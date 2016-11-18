/*
** my_getnbr.c for CPool_Day07 in /home/benoit.lormeau/delivery/CPool_Day07/lib/my/
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 11 14:00:50 2016 Benoit Lormeau
** Last update Mon Oct 31 10:34:55 2016 Benoit Lormeau
*/

int	my_nbrlen(int x)
{
  if (x >= 1000000000 || x <= -100000000)
    return (10);
  if (x >= 100000000 || x <= -10000000)
    return (9);
  if (x >= 10000000 || x <= -1000000)
    return (8);
  if (x >= 1000000 || x <= -100000)
    return (7);
  if (x >= 100000 || x <= -10000)
    return (6);
  if (x >= 10000 || x <= -1000)
    return (5);
  if (x >= 1000 || x <= -100)
    return (4);
  if (x >= 100 || x <= -10)
    return (3);
  if (x >= 10 || x <= -1)
    return (2);
  return (1);
}