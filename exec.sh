# !/bin/sh
# cria o Object file (arquivos.o)
gcc -c libraries/pilha_contigua.c -lrt
gcc -c main.c -lrt

contigua='pilha_contigua.o'
main='main.o'

#cria o linker juntando todos os object file criados anteriorimente.
gcc -o binary $contigua $main -lrt

#executa o linker (executavel)
./binary

#executa o linker (executavel) com software valgrind
# valgrind --leak-check=full ./binary

#remover arquivos object e binário
rm *.o
rm binary


# #cria o Object file (arquivos.o)
# gcc -c libraries/pilha_encadeada.c -lrt
# gcc -c main.c -lrt

# encadeada='pilha_encadeada.o'
# main='main.o'

# #cria o linker juntando todos os object file criados anteriorimente.
# gcc -o binary $encadeada $main -lrt

# #executa o linker (executavel)
# ./binary

# #executa o linker (executavel) com software valgrind
# # valgrind --leak-check=full ./binary

# #remover arquivos object e binário
# rm *.o
# rm binary
