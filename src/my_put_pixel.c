/*
** my_put_pixel.c for wireframe in /home/benito/delivery/wireframe
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.net>
** 
** Started on  Tue Nov 15 15:00:20 2016 Benoit Lormeau
** Last update Tue Nov 15 15:00:45 2016 Benoit Lormeau
*/

#include "my_sfml.h"

sfColor		my_color_add(sfColor color1, sfColor color2)
{
  sfColor	new;
  float		alpha;
  float		r;
  float		g;
  float		b;

  alpha = (float) color1.a / 255;
  r = alpha * color1.r + (1 - alpha) * color2.r;
  g = alpha * color1.g + (1 - alpha) * color2.g;
  b = alpha * color1.b + (1 - alpha) * color2.b;
  new = sfColor_fromRGBA(r, g, b, color1.a);
  return (new);
}

void	my_put_pixel(t_my_framebuffer *fb, int x, int y, sfColor color)
{
  int		w;
  sfColor	current;
  sfColor	new;

  w = fb->width;
  current = sfColor_fromRGBA(fb->pixels[(w * y + x) * 4 + 0],
			     fb->pixels[(w * y + x) * 4 + 1],
			     fb->pixels[(w * y + x) * 4 + 2],
			     fb->pixels[(w * y + x) * 4 + 3]);
  new = my_color_add(color, current);
  fb->pixels[(w * y + x) * 4 + 0] = new.r;
  fb->pixels[(w * y + x) * 4 + 1] = new.g;
  fb->pixels[(w * y + x) * 4 + 2] = new.b;
  fb->pixels[(w * y + x) * 4 + 3] = new.a;
}