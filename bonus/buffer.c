/*
** buffer.c for wireframe in /home/benito/delivery/wireframe
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.net>
** 
** Started on  Tue Nov 15 19:25:55 2016 Benoit Lormeau
** Last update Tue Nov 15 19:27:15 2016 Benoit Lormeau
*/

#include "buffer.h"
#include "perlin.h"

char	*read_file(char *path, char *buffer)
{
  int	fd;
  int	bytes;

  fd = open(path, O_RDONLY);
  if (fd < 3)
    return (NULL);
  bytes = read(fd, buffer, 1024);
  buffer[bytes] = '\0';
  close(fd);
  return (buffer);
}

t_map	fill_map(char *buffer, t_map map)
{
  int	i;
  int	x;
  int	y;
  static int inc;

  i = 0;
  x = 0;
  y = 0;
  while (*buffer != '\0')
    {
      if (*buffer == '\n')
	{
	  y++;
	  x = 0;
	  buffer++;
	}
      map.tab[i] = sfVector_from3f(x, y, (float) my_atoi(buffer) + (perlin2d(x, y + inc, 0.1, 6) * 6));
      buffer += my_nbrlen(map.tab[i].z) + 1;
      i++;
      x++;
    }
  inc++;
  return (map);
}

t_map	parse_buffer(char *path)
{
  int	i;
  int	w;
  int	h;
  char	*buffer;
  t_map	map;

  w = -1;
  h = 0;
  i = 0;
  if ((buffer = malloc(sizeof(char) * (1025))) == NULL)
    return (map);
  read_file(path, buffer);
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n')
        {
          h++;
          w = (w == -1) ? (i / 2) : w;
        }
      i++;
    }
  map.width = w;
  map.height = h;
  if ((map.tab = malloc(sizeof(sfVector3f) * (w * h))) == NULL)
    return (map);
  return (fill_map(buffer, map));
}