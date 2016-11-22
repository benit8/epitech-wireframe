/*
** my_draw_grid.c for wireframe in /home/benito/delivery/wireframe
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.net>
** 
** Started on  Tue Nov 15 15:00:20 2016 Benoit Lormeau
** Last update Tue Nov 15 15:00:45 2016 Benoit Lormeau
*/

#include "my_sfml.h"

void		my_draw_grid(t_my_framebuffer *fb, int width, int height)
{
  int		i;
  sfVector3f	a;
  sfVector3f	b;
  sfVector3f	**grid;
  sfColor	color;

  color = sfColor_fromRGBA(128, 128, 128, 255);
  i = -1;
  while (++i < height)
    {
      a = sfVector_from3f(0, i, 0);
      b = sfVector_from3f(width - 1, i, 0);
      my_draw_line_3d(fb, a, b, color);
    }
  i = -1;
  while (++i < width)
    {
      a = sfVector_from3f(i, 0, 0);
      b = sfVector_from3f(i, height - 1, 0);
      my_draw_line_3d(fb, a, b, color);
    }
}