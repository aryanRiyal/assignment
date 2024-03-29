#include "../lib/header.h"

void *doit(void *arg){
	pthread_detach(pthread_self());
	int clientSocket = *(int *)arg;
	char recvBuff[MB];
	memset(recvBuff,0,MB);
	while(1){
		serverRecv(clientSocket,recvBuff);
		if(strncmp(recvBuff,"bye",3)==0){
			printf("\n[+]Disconnected from - Client(%d)\n\n",n_client);
			break;
		}
	}
	close(clientSocket);
	return arg;
}
int main(void){
    int listenfd=0;
    int clientSocket;
    pthread_t tid;
    // calling socket(), bind(), listen() with error handling
    createServerSocket( &listenfd);
    while(1){
	n_client = clientHandle(listenfd,&clientSocket);
	if(pthread_create(&tid,NULL,doit,&clientSocket)==0){
		// pthread_detach(pthread_self());
                printf("pthread_create() success");
	}
	else{
		perror("pthread_create() error");
	}
    }
    close(listenfd);
    printf("\n...Terminating the session...\n");
    return (EXIT_SUCCESS);
}
