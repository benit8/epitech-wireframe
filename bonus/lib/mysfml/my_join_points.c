/*
** my_join_points.c for wireframe in /home/benito/delivery/wireframe
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.net>
** 
** Started on  Tue Nov 15 18:25:24 2016 Benoit Lormeau
** Last update Tue Nov 15 18:26:20 2016 Benoit Lormeau
*/

#include "my_sfml.h"

void	my_join_points(t_my_framebuffer *framebuffer, t_map map)
{
  int	i;
  int	j;
  int	w;
  int	h;

  w = map.width;
  h = map.height;
  i = 0;
  while (i < (w * h))
    {
      if ((i % w != w - 1) || i == 0)
        my_draw_line_3d(framebuffer, map.tab[i], map.tab[i + 1], sfBlack);
      if (i < (w * h) - w)
        my_draw_line_3d(framebuffer, map.tab[i], map.tab[i + w], sfBlack);
      if (((i % w != w - 1) || i == 0) && (i < (w * h) - w))
        my_draw_line_3d(framebuffer, map.tab[i], map.tab[i + w + 1], sfBlack);
      i++;
    }
}