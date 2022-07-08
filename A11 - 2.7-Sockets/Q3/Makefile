all: Q3_servidor.out Q3_cliente.out
Q3_servidor.out: Q3_servidor.o server_funcs.o
	gcc Q3_servidor.o server_funcs.o -o Q3_servidor
Q3_cliente.out: Q3_cliente.c
	gcc Q3_cliente.c -o Q3_cliente
Q2_servidor.o: Q3_servidor.c
	gcc -c Q3_servidor.c
server_funcs.o: server_funcs.c
	gcc -c server_funcs.c
clean:
	rm -f *.out *.o *.bin *.txt *.html
