
#ifndef T_COORDINATE_H
# define T_COORDINATE_H

typedef struct	s_fcoor
{
	float	x;
	float	y;
}				t_fcoor;

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

#endif
