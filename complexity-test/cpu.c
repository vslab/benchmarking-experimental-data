#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i = 0;
  int res = 0;
  for(i=0;i<1024*1024;i++)
    {
      res = (res * (rand() % 1024)) % 1024;
    }
  printf("res=%d", res);
  return 0;
}
