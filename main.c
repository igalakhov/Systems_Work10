#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "randgen.h"


int main(){
  printf("Generating random numbers:\n");

  int * arr = malloc(10 * sizeof(int));
  int * arr_end = arr + 10;
  int * arr_p = arr;
  while(arr_end - arr_p){
    *arr_p = randgen();
    printf(" Random number %ld: %d\n", arr_p - arr, *arr_p);
    arr_p++;
  }

  printf("\nOpening [foo.txt] for writing\n");

  int fd = open("foo.txt", O_CREAT|O_WRONLY, 0700);

  if(fd == -1){
    printf(" Error opening file: %s\n", strerror(errno));
    printf(" Exiting program...\n");
    exit(0);
  } else {
    printf(" File opened! (descriptor %d)\n", fd);
  }

  printf("\nWriting random numbers to file:\n");
  int w = write(fd, arr, 10*sizeof(int));
  if(w == -1){
    printf(" Error writing bytes: %s\n", strerror(errno));
    printf(" Exiting program...\n");
    exit(0);
  } else {
    printf(" %d Bytes written!\n", w);
  }

  close(fd);

  printf("\nOpening [foo.txt] for reading\n");

  fd = open("foo.txt", O_RDONLY, 0700);

  if(fd == -1){
    printf(" Error opening file: %s\n", strerror(errno));
    printf(" Exiting program...\n");
    exit(0);
  } else {
    printf(" File opened! (descriptor %d)\n", fd);
  }

  printf("\nReading from [foo.txt]\n");

  int * new_arr = malloc(sizeof(int) * 10);
  int r = read(fd, new_arr, 10*sizeof(int));

  if(r == -1){
    printf(" Error reading bytes: %s\n", strerror(errno));
    printf(" Exiting program...\n");
    exit(0);
  } else {
    printf(" %d Bytes read!\n", w);
  }

  int * new_arr_p = new_arr;
  int * new_arr_end = new_arr + 10;
  printf("\nPrinting read content:\n");
  while(new_arr_end - new_arr_p){
    printf(" Random number %ld: %d\n", new_arr_p - new_arr, *new_arr_p);
    new_arr_p++;
  }
  printf("\n");

  return 0;
}
