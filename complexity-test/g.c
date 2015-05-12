#include <stdio.h>
#include <stdlib.h>

int g(int size)
{
  int i;
  int *buf;
  int res = 0;
  buf = (int *) calloc(size, sizeof(int));
  // fill random locations with random data
  for(i=0;i<size;i++)
    {
      buf[rand() % size] = rand() % size;
    }
  // sum content of random locations
  for(i=0;i<size;i++)
    {
      res = (res + buf[rand() % size]) % size;
    }
  free(buf);
  return res;
}

int main(int argc, char *argv[])
{
  int i = 0;
  int res = 0;
  int size = 1024;
  if(argc>1)
    {
      //size = atoi(argv[1]);
      sscanf(argv[1], "%d", &size);
    } 
  res = g(size);
  printf("res=%d\n", res);
  return 0;
}
