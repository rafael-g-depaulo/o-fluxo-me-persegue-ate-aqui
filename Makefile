################################################################
# pra cada modulo(.cpp), fazer assim:
# 
# nomeDoModulo.o: nomeDoModulo.cpp [e outras dependencias .o, se tiver]
# 	$(CC) $(CFLAGS) nomeDoModulo.cpp
# 
# depois, adicione "nomeDoModulo.o" em "MODULES", do lado dos outros .o's
#

# Compilador:
CC = g++

# Flags:
CFLAGS = -c -g -Wall -std=c++11

# modulos
MODULES = construction.o grau.o ordenacao.o dfs.o

# Compila o executavel a partir dos .o's
executavel: main.o $(MODULES)
	$(CC) main.o $(MODULES) -fPIC -o main

# modulo principal, o programa em si
main.o: main.cpp construction.o dfs.o
	$(CC) $(CFLAGS) main.cpp
	
# modulo de leitura de arquivo e criação do grafo
construction.o: construction.cpp
	$(CC) $(CFLAGS) construction.cpp
	
# modulo que pega o grau do vértice
grau.o: grau.cpp
	$(CC) $(CFLAGS) grau.cpp

# modulo que cria uma ordenação topológica 
ordenacao.o: ordenacao.cpp
	$(CC) $(CFLAGS) ordenacao.cpp

# modulo que percorre o grafo em DFS
dfs.o: dfs.cpp
	$(CC) $(CFLAGS) dfs.cpp