// Projeto 2 de Teoria e Aplicação de Grafos, Turma A
// Prof.: Díbio
// Autores: Rafael Gonçalves de Paulo (17/0043959)
//          João Lucas Azevedo Yamin Rodrigues da Cunha (17/0013731)
// dfs.h: Arquivo de declaração de funções para busca

#include <vector>
#include <functional>
#include "construction.h"

using namespace std;

// DFS_post: Percorre o grafo em DFS, e executa foo() com cada vertice v em pos-ordem
void DFS_post(Grafo& grafo, vector<int> start, function<void (int)> foo);

// DFS_post_util: Função recursiva auxiliar de DFS_post
void DFS_post_util(Grafo& grafo, int atual, vector<bool>& visited, function<void (int)> foo);