// Projeto 2 de Teoria e Aplicação de Grafos, Turma A
// Prof.: Díbio
// Autores: Rafael Gonçalves de Paulo (17/0043959)
//          João Lucas Azevedo Yamin Rodrigues da Cunha (17/0013731)
// ordenacao.c: Arquivo de implementação de funções para ordenação topológica

#include "ordenacao.h"
#include "grau.h"
#include "dfs.h"
#include <iostream>

// ordenacaoTopologica: Função principal de ordenação topologica
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

// getRoots: Acha todos os vértices que são referenciados por nenhum outro vértice
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