/*
** my_sfml.h for CPG_bootstrap in /home/benito/delivery/PSU_2016_CGP_bootstrap
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.net>
** 
** Started on  Wed Nov  9 13:52:13 2016 Benoit Lormeau
** Last update Tue Nov 15 09:48:27 2016 Benoit Lormeau
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct	s_map
{
  sfVector3f	*tab;
  int		width;
  int		height;
}		t_map;

typedef struct		s_init
{
  sfVideoMode 		mode;
  sfRenderWindow	*window;
  sfSprite 		*sprite;
  sfTexture 		*texture;
  t_my_framebuffer 	*framebuffer;
}			t_init;

int			my_atoi(char *str);
int			my_nbrlen(int nb);
sfVector2f		sfVector_from2f(float x, float y);
sfVector3f		sfVector_from3f(float x, float y, float z);
t_my_framebuffer	*my_framebuffer_create(int width, int height);
sfColor			my_color_add(sfColor color1, sfColor color2);
void			my_put_pixel(t_my_framebuffer *fb,
				     int x,
				     int y,
				     sfColor color);
void			my_put_square(t_my_framebuffer *fb,
				      sfVector2f coords,
				      sfVector2f size,
				      sfColor color);
void			my_draw_line(t_my_framebuffer *fb,
				     sfVector2f from,
				     sfVector2f to,
				     sfColor color);
sfVector2f		my_parallel_projection(sfVector3f pos3d,
					       float angle);
sfVector2f		my_isometric_projection(sfVector3f pos3d);
void			my_draw_line_3d(t_my_framebuffer *fb,
					sfVector3f a,
					sfVector3f b,
					sfColor color);
void			my_draw_grid(t_my_framebuffer *fb,
				     int width,
				     int height);
void			my_join_points(t_my_framebuffer *fb, t_map map);

#endif
