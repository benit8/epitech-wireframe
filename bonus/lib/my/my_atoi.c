/*
** my_atoi.c for CPool_libmy in /home/benoit.lormeau/delivery/CPool_evalexpr/lib/my/
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
** 
** Started on  Thu Oct 27 15:00:53 2016 Benoit Lormeau
** Last update Fri Nov  4 14:31:39 2016 Benoit Lormeau
*/

int	is_numeric(char c)
{
  return (c >= '0' && c <= '9');
}

int	my_atoi(char *str)
{
  int		i;
  int		neg;
  unsigned int	res;

  i = 0;
  neg = 1;
  res = 0;
  while (str[i] == '-' || str[i] == '+' || str[i] == ' ')
    {
      if (str[i] == '-')
	neg = -neg;
      i++;
    }
  while (is_numeric(str[i]))
    {
      res = res * 10 + (str[i] - 48);
      i++;
    }
  if (neg == -1)
    res *= -1;
  return (res);
}
