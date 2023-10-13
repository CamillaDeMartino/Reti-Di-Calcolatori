/**
 * Realizzare una libreria di wrapper per le chiamate alle procedure per le socket:
   - socket, connect, bind, listen, accept
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "wrapper.h"

int Socket(int family, int type, int protocol)
{
  int n;
  if ( (n = socket(family, type, protocol)) < 0) {
    perror("socket");
    exit(1);
  }

  return(n);
}