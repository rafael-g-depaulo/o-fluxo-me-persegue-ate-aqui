#include "dfs.h"

// percorre o grafo em DFS, e executa foo() com cada vertice v em pos-ordem
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

// funcao recursiva auxiliar de DFS_post
void DFS_post_util(Grafo& grafo, int atual, vector<bool>& visited, function<void (int)> foo) {
    visited[atual] = true;
    for (auto vert : grafo[atual])
        if (!visited[vert]) {
            DFS_post_util(grafo, vert, visited, foo);
        }
    foo(atual);
}