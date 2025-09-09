#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAP_WIDTH 8
#define MAP_HEIGHT 8

// mapa simple (1 = pared, 0 = vacío)
int worldMap[MAP_HEIGHT][MAP_WIDTH] = {
    {1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,0,1},
    {1,0,1,0,1,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1}
};

typedef struct {
    double x, y;     // posición del jugador
    double dirX, dirY; // dirección de vista
    double planeX, planeY; // plano de cámara (FOV)
} Player;

int main() {
    Player p = {3.5, 3.5, -1.0, 0.0, 0.0, 0.66}; // posición inicial

    int screenWidth = 40; // ancho "ficticio" de pantalla
    int screenHeight = 20;

    for (int x = 0; x < screenWidth; x++) {
        // cálculo del rayo
        double cameraX = 2 * x / (double)screenWidth - 1; // entre -1 y 1
        double rayDirX = p.dirX + p.planeX * cameraX;
        double rayDirY = p.dirY + p.planeY * cameraX;

        int mapX = (int)p.x;
        int mapY = (int)p.y;

        // distancia del rayo desde la posición actual hasta la siguiente x o y
        double sideDistX;
        double sideDistY;

        // longitud del rayo desde una x o y hasta la siguiente
        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
        double perpWallDist;

        int stepX;
        int stepY;
        int hit = 0; // ¿se ha golpeado una pared?
        int side;    // ¿fue en X o en Y?

        // cálculo de step y sideDist inicial
        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (p.x - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - p.x) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (p.y - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - p.y) * deltaDistY;
        }

        // algoritmo DDA
        while (hit == 0) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            // ¿hay un muro?
            if (worldMap[mapY][mapX] > 0) hit = 1;
        }

        // calcular distancia perpendicular al muro
        if (side == 0)
            perpWallDist = (mapX - p.x + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - p.y + (1 - stepY) / 2) / rayDirY;

        int lineHeight = (int)(screenHeight / perpWallDist);

        printf("Ray %d: hit wall at (%d, %d), dist = %f, lineHeight = %d\n",
               x, mapX, mapY, perpWallDist, lineHeight);
    }

    return 0;
}
