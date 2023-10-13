#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>


int Socket(int family, int type, int protocol);

/*void Connect(int sockfd, struct sockaddr servaddr)
{
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr,"connect error\n");
        exit(1);
    }
}*/

