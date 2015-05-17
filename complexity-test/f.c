#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int f(int size)
{
  int i,j,x,y = 0;
  int res = 0;
  
  for(i=0;i<((int)log2f((float)size));i++)
    {
      // just a fixed load for every iteration to make the computation heavy
      for (x=0;x<1024*1024;x++)
	{
	  res = ((res + x) % size ) * (x % 1024);
	}      
      res = res + rand() % 2;
    }
  return res;
}

int main(int argc, char *argv[])
{
  int res = 0;
  int size = 1024;
  if(argc>1)
    {
      //size = atoi(argv[1]);
      sscanf(argv[1], "%d", &size);
    } 
  res = f(size);  
  printf("res=%d\n", res);
  return 0;
}
