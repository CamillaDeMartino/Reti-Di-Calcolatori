/**
 * Utilizzando le funzioni wrapper
 * - riscrivere il client daytime
 * - riscrivere il server daytime
 * – test
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "wrapper.h"

int main(int argc, char **argv)
{
    int sockfd, n;
    char recvline[1025] ;
    struct sockaddr_in servaddr;

    if (argc != 2) {
        fprintf(stderr,"usage: %s <IPaddress>\n",argv[0]);
        exit (1);
    }

    //socket utilizzando wrapper
    sockfd = Socket(AF_INET, SOCK_STREAM, 0);
    /*if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr,"socket error\n");
        exit (1);
    }*/
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr,"inet_pton error for %s\n", argv[1]);
        exit (1);
    }

    //connect utilizzando wrapper
    Connect(sockfd, (struct sockaddr_in) servaddr);
    /*if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr,"connect error\n");
        exit(1);
    }*/

    
    while ( (n = read(sockfd, recvline, 1024)) > 0) {
        recvline[n] = 0;
        if (fputs(recvline, stdout) == EOF) {
            fprintf(stderr,"fputs error\n");
            exit(1);
        }
    }
    if (n < 0) {
        fprintf(stderr,"read error\n");
        exit(1);
    }
    exit(0);

}

   
