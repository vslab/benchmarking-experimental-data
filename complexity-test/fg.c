#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int g(int size);

int f1(int size)
{
  int i,j,x,y = 0;
  int res = 0;
  printf("log(%d)=%d\n", size, (int)log2f((float)size));
  for(i=0;i<(int)log2f((float)size);i++)
    {
      // just a fixed load for every iteration to make the computation heavy
      for (x=0;x<1024;x++)
	{
	  for (y=0;y<1024;y++)
	    {
	      res = ((((res + x + y) % size ) * x % size) * y % size);
	    }
	}
      res = (res + rand() % 2 + g(size)) % size;
    }
  return res;
}

int f2(int size)
{
  int i,j,x,y = 0;
  int res = 0;
  printf("log(%d)=%d\n", size, (int)log2f((float)size));
  for(i=0;i<(int)log2f((float)size);i++)
    {
      // just a fixed load for every iteration to make the computation heavy
      for (x=0;x<1024;x++)
	{
	  for (y=0;y<1024;y++)
	    {
	      res = ((((res + x + y) % size ) * x % size) * y % size);
	    }
	}
      res = (res + rand() % 2) % size;
    }
  res = res + g(size);
  return res;
}

int f3(int size)
{
  int i,j,x,y = 0;
  int res = 0;
  printf("log(%d)=%d\n", size, (int)log2f((float)size));
  for(i=0;i<(int)log2f((float)size);i++)
    {
      // just a fixed load for every iteration to make the computation heavy
      for (x=0;x<1024;x++)
	{
	  for (y=0;y<1024;y++)
	    {
	      res = ((((res + x + y) % size ) * x % size) * y % size);
	    }
	}
      res = (res + rand() % 2) % size + g(i+1);
    }
  return res;
}


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
  int alg = 0;
  int res = 0;
  int size = 1024;
  float factor = 0.0;
  if(argc>1)
    {
      //size = atoi(argv[1]);
      sscanf(argv[1], "%d", &size);
    }
  if(argc>2)
    {
      //size = atoi(argv[1]);
      sscanf(argv[2], "%d", &alg);
    }
  switch(alg)
    {
    case 0:
      res = f1(size);
      break;
    case 1:
      res = f2(size);
      break;
    case 2:
      res = f3(size);
      break;
    }
  printf("res=%d\n", res);
  return 0;
}
