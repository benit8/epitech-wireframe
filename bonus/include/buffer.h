/*
** buffer.h for wireframe in /home/benito/delivery/wireframe
** 
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.net>
** 
** Started on  Tue Nov 15 19:28:43 2016 Benoit Lormeau
** Last update Tue Nov 15 19:29:11 2016 Benoit Lormeau
*/

#ifndef	BUFFER_H_
#define	BUFFER_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_sfml.h"

t_map	parse_buffer(char *path);

#endif
