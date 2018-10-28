#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int randgen(){
  int fd = open("/dev/random", O_RDONLY);

  if(fd == -1){
    printf(" Error opening /dev/random: %s\n", strerror(errno));
    return -1;
  }

  int buf;
  int r = read(fd, &buf, sizeof(buf));
  if(r == -1){
    printf(" Error reading from /dev/random: %s\n", strerror(errno));
    return -1;
  }

  close(fd);

  return buf;
}
