
#include <string.h>
#include <stdio.h>

#define SIZE (int)strlen("salut")

int	main(void)
{
  char	buffer[SIZE];

  strcpy(buffer, "salut");
  printf("%s\n", buffer);
  return (0);
}
