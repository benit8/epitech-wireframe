/*
** main.c for CGP_bootstrap in /home/benito/delivery/PSU_2016_C_Graphical_programming_bootstrap
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.net>
** 
** Started on  Wed Nov  9 13:37:06 2016 Benoit Lormeau
** Last update Tue Nov 15 13:55:19 2016 Benoit Lormeau
*/

#include "buffer.h"
#include "my_sfml.h"

t_my_framebuffer	*get_framebuffer(char *path)
{
  t_map			map;
  t_my_framebuffer	*framebuffer;
  sfVector3f		l;
  sfColor		color;
  int			i;

  map = parse_buffer(path);
  color = sfColor_fromRGBA(90, 90, 90, 255);
  if ((framebuffer = my_framebuffer_create(640, 480)) == NULL)
    return (NULL);
  my_draw_grid(framebuffer, map.width, map.height);
  i = -1;
  while (++i < (map.width * map.height))
    {
      l = sfVector_from3f(map.tab[i].x, map.tab[i].y, 0);
      my_draw_line_3d(framebuffer, l, map.tab[i], color);
    }
  my_join_points(framebuffer, map);
  return (framebuffer);
}

t_init			init(char *path)
{
  t_init		vars;

  vars.mode.width = 640;
  vars.mode.height = 480;
  vars.mode.bitsPerPixel = 32;
  if ((vars.framebuffer = get_framebuffer(path)) == NULL)
    return (vars);
  vars.sprite = sfSprite_create();
  vars.texture = sfTexture_create(640, 480);
  sfSprite_setTexture(vars.sprite, vars.texture, sfTrue);
  sfTexture_updateFromPixels(vars.texture, vars.framebuffer->pixels, 640, 480, 0, 0);
  vars.window = sfRenderWindow_create(vars.mode, "Wireframe", sfResize | sfClose, NULL);
  return (vars);
}

int			main(int ac, char **av)
{
  t_init		vars;
  sfEvent		event;

  if (ac < 2)
    return (84);
  vars = init(av[1]);
  if (vars.framebuffer == NULL)
    return (84);
  while (sfRenderWindow_isOpen(vars.window))
    {
      while (sfRenderWindow_pollEvent(vars.window, &event))
	{
	  if (event.type == sfEvtClosed)
	    sfRenderWindow_close(vars.window);
	  if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
	    sfRenderWindow_close(vars.window);
	}
      sfRenderWindow_clear(vars.window, sfWhite);
      sfRenderWindow_drawSprite(vars.window, vars.sprite, NULL);
      sfRenderWindow_display(vars.window);
    }
  sfRenderWindow_destroy(vars.window);
  free(vars.framebuffer);
  return (0);
}
