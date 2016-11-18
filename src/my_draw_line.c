/*
** dda.c for bswireframe in /home/benito/delivery/CGP_2016_wireframe_bootstrap
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.net>
** 
** Started on  Tue Nov 15 09:24:02 2016 Benoit Lormeau
** Last update Tue Nov 15 10:04:30 2016 Benoit Lormeau
*/

#include <stdio.h>
#include <math.h>
#include "my_sfml.h"

void	my_draw_line(t_my_framebuffer *fb, sfVector2f from, sfVector2f to, sfColor color)
{
  float	x;
  float	y;
  float	dx;
  float	dy;
  float	ix;
  float	iy;
  int	i;
  int	steps;

  i = -1;
  x = from.x;
  y = from.y;
  dx = to.x - from.x;
  dy = to.y - from.y;
  steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
  ix = dx / (float) steps;
  iy = dy / (float) steps;
  while (++i < steps)
    {
      my_put_pixel(fb, round(x), round(y), color);
      x += ix;
      y += iy;
    }
}

void    my_draw_line_3d(t_my_framebuffer *fb, sfVector3f a, sfVector3f b, sfColor color)
{
  sfVector2f  a2;
  sfVector2f  b2;

  a2 = my_convert_point(a, 225, 200);
  b2 = my_convert_point(b, 225, 200);
  my_draw_line(fb, a2, b2, color);
}