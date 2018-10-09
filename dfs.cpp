// Projeto 2 de Teoria e Aplicação de Grafos, Turma A
// Prof.: Díbio
// Autores: Rafael Gonçalves de Paulo (17/0043959)
//          João Lucas Azevedo Yamin Rodrigues da Cunha (17/0013731)
// dfs.c: Arquivo de implementação de funções para busca

#include "dfs.h"

// DFS_post: Percorre o grafo em DFS, e executa foo() com cada vertice v em pos-ordem
void DFS_post(Grafo& grafo, vector<int> start, function<void (int)> foo) {

    vector<bool> visited(grafo.size(), false); 
    
    // iterar o DFS em todos os vértices dados, se não tiverem sido visitados
    if (start.size() > 0)
    for (auto vert: start)
        if (!visited[vert]) DFS_post_util(grafo, vert, visited, foo);

    // fazer os outros caminhos, se existirem
    for (unsigned int i = 0; i < visited.size(); i++)
        if (!visited[i]) DFS_post_util(grafo, i, visited, foo);
}

// DFS_post_util: Função recursiva auxiliar de DFS_post
void DFS_post_util(Grafo& grafo, int atual, vector<bool>& visited, function<void (int)> foo) {
    visited[atual] = true;
    for (auto vert : grafo[atual])
        if (!visited[vert]) {
            DFS_post_util(grafo, vert, visited, foo);
        }
    foo(atual);
}