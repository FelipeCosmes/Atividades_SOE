all: Q2_servidor.out Q2_cliente.out
Q2_servidor.out: Q2_servidor.o server_funcs.o
	gcc Q2_servidor.o server_funcs.o -o Q2_servidor
Q2_cliente.out: Q2_cliente.c
	gcc Q2_cliente.c -o Q2_cliente
Q2_servidor.o: Q2_servidor.c
	gcc -c Q2_servidor.c
server_funcs.o: server_funcs.c
	gcc -c server_funcs.c
clean:
	rm -f *.out *.o *.bin *.txt *.html
