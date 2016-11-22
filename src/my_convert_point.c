/*
** my_convert_point for CPG_bootstrap in /home/benito/delivery/PSU_2016_CGP_bootstrap
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.net>
** 
** Started on  Wed Nov  9 13:52:13 2016 Benoit Lormeau
** Last update Tue Nov 15 15:46:11 2016 Benoit Lormeau
*/

#include "my_sfml.h"

sfVector2f	sfVector_from2f(float x, float y)
{
  sfVector2f	res;

  res.x = x;
  res.y = y;
  return (res);
}

sfVector3f	sfVector_from3f(float x, float y, float z)
{
  sfVector3f	res;

  res.x = x;
  res.y = y;
  res.z = z;
  return (res);
}