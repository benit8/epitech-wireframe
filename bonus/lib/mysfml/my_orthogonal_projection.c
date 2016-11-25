/*
** my_orthogonal_projection.c for wireframe in /home/benito/delivery/wireframe
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.net>
** 
** Started on  Thu Nov 24 23:41:57 2016 Benoit Lormeau
** Last update Thu Nov 24 23:45:50 2016 Benoit Lormeau
*/

#include <math.h>
#include "my_sfml.h"

int	orig_x;
int	orig_y;
float	factor_;

sfVector2f	my_orthogonal_projection(sfVector3f p, float omega, float alpha)
{
  sfVector2f	res;
  float		a1 = cos(omega);
  float		a2 = sin(omega);
  float		b1 = cos(alpha);
  float		b2 = sin(alpha);

  res.x = orig_x + factor_ * (a1 * p.x + a2 * p.y);
  res.y = orig_y + factor_ * (b2 * (a2 * p.x - a1 * p.y) + b1 * p.z);
  return (res);
}