#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i = 0;
  int res = 0;
  int *buf;
  buf = (int *) calloc(1024*1024, sizeof(int));
  for(i=0;i<1024*1024;i++)
    {
      buf[i] = rand();
    }
  for(i=0;i<1024*1024;i++)
    {
      res = (res + buf[rand() % 1024*1024] % 1024) % 1024;
    }
  printf("res=%d", res);
  free(buf);
  return 0;
}
