/*
** my_map.c for Repo igniter in /home/benito/delivery/wireframe/bonus
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.net>
** 
** Started on  Fri Nov 25 13:48:46 2016 Benoit Lormeau
** Last update Fri Nov 25 13:49:13 2016 Benoit Lormeau
*/

float	my_map(float n, float start1, float stop1, float start2, float stop2)
{
  return ((n - start1) / (stop1 - start1)) * (stop2 - start2) + start2;
}