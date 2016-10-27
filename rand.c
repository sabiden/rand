#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


int ranInt(){
  int fd = open("/dev/random",O_RDONLY);

  int * mem;
  mem = (int *)malloc(sizeof(int));
  
  int rdret = read(fd, mem, 4);

  int retVal = *mem;

  close(fd);

  free(mem);

  if(rdret < 0){
    printf("error has occured: %d :  %s", errno,strerror(errno));
  }
  
  if (retVal < 0){
    retVal = (retVal * -1);
  }

  return retVal;
}

void main(){
  printf("===The code works but takes a while to load, at it did for me===\n\n");
  printf("Adding values to the initial array\n\n");
  int x = 0;
  int arr[10];
  while (x < 10){
    int ranVal = ranInt();
    printf("random %i :%i\n",x,ranVal);
    arr[x] = ranVal;
    x++;
  }
  int fd = open("output.txt", O_CREAT | O_RDWR, 0644);
  printf("Writing to output file\n\n");
  write(fd, arr, sizeof(int) * 10);
  close(fd);
  fd = open("output.txt", O_RDONLY);
  int arr2[10];
  printf("Reading from output file into new array\n\n");
  read(fd, arr2,  sizeof(int) * 10);
  int j = 0;
  printf("Printing second array\n\n");
  while(j<10){
    printf("arr2[%i] : %i\n", j, arr2[j]);
    j++;
  }
  close(fd);
}
  
