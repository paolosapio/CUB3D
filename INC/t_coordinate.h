
#ifndef T_COORDINATE_H
# define T_COORDINATE_H

typedef struct	s_coor
{
	float x;
	float y;
}				t_coor;

typedef  t_coor t_vector;

typedef struct	s_segment
{
	t_coor	start;
	t_coor	end;
}				t_segment;

typedef struct	s_int_coor
{
	int	x;
	int	y;
}				t_int_coor;

#endif
