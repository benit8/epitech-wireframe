/*
** my_parallel_projection.c for wireframe in /home/benito/delivery/wireframe
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.net>
** 
** Started on  Tue Nov 22 11:17:52 2016 Benoit Lormeau
** Last update Tue Nov 22 11:17:54 2016 Benoit Lormeau
*/

#include <math.h>
#include "my_sfml.h"

float		hFactor;
float		xRotate;
float		yRotate;
float		zRotate;

sfVector2f	my_parallel_projection(sfVector3f p, float angle)
{
  sfVector2f	res;
  float		k1;
  float		k2;
  float		k3;
  int		xoff;
  int		yoff;

  xoff = 450;
  yoff = 400;
  k1 = 1;
  k2 = cos(angle * 3.14159265 / 180.0);
  k3 = 1;
  res.x = (p.x * k1 + xoff) - (p.y * (k2 / 2));
  res.y = (-p.z * (k3 / hFactor) + yoff) + (p.y * (k2 / yRotate));
  return (res);
}
