/*
** my_swap.c for wireframe in /home/benito/delivery/wireframe/bonus
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.net>
** 
** Started on  Sat Nov 26 00:20:25 2016 Benoit Lormeau
** Last update Sat Nov 26 00:22:29 2016 Benoit Lormeau
*/

void		my_swap(double *a, double *b)
{
  double	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}
