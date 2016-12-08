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
  int		idx;
  sfColor	current;
  sfColor	new;

  idx = (fb->width * y + x) * 4;
  if (idx >= 0 && idx < (fb->width * fb->height * 4 - 4) &&
      ((y >= 0 && y < fb->height) && (x >= 0 && x < fb->width)))
    {
      current = sfColor_fromRGBA(fb->pixels[idx + 0],
				 fb->pixels[idx + 1],
				 fb->pixels[idx + 2],
			 	 fb->pixels[idx + 3]);
      new = my_color_add(color, current);
      fb->pixels[idx + 0] = new.r;
      fb->pixels[idx + 1] = new.g;
      fb->pixels[idx + 2] = new.b;
      fb->pixels[idx + 3] = new.a;
    }
}