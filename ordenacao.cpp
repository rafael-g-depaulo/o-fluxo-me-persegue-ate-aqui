#include "ordenacao.h"
#include "grau.h"
#include "dfs.h"
#include <iostream>

deque<int> ordenacaoTopologica(Grafo& grafo) {
    vector<int> roots = getRoots(grafo);    // pega os possíveis pontos iniciais
    if (roots.empty()) {
        cout << "Grafo não tem nó sem prerequisitos!!!!\n";
        throw "ERRO: grafo sem raiz";
    }

    // agora percorremos o grafo com DFS em pos ordem, adicionando os vertices em um stack
    deque<int> ord;    // resetando a variavel auxiliar
    DFS_post(grafo, getRoots(grafo), [&ord] (int x) { ord.push_front(x); });
    return ord;
}

vector<int> getRoots(Grafo& grafo) {
    vector<bool> rootsBool(grafo.size(), true);

    for (auto vert1: grafo)
        for (auto v : vert1)
            rootsBool[v] = false;
    
    vector<int> roots;
    for (unsigned int i = 0; i < rootsBool.size(); i++)
        if (rootsBool[i]) roots.push_back(i);

    return roots;
}