/*
** my_draw_line.c for bswireframe in /home/benito/delivery/CGP_2016_wireframe_bootstrap
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.net>
** 
** Started on  Tue Nov 15 09:24:02 2016 Benoit Lormeau
** Last update Fri Nov 18 17:07:28 2016 Benoit Lormeau
*/

#include <math.h>
#include "my_sfml.h"

float	alpha_;
float	omega_;

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

void		my_draw_line_3d(t_my_framebuffer *fb, sfVector3f a, sfVector3f b, sfColor color)
{
  sfVector2f	a2;
  sfVector2f	b2;
  int		cond = 2;

  if (cond == 1)
    {
      a2 = my_parallel_projection(a, 30);
      b2 = my_parallel_projection(b, 30);
    }
  else if (cond == 2)
    {
      a2 = my_orthogonal_projection(a, omega_, alpha_);
      b2 = my_orthogonal_projection(b, omega_, alpha_);
    }
  else
    {
      a2 = my_isometric_projection(a);
      b2 = my_isometric_projection(b);
    }
  my_draw_line(fb, a2, b2, color);
}
