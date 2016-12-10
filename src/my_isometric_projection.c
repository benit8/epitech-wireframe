/*
** my_isometric_projection.c for wireframe in /home/benito/delivery/wireframe
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.net>
** 
** Started on  Tue Nov 22 11:17:52 2016 Benoit Lormeau
** Last update Tue Nov 22 11:17:54 2016 Benoit Lormeau
*/

#include "my_sfml.h"

sfVector2f	my_isometric_projection(sfVector3f p)
{
  sfVector2f	res;
  int		xoff;
  int		yoff;

  xoff = 0;
  yoff = 0;
  res.x = (p.x / 2 + xoff) - (p.y / 2);
  res.y = (-p.z / 4 + yoff) + (p.y / 4) + (p.x / 4);
  return (res);
}