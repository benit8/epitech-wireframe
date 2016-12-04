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

void		my_draw_line(t_my_framebuffer *fb, sfVector2f from, sfVector2f to, sfColor color)
{
  double	x;
  double	y;
  double	dx;
  double	dy;
  double	ix;
  double	iy;
  int	i;
  int	steps;

  i = -1;
  x = from.x;
  y = from.y;
  dx = to.x - from.x;
  dy = to.y - from.y;
  steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
  ix = dx / (double) steps;
  iy = dy / (double) steps;
  while (++i < steps)
    {
      my_put_pixel(fb, round(x), round(y), color);
      x += ix;
      y += iy;
    }
}

void		my_draw_line_aa(t_my_framebuffer *fb, sfVector2f from, sfVector2f to, sfColor color)
{
  double	x1, y1;
  double	x2, y2;
  double	dx, dy;
  double	xend, yend;
  double	xgap, ygap;
  double	interx, intery;
  double	gradient;
  int		xpxl1, ypxl1;
  int		xpxl2, ypxl2;
  int		x, y;

  x1 = from.x;
  y1 = from.y;
  x2 = to.x;
  y2 = to.y;
  dx = (double) x2 - (double) x1;
  dy = (double) y2 - (double) y1;
  if (fabs(dx) > fabs(dy)){
    if (x2 < x1){
      my_swap(&x1, &x2);
      my_swap(&y1, &y2);
    }
    gradient = dy / dx;
    xend = round_(x1);
    yend = y1 + gradient * (xend - x1);
    xgap = rfpart_(x1 + 0.5);
    xpxl1 = xend;
    ypxl1 = ipart_(yend);
    my_put_pixel(fb, xpxl1, ypxl1,     (sfColor){color.r, color.g, color.b, my_map(rfpart_(yend) * xgap, 0, 1, 0, color.a)});
    my_put_pixel(fb, xpxl1, ypxl1 + 1, (sfColor){color.r, color.g, color.b, my_map(fpart_(yend) * xgap, 0, 1, 0, color.a)});
    intery = yend + gradient;

    xend = round_(x2);
    yend = y2 + gradient * (xend - x2);
    xgap = fpart_(x2 + 0.5);
    xpxl2 = xend;
    ypxl2 = ipart_(yend);
    my_put_pixel(fb, xpxl2, ypxl2,     (sfColor){color.r, color.g, color.b, my_map(rfpart_(yend) * xgap, 0, 1, 0, color.a)});
    my_put_pixel(fb, xpxl2, ypxl2 + 1, (sfColor){color.r, color.g, color.b, my_map(fpart_(yend) * xgap, 0, 1, 0, color.a)});

    x = xpxl1 + 1;
    while (x <= xpxl2 - 1){
      my_put_pixel(fb, x, ipart_(intery),     (sfColor){color.r, color.g, color.b, my_map(rfpart_(intery), 0, 1, 0, color.a)});
      my_put_pixel(fb, x, ipart_(intery) + 1, (sfColor){color.r, color.g, color.b, my_map(fpart_(intery), 0, 1, 0, color.a)});
      intery += gradient;
      x++;
    }
  } else {
    if (y2 < y1){
      my_swap(&x1, &x2);
      my_swap(&y1, &y2);
    }
    gradient = dx / dy;
    yend = round_(y1);
    xend = x1 + gradient * (yend - y1);
    ygap = rfpart_(y1 + 0.5);
    ypxl1 = yend;
    xpxl1 = ipart_(xend);
    my_put_pixel(fb, xpxl1, ypxl1,     (sfColor){color.r, color.g, color.b, my_map(rfpart_(xend) * ygap, 0, 1, 0, color.a)});
    my_put_pixel(fb, xpxl1, ypxl1 + 1, (sfColor){color.r, color.g, color.b, my_map(fpart_(xend) * ygap, 0, 1, 0, color.a)});
    interx = xend + gradient;

    yend = round_(y2);
    xend = x2 + gradient * (yend - y2);
    ygap = fpart_(y2 + 0.5);
    ypxl2 = yend;
    xpxl2 = ipart_(xend);
    my_put_pixel(fb, xpxl2, ypxl2,     (sfColor){color.r, color.g, color.b, my_map(rfpart_(xend) * ygap, 0, 1, 0, color.a)});
    my_put_pixel(fb, xpxl2, ypxl2 + 1, (sfColor){color.r, color.g, color.b, my_map(fpart_(xend) * ygap, 0, 1, 0, color.a)});

    y = ypxl1 + 1;
    while (y <= ypxl2 - 1){
      my_put_pixel(fb, ipart_(interx),     y, (sfColor){color.r, color.g, color.b, my_map(rfpart_(interx), 0, 1, 0, color.a)});
      my_put_pixel(fb, ipart_(interx) + 1, y, (sfColor){color.r, color.g, color.b, my_map(fpart_(interx), 0, 1, 0, color.a)});
      interx += gradient;
      y++;
    }
  }
}

void		my_draw_line_3d(t_my_framebuffer *fb, sfVector3f a3, sfVector3f b3, sfColor color)
{
  sfVector2f	a2;
  sfVector2f	b2;
  float		h;

  h = (a3.z + b3.z) / 2;
  if (h > 5.5)
    color = sfColor_fromRGB(80, 80, 80);
  else if (h > 1.7)
    color = sfColor_fromRGB(88, 41, 0);
  else if (h > 0.2)
    color = sfGreen;
  else
    color = sfBlue;

  // color.a = my_map(h, 0, 10, 0, 255);

  a3.x -= 25;
  a3.y -= 25;

  b3.x -= 25;
  b3.y -= 25;

  a2 = my_orthogonal_projection(a3, omega_, alpha_);
  b2 = my_orthogonal_projection(b3, omega_, alpha_);
  // my_draw_line(fb, a2, b2, color);
  my_draw_line_aa(fb, a2, b2, color);
  // my_draw_line_aa(fb, a2, b2, (sfColor){color.r, color.g, color.b, my_map((a3.z + b3.z) / 2, 0, 8, 70, 255)});
}