#include "refresh_game.h"
#include <stdio.h>
#include <math.h>

t_coor chat_raycasting(mlx_image_t *image, t_coor start_pos, t_coor end_pos, t_map map)
{
    // Dirección del rayo (no normalizamos)
    t_coor rayDir = { end_pos.x - start_pos.x, end_pos.y - start_pos.y };

    // salida rápida si no hay dirección
    if (fabsf(rayDir.x) < 1e-9f && fabsf(rayDir.y) < 1e-9f)
        return start_pos;

    int mapX = (int)floorf(start_pos.x);
    int mapY = (int)floorf(start_pos.y);

    // evitar divisiones por cero posteriores (conservando signo)
    if (fabsf(rayDir.x) < 1e-9f) rayDir.x = (rayDir.x < 0.0f) ? -1e-9f : 1e-9f;
    if (fabsf(rayDir.y) < 1e-9f) rayDir.y = (rayDir.y < 0.0f) ? -1e-9f : 1e-9f;

    // deltaDist: distancia (a lo largo del rayo) para cruzar una celda en X / Y
    float deltaDistX = sqrtf(1.0f + (rayDir.y * rayDir.y) / (rayDir.x * rayDir.x));
    float deltaDistY = sqrtf(1.0f + (rayDir.x * rayDir.x) / (rayDir.y * rayDir.y));

    int stepX, stepY;
    float sideDistX, sideDistY;

    if (rayDir.x < 0.0f) {
        stepX = -1;
        sideDistX = (start_pos.x - (float)mapX) * deltaDistX;
    } else {
        stepX = 1;
        sideDistX = ((float)(mapX + 1) - start_pos.x) * deltaDistX;
    }

    if (rayDir.y < 0.0f) {
        stepY = -1;
        sideDistY = (start_pos.y - (float)mapY) * deltaDistY;
    } else {
        stepY = 1;
        sideDistY = ((float)(mapY + 1) - start_pos.y) * deltaDistY;
    }

    int hit = 0;
    int side = -1; // 0 => se movió en X (vertical wall), 1 => en Y (horizontal wall)

    // DDA loop
    while (!hit) {
        if (sideDistX < sideDistY) {
            sideDistX += deltaDistX;
            mapX += stepX;
            side = 0;
        } else {
            sideDistY += deltaDistY;
            mapY += stepY;
            side = 1;
        }

        // Si tu t_map tiene dimensiones definidas, descomenta y ajusta los nombres.
        // Evita indexación fuera de rango.
        // if (mapX < 0 || mapY < 0 || mapX >= map.width || mapY >= map.height) break;

        // Comprueba la celda - asumo que '1' es pared
        if (map.array[mapY][mapX] == '1') hit = 1;
    }

    float perpWallDist;
    if (hit) {
        // Fórmula segura y clásica (Lode): distancia “a lo largo del rayo” hasta la pared
        if (side == 0)
            perpWallDist = (mapX - start_pos.x + (1 - stepX) / 2.0f) / rayDir.x;
        else
            perpWallDist = (mapY - start_pos.y + (1 - stepY) / 2.0f) / rayDir.y;

        // Punto de impacto en coordenadas del mundo
        end_pos.x = start_pos.x + rayDir.x * perpWallDist;
        end_pos.y = start_pos.y + rayDir.y * perpWallDist;
    } else {
        // Si por alguna razón no hubo hit (salida por límite), usamos el último sideDist
        float fallbackDist = fminf(sideDistX, sideDistY);
        end_pos.x = start_pos.x + rayDir.x * fallbackDist;
        end_pos.y = start_pos.y + rayDir.y * fallbackDist;
    }

    // Dibuja rayo collision (rojo) y objetivo original (verde opcional)
    // Si quieres ver sólo colisión deja sólo el rojo.
    bresenham_algorithm(image, start_pos, end_pos, color(255, 0, 0, 255));

    // debug opcional
    // printf("Hit at map (%d,%d) side=%d perpDist=%f\n", mapX, mapY, side, perpWallDist);

    return end_pos;
}
