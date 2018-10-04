#include "ordenacao.h"
#include "grau.h"
#include "dfs.h"
#include <iostream>

deque<int> _ord;    // variavel auxiliar
void add2Deque(int n) {
    _ord.push_front(n);
}

deque<int> ordenacaoTopologica(Grafo& grafo) {
    vector<int> roots = getRoots(grafo);    // pega os possíveis pontos iniciais
    if (roots.empty()) {
        cout << "Grafo não tem nó sem prerequisitos!!!!\n";
        throw "ERRO: grafo sem raiz";
    }

    // agora percorremos o grafo com DFS em pos ordem, adicionando os vertices em um stack
    _ord = deque<int>();    // resetando a variavel auxiliar
    DFS_post(grafo, getRoots(grafo)[0], add2Deque);
    return _ord;
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