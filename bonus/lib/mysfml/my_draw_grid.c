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
  sfColor	color;
  sfVector3f	**grid;
  sfVector3f	a;
  sfVector3f	b;
  int		i;
  int		f;

  color = sfColor_fromRGBA(128, 128, 128, 255);
  i = -1;
  f = 75;
  while (++i < height)
    {
      a = sfVector_from3f(0,               i * f, 0);
      b = sfVector_from3f((width - 1) * f, i * f, 0);
      my_draw_line_3d(fb, a, b, color);
    }
  i = -1;
  while (++i < width)
    {
      a = sfVector_from3f(i * f, 0,                0);
      b = sfVector_from3f(i * f, (height - 1) * f, 0);
      my_draw_line_3d(fb, a, b, color);
    }
}

void		my_draw_heights(t_my_framebuffer *framebuffer, t_map map)
{
  sfVector3f		l;
  sfColor		color;
  int			i;

  color = sfColor_fromRGBA(90, 90, 90, 255);
  i = -1;
  while (++i < (map.width * map.height))
    {
      l = sfVector_from3f(map.tab[i].x, map.tab[i].y, 0);
      my_draw_line_3d(framebuffer, l, map.tab[i], color);
    }
}