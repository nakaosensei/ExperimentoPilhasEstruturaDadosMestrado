# !/bin/sh
# cria o Object file (arquivos.o)
gcc -c libraries/fila_contigua.c -lrt
gcc -c libraries/fila_encadeada.c -lrt
gcc -c libraries/fila_prioridade_encadeada.c -lrt
gcc -c libraries/fila_prioridade_heap.c -lrt
gcc -c main.c -lrt

contigua='fila_contigua.o'
encadeada='fila_encadeada.o'
prioridade_encadeada='fila_prioridade_encadeada.o'
prioridade_heap='fila_prioridade_heap.o'
main='main.o'

#cria o linker juntando todos os object file criados anteriorimente.
gcc -o binary $prioridade_heap $main -lrt

#executa o linker (executavel)
./binary

#executa o linker (executavel) com software valgrind
# valgrind --leak-check=full ./binary

#remover arquivos object e binário
rm *.o
rm binary