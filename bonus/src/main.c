/*
** main.c for CGP_bootstrap in /home/benito/delivery/PSU_2016_C_Graphical_programming_bootstrap
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.net>
** 
** Started on  Wed Nov  9 13:37:06 2016 Benoit Lormeau
** Last update Tue Nov 15 13:55:19 2016 Benoit Lormeau
*/

#include <stdio.h>
#include <time.h>
#include "buffer.h"
#include "my_sfml.h"

int	orig_x  = WIDTH / 2;
int	orig_y  = HEIGHT / 2;

float	alpha_  = 10;
float	omega_  = -0.6;
float	factor_ = 7;
float	inc_    = 1;

t_my_framebuffer	*get_framebuffer()
{
  t_my_framebuffer	*framebuffer;

  framebuffer = my_framebuffer_create(WIDTH, HEIGHT);
  clear_framebuffer(framebuffer);
  return (framebuffer);
}

t_init		init()
{
  t_init	vars;

  // Mode
  vars.mode.width = WIDTH;
  vars.mode.height = HEIGHT;
  vars.mode.bitsPerPixel = 32;

  // Framebuffer
  vars.framebuffer = get_framebuffer();

  // Texture / Sprite
  vars.sprite = sfSprite_create();
  vars.texture = sfTexture_create(WIDTH, HEIGHT);
  sfTexture_updateFromPixels(vars.texture, vars.framebuffer->pixels, WIDTH, HEIGHT, 0, 0);
  sfSprite_setTexture(vars.sprite, vars.texture, sfTrue);

  // Vertices
  vars.vertices = sfVertexArray_create();
  vars.vertexTab = malloc(sizeof(sfVertexArray *) * (MAP_H - 1));

  // States
  vars.states = malloc(sizeof(sfRenderStates));
  vars.states->blendMode = sfBlendNone;
  vars.states->transform = sfTransform_Identity;
  vars.states->texture = vars.texture;
  vars.states->shader = sfShader_createFromFile(NULL, NULL);

  // RenderWindow
  vars.rWindow = sfRenderWindow_create(vars.mode, "Wireframe sauce Benito", sfResize | sfClose, NULL);
  return (vars);
}

void	update(t_init vars, char *path)
{
  sfVertexArray_clear(vars.vertices);
  vars.vertices = get_vertexArray(vars.vertices, path);

  for (int i = 0; i < MAP_H - 1; i++){
    vars.vertexTab[i] = get_vertexArray_line(vars.vertices, i * MAP_W);
    sfVertexArray_setPrimitiveType(vars.vertexTab[i], sfTrianglesStrip);
  }
}

int		main(int ac, char **av)
{
  t_init	vars;
  sfEvent	event;

  srand(time(NULL));
  if (ac < 2)
    return (84);
  vars = init();
  while (sfRenderWindow_isOpen(vars.rWindow))
    {
      if (inc_)
        update(vars, av[1]);
      while (sfRenderWindow_pollEvent(vars.rWindow, &event))
	{
	  if (event.type == sfEvtClosed)
	    sfRenderWindow_close(vars.rWindow);
	  if (event.type == sfEvtKeyPressed){
	      if (event.key.code == sfKeyEscape)
		sfRenderWindow_close(vars.rWindow);
	      if (event.key.code == sfKeyZ)
	        alpha_ -= 0.1;
	      if (event.key.code == sfKeyS)
	        alpha_ += 0.1;
	      if (event.key.code == sfKeyD)
	        omega_ += 0.1;
	      if (event.key.code == sfKeyQ)
	        omega_ -= 0.1;
	      if (event.key.code == sfKeyE)
	        inc_ += 0.1;
	      if (event.key.code == sfKeyA)
	        inc_ -= 0.1;
	      if (event.key.code == sfKeyUp)
	        orig_y -= 100;
	      if (event.key.code == sfKeyDown)
	        orig_y += 100;
	      if (event.key.code == sfKeyRight)
	        orig_x += 100;
	      if (event.key.code == sfKeyLeft)
	        orig_x -= 100;
	    }
	  if (event.type == sfEvtMouseWheelMoved)
	    factor_ += (float) event.mouseWheel.delta;
	}
      sfRenderWindow_clear(vars.rWindow, sfWhite);

      for (int i = 0; i < MAP_H - 1; ++i)
        sfRenderWindow_drawVertexArray(vars.rWindow, vars.vertexTab[i], vars.states);

      sfRenderWindow_display(vars.rWindow);
    }
  sfRenderWindow_destroy(vars.rWindow);
  free(vars.framebuffer);
  return (0);
}
