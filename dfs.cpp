#include "dfs.h"

// percorre o grafo em DFS, e executa foo() com cada vertice v em pos-ordem
void DFS_post(Grafo& grafo, int start, void foo(int)) {

    vector<bool> visited(grafo.size(), false); 
    DFS_post_util(grafo, start, visited, foo);
    // fazer os outros caminhos, se existirem
    for (unsigned int i = 0; i < visited.size(); i++)
        if (!visited[i]) DFS_post_util(grafo, i, visited, foo);
}

// funcao recursiva auxiliar de DFS_post
void DFS_post_util(Grafo& grafo, int atual, vector<bool>& visited, void foo(int)) {
    visited[atual] = true;
    for (auto vert : grafo[atual])
        if (!visited[vert]) {
            DFS_post_util(grafo, vert, visited, foo);
        }
    foo(atual);
}