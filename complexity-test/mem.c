#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  int i = 0;
  int res = 0;
  int *buf;
  int jump = 32;
  int size = 1024*1024*16;
  int bufsize = 1024*1024*16;
  int pos = 0;
  if(argc>1)
    {
      //size = atoi(argv[1]);
      sscanf(argv[1], "%d", &jump);
    } 

  buf = (int *) calloc(bufsize, sizeof(int));
  // fill the buffer with bounded random data
  for(i=0;i<size;i++)
    {
      pos = (pos + jump + 1) % bufsize;
      buf[pos] = i;
    }
  // do something with the data to ensure the compiler doesn't take everything away
  res = buf[rand() % bufsize];
  printf("res=%d\n", res);
  free(buf);
  return 0;
}
