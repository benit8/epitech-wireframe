#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int	main(int ac, char **av)
{
  if (ac != 3){
    printf("usage: ./gen [width] [height]\n");
    return (EXIT_FAILURE);
  } else {
    srand(time(NULL));

    int w = atoi(av[1]);
    int h = atoi(av[2]);

    for (int i = 0; i < h; ++i)
      {
	for (int j = 0; j < w; ++j)
	  {
	    printf("%d", rand() % 4);
	    if (i != h - 1 || j != w - 1)
	      printf(",");
	    if (j != w - 1)
	      printf(" ");
	  }
	printf("\n");
      }
    printf("\n");
  }

  return (EXIT_SUCCESS);
}