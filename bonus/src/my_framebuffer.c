/*
** my_framebuffer.c for CGP_bootstrap in /home/benito/delivery/PSU_2016_CGP_bootstrap
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.net>
** 
** Started on  Wed Nov  9 13:58:07 2016 Benoit Lormeau
** Last update Tue Nov 15 09:50:06 2016 Benoit Lormeau
*/

#include "my_sfml.h"

t_my_framebuffer	*my_framebuffer_create(int width, int height)
{
  t_my_framebuffer	*fb;

  if ((fb = malloc(sizeof(t_my_framebuffer))) == NULL)
    exit(EXIT_FAILURE);
  fb->pixels = malloc(4 * width * height);
  fb->width = width;
  fb->height = height;
  return (fb);
}

void	empty_framebuffer(t_my_framebuffer *fb)
{
  int	i;

  i = -1;
  while (++i < (4 * fb->width * fb->height))
    fb->pixels[i] = 0;
}