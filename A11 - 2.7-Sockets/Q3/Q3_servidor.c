#include "server_funcs.h"

char* falasServidor[] = {
	"Não façais nada violento, praticai somente aquilo que é justo e equilibrado.",
	"Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu..."
};

int main (int argc, char* const argv[])
{
	if(argc < 2)
	{
		puts("Modo de Uso:");
		printf("%s NUM_PORTA\n", argv[0]);
		exit(1);
	}
	
	struct sockaddr socket_struct;
	signal(SIGINT, end_server);
	strcpy(socket_name, argv[1]);
	socket_id = socket(PF_LOCAL, SOCK_STREAM, 0);
	socket_struct.sa_family = AF_LOCAL;
	strcpy(socket_struct.sa_data, socket_name);
	bind(socket_id, &socket_struct, sizeof(socket_struct));
	listen(socket_id, 10);

	char indexFala[2];
	int index;
	while(1)
	{
		int socket_id_cliente, end_server_ok;
		end_server_ok = 0;
		struct sockaddr clienteAddr;
		socklen_t clienteLength = sizeof( (struct sockaddr *) &clienteAddr);

		socket_id_cliente = accept(socket_id, &clienteAddr, &clienteLength);
		end_server_ok = print_client_message(socket_id_cliente);

		read(socket_id_cliente, &indexFala, 1);
		// printf("%s\n", indexFala);
		index = atoi(indexFala);
		if(!strcmp(&indexFala, "0")){
			// printf("Fala 0\n");
			int length = strlen(falasServidor[0]) + 1;
			write(socket_id_cliente, &length, sizeof(int));
			write(socket_id_cliente, falasServidor[0], length);
		}else if(!strcmp(&indexFala, "1")){
			// printf("Fala 1\n");
			int length = strlen(falasServidor[1]) + 1;
			write(socket_id_cliente, &length, sizeof(int));
			write(socket_id_cliente, falasServidor[1], length);
		}
		close(socket_id_cliente);

		if(end_server_ok)
			end_server(0);
	}

	return 0;
}
