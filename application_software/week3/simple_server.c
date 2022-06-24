/* run using ./server <port> */
#include "http_server.hh"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#include <pthread.h>
void error(char *msg) {
  perror(msg);
  exit(1);
}
void *mySockFunc(void *arg) {
  int n;
  int newsockfd = *(int *)arg;
  char buffer[256];
   if (newsockfd < 0)
    error("ERROR on accept");

  /* read message from client */
  while(1){
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    if (n < 0)
      error("ERROR reading from socket");
    // printf(buffer);
    if(buffer == "quit") {
      close(newsockfd);
      break;
    }
    // HTTP_Response res(handle_request(buffer));
    /* send reply to client */
    // res = handle_request(buffer);
    HTTP_Response res;
    res.handle_request(buffer);
    buffer = res.get_string();
    n = write(newsockfd, buffer, 18);
    if (n < 0)
      error("ERROR writing to socket");
  }
  return 0;
}



int main(int argc, char *argv[]) {
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  
  struct sockaddr_in serv_addr, cli_addr;

  if (argc < 2) {
    fprintf(stderr, "ERROR, no port provided\n");
    exit(1);
  }

  /* create socket */

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
    error("ERROR opening socket");

  /* fill in port number to listen on. IP address can be anything (INADDR_ANY)
   */

  bzero((char *)&serv_addr, sizeof(serv_addr));
  portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  /* bind socket to this port number on this machine */

  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    error("ERROR on binding");

  /* listen for incoming connection requests */

  listen(sockfd, 5);
  clilen = sizeof(cli_addr);
  pthread_t tid[10];
  int i = 0;
  /* accept a new request, create a newsockfd */
  while(1) {
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    pthread_create(&tid[i++],NULL, mySockFunc, &newsockfd);
  }

  return 0;
}