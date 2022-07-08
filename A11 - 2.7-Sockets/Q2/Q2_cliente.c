#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main (int argc, char* const argv[])
{
	if(argc < 2)
	{
		puts("Modo de Uso:");
		printf("%s NOME_SOCKET\n", argv[0]);
		exit(1);
	}
	char *socket_name;
	char mensagem[2];
	int socket_id;
	struct sockaddr name;
	int length;

	socket_name = argv[1];

    for(int i=1; i<11; i++){
		sprintf(mensagem, "%d", i);
        socket_id = socket(PF_LOCAL, SOCK_STREAM,0);
        name.sa_family = AF_LOCAL;
        strcpy(name.sa_data, socket_name);
        connect(socket_id, &name, sizeof(name));
        length = strlen(mensagem) + 1;
        write(socket_id, &length, sizeof(int));
        write(socket_id, mensagem, length);
        close(socket_id);
		sleep(1);
    }
	return 0;
}
