/*
** my_sfml.h for CPG_bootstrap in /home/benito/delivery/PSU_2016_CGP_bootstrap
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.net>
** 
** Started on  Wed Nov  9 13:52:13 2016 Benoit Lormeau
** Last update Fri Nov 25 13:49:52 2016 Benoit Lormeau
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>

#define 		WIDTH	1920
#define 		HEIGHT	1030

#define			MAP_W	200
#define			MAP_H	200

#define	 ipart_(X)	((int)(X))
#define	 round_(X)	((int)(((double)(X)) + 0.5))
#define	 fpart_(X)	(((double)(X)) - (double) ipart_(X))
#define	rfpart_(X)	(1.0 - fpart_(X))


typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_map
{
  sfVector3f		*tab;
  int			width;
  int			height;
}			t_map;

typedef struct		s_init
{
  sfVideoMode 		mode;
  sfRenderWindow	*rWindow;
  sfWindow		*window;
  sfSprite 		*sprite;
  sfTexture 		*texture;
  t_my_framebuffer 	*framebuffer;
  sfVertexArray		*vertices;
  sfVertexArray		**vertexTab;
  sfRenderStates	*states;
}			t_init;


int			my_atoi(char *str);
int			my_nbrlen(int nb);
float			my_map(float n, float start1, float stop1, float start2, float stop2);
void			my_swap(double *a, double *b);

sfVector2f		sfVector_from2f(float x, float y);
sfVector3f		sfVector_from3f(float x, float y, float z);

t_my_framebuffer	*my_framebuffer_create(int width, int height);
void			clear_framebuffer(t_my_framebuffer *fb);

sfVertexArray		*get_vertexArray(sfVertexArray *vertices, char *path);
sfVertexArray		*get_vertexArray_line(sfVertexArray *vertices, unsigned int start);

sfColor			my_color_add(sfColor color1, sfColor color2);
void			my_put_pixel(t_my_framebuffer *fb, int x, int y, sfColor color);

sfVector2f		my_orthogonal_projection(sfVector3f pos3d, float omega, float alpha);
sfVector2f		my_parallel_projection(sfVector3f pos3d, float angle);
sfVector2f		my_isometric_projection(sfVector3f pos3d);

void			my_draw_line(t_my_framebuffer *fb, sfVector2f from, sfVector2f to, sfColor color);
void			my_draw_line_aa(t_my_framebuffer *fb, sfVector2f from, sfVector2f to, sfColor color);
void			my_draw_line_3d(t_my_framebuffer *fb, sfVector3f a, sfVector3f b, sfColor color);
void			my_put_square(t_my_framebuffer *fb, sfVector2f coords, sfVector2f size, sfColor color);
void			my_draw_grid(t_my_framebuffer *fb, int width, int height);
void			my_draw_heights(t_my_framebuffer *fb, t_map map);
void			my_join_points(t_my_framebuffer *fb, t_map map);


extern int		orig_x;
extern int		orig_y;

extern float		alpha_;
extern float		omega_;
extern float		factor_;

#endif