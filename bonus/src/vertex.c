/*
** vertex.c for wireframe in /home/benito/delivery/wireframe/bonus
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.net>
** 
** Started on  Sat Dec  3 21:26:39 2016 Benoit Lormeau
** Last update Sat Dec  3 21:26:41 2016 Benoit Lormeau
*/

#include "buffer.h"
#include "my_sfml.h"

sfColor	get_colorFromHeight(float z)
{
  float	f;

  f = my_map(z, 0, 8, 50, 255);
  // if (z > 7)
  //   return ((sfColor){0, 255, 255, 0});
  // else if (z > 4)
  //   return ((sfColor){100, 40, 0, 0});
  // if (z > 0.5)
  //   return ((sfColor){0, 100, 0, 0});
  // else
    return ((sfColor){f, 0, 0, 0});

  return (sfBlack);
}

sfVertexArray	*get_vertexArray(sfVertexArray *vertices, char *path)
{
  t_map		map;

  map = parse_buffer(path);

  for (int i = 0; i < 2500; ++i){
    map.tab[i].x -= 25;
    map.tab[i].y -= 25;

    sfVertexArray_append(vertices,
      (sfVertex){
    	my_orthogonal_projection(map.tab[i], omega_, alpha_),
	get_colorFromHeight(map.tab[i].z),
	(sfVector2f){0, 0}
      }
    );
  }

  return (vertices);
}

sfVertexArray	*get_vertexArray_line(sfVertexArray *vertices, unsigned int start)
{
  sfVertexArray	*line;

  line = sfVertexArray_create();

  for (int i = 0; i < 50; ++i){
    sfVertexArray_append(line, *sfVertexArray_getVertex(vertices, start + i));
    sfVertexArray_append(line, *sfVertexArray_getVertex(vertices, start + i + 50));
  }

  return (line);
}