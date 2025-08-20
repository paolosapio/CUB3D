#include "../MOVEMENTS/movements.h"
#include "collisions.h"

#define 	ACTIVATED '1'

float	degrees_to_radius(float degrees)
{
	return ((degrees / 180) * M_PI);
}

#define ANTENNA_OFFSET 2

// bool	antennas_north(t_player player, t_map map)
// {
// 	t_antenna north_left;


// 	north_left.x = player.pos.x * (map.size_of_tile / 2);
// 	north_left.y = player.pos.y * (map.size_of_tile / 2);

// 	north_left.x -= cos(degrees_to_radius(player.vision_angle) / 10) * player.speed;
// 	north_left.y -= sin(((player.vision_angle / 180) * M_PI) / 10) * player.speed;
// 	if (map.array[(int)north_left.y / 30][(int)north_left.x / 30] == ACTIVATED)
// 		return (false);
// 	return (true);
// }

bool	antennas_north(t_player player, t_map map)
{
	t_antenna north_left;
	float	coseno;
	float	seno;

	north_left.x = (player.pos.x * map.size_of_tile) + (map.size_of_tile / 2);
	north_left.y = (player.pos.y * map.size_of_tile) + (map.size_of_tile / 2);

	coseno = cos(degrees_to_radius(player.vision_angle)) * player.speed;
	if (coseno != 0)
		north_left.x -= coseno + 7;

	seno = sin((player.vision_angle / 180) * M_PI) * player.speed;
	if (seno != 0)
		north_left.y -= seno + 7;

	printf("\n-----------------------------------------\n");
	printf("Posicion jugador (centro) y = %f x = %f\n", 
		((player.pos.y * map.size_of_tile) + (map.size_of_tile / 2)) / map.size_of_tile,
		((player.pos.x * map.size_of_tile) + (map.size_of_tile / 2)) / map.size_of_tile);
	printf("casilla (float)           y = %f x = %f\n", north_left.y / 30, north_left.x / 30);
	printf("casilla (int)             y = %d x = %d\n", (int)north_left.y / 30, (int)north_left.x / 30);
	if (map.array[(int)north_left.y / 30][(int)north_left.x / 30] == ACTIVATED)
	{
		printf("ANTENA ACTIVADAAAA\n");
		return (false);
	}

	return (true);
}

bool	antennas_right(t_player player, t_map map)
{
	t_antenna north_left;
	t_antenna north_rigth;


	north_left.x = player.pos.x * (map.size_of_tile / 2);
	north_left.y = player.pos.y * (map.size_of_tile / 2);

	north_left.x += cos(degrees_to_radius(player.vision_angle - 90)) * player.speed;
	north_left.y += sin(((player.vision_angle - 90)/ 180) * M_PI) * player.speed;
	if (map.array[(int)north_left.y / 30][(int)north_left.x / 30] == ACTIVATED)
		return (false);

	north_rigth.x = (player.pos.x * 30)+ (map.size_of_tile - ANTENNA_OFFSET);
	north_rigth.y = ANTENNA_OFFSET + player.pos.y * 30;

	// printf("NRY: %f\n", north_rigth.y);
	// printf("NRX: %f\n", north_rigth.x);
	// if (map.array[(int)north_rigth.y / 30][(int)north_rigth.x / 30] == ACTIVATED)
	// 	return (false);
	return (true);
}

bool	antennas_left(t_player player, t_map map)
{
	t_antenna north_left;
	t_antenna north_rigth;


	north_left.x = player.pos.x * (map.size_of_tile / 2);
	north_left.y = player.pos.y * (map.size_of_tile / 2);

	north_left.x -= cos(degrees_to_radius(player.vision_angle - 90)) * player.speed;
	north_left.y -= sin(((player.vision_angle - 90)/ 180) * M_PI) * player.speed;
	if (map.array[(int)north_left.y / 30][(int)north_left.x / 30] == ACTIVATED)
		return (false);

	north_rigth.x = (player.pos.x * 30)+ (map.size_of_tile - ANTENNA_OFFSET);
	north_rigth.y = ANTENNA_OFFSET + player.pos.y * 30;

	// printf("NRY: %f\n", north_rigth.y);
	// printf("NRX: %f\n", north_rigth.x);
	// if (map.array[(int)north_rigth.y / 30][(int)north_rigth.x / 30] == ACTIVATED)
	// 	return (false);
	return (true);
}


// // #include "../MOVEMENTS/movements.h"

// #define 	ACTIVATED '1'
// #define 	NORTH_RIGHT_ANTENNA map.array[y + 1][x + 1]
// #define 	NORTH_LEFT_ANTENNA map.array[y + 1][x - 1]

// #define 	SOUTH_RIGHT_ANTENNA map.array[y - 1][x + 1]
// #define 	SOUTH_LEFT_ANTENNA map.array[y - 1][x - 1]

// float	degrees_to_radius(float degrees)
// {
// 	return ((degrees / 180) * M_PI);
// }

// bool	antennas_north(t_player player, t_map map)
// {
// 	int	x;
// 	int	y;

// 	x = player.pos.x;
// 	y = player.pos.y;
// 	x -= cos(degrees_to_radius(player.vision_angle)) * player.speed;
// 	y -= (sin((player.vision_angle / 180) * M_PI) / 10) * player.speed;

// 	if (NORTH_RIGHT_ANTENNA == ACTIVATED)
// 		return (false);
// 	if (NORTH_LEFT_ANTENNA == ACTIVATED)
// 		return (false);
// 	return (true);
// }

// bool	antennas_south(t_player player, t_map map)
// {
// 	int	x;
// 	int y;

// 	x = player.pos.x;
// 	y = player.pos.y;
// 	x -= (cos((player.vision_angle / 180) * M_PI) / 10) * player.speed;
// 	y -= (sin((player.vision_angle / 180) * M_PI) / 10) * player.speed;

// 	if (SOUTH_RIGHT_ANTENNA == ACTIVATED)
// 		return (false);
// 	if (SOUTH_LEFT_ANTENNA == ACTIVATED)
// 		return (false);
// 	return (true);
// }
