/*
** my_put_square.c for wireframe in /home/benito/delivery/wireframe
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.net>
** 
** Started on  Tue Nov 15 15:00:20 2016 Benoit Lormeau
** Last update Tue Nov 15 15:00:45 2016 Benoit Lormeau
*/

#include "my_sfml.h"

void	my_put_square(t_my_framebuffer *fb, sfVector2f coords, sfVector2f size, sfColor color)
{
  int	i;
  int	j;

  j = 0;
  while (j < size.y)
    {
      i = 0;
      while (i < size.x)
	{
	  my_put_pixel(fb, coords.x + i, coords.y + j, color);
	  i++;
	}
      j++;
    }
}