#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <arpa/inet.h>

char* falasCliente[] = {
	"Pai, qual é a verdadeira essência da sabedoria?",
	"Mas até uma criança de três anos sabe disso!"
};

int print_client_message(int client_socket)
{
	int length, end_server_ok;
	char* text;
	read(client_socket, &length, sizeof(int));
	text = (char*) malloc(length);
	read(client_socket, text, length);
	fprintf(stderr,"SERVIDOR: %s\n", text);
	end_server_ok = !strcmp(text, "sair");
	free(text);
	return end_server_ok;
}

int main (int argc, char* const argv[])
{
	if(argc < 2)
	{
		puts("Modo de Uso:");
		printf("%s NOME_SOCKET\n", argv[0]);
		exit(1);
	}

	char *socket_name;
	char *mensagem;
	char *text;
	int socket_id;
	struct sockaddr name;
	int length;

	socket_name = argv[1];
	socket_id = socket(PF_LOCAL, SOCK_STREAM,0);
	
	name.sa_family = AF_LOCAL;
	strcpy(name.sa_data, socket_name);
	// Manda primeira fala
	connect(socket_id, &name, sizeof(name));
	mensagem = falasCliente[0];
	length = strlen(mensagem) + 1;
	write(socket_id, &length, sizeof(int));
	write(socket_id, mensagem, length);
	write(socket_id, "0", 1);
	fprintf(stderr,"CLIENTE: %s\n", falasCliente[0]);
	// Recebe primeira resposta
	read(socket_id, &length, sizeof(int));
	text = (char*) malloc(length);
	read(socket_id, text, length);
	fprintf(stderr,"SERVIDOR: %s\n", text);
	free(text);

	close(socket_id);
	sleep(1);

	// Manda segunda fala
	socket_id = socket(PF_LOCAL, SOCK_STREAM,0);
	connect(socket_id, &name, sizeof(name));
	mensagem = falasCliente[1];
	length = strlen(mensagem) + 1;
	write(socket_id, &length, sizeof(int));
	write(socket_id, mensagem, length);
	write(socket_id, "1", 1);
	fprintf(stderr,"CLIENTE: %s\n", falasCliente[1]);
	// Recebe segunda resposta
	read(socket_id, &length, sizeof(int));
	text = (char*) malloc(length);
	read(socket_id, text, length);
	fprintf(stderr,"SERVIDOR: %s\n", text);
	free(text);

	close(socket_id);
	
	return 0;
}
