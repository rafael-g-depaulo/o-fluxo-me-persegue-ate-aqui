// Projeto 2 de Teoria e Aplicação de Grafos, Turma A
// Prof.: Díbio
// Autores: Rafael Gonçalves de Paulo (17/0043959)
//          João Lucas Azevedo Yamin Rodrigues da Cunha (17/0013731)
// caminho.h: Arquivo de declaração de funções para buscar caminho crítico

#include <vector>
#include <deque>
#include <queue>
#include <functional>
#include "construction.h"

using namespace std;

typedef pair<int, vector<int> > Caminho;

// shortestPathToLeaf: encontra o menor caminho para uma folha
deque<int> shortestPathToLeaf(Grafo g, Creditos c, Estresses e, int src);

// criticalPath: encontra o caminho crítico
deque<int> criticalPath(Grafo g, Creditos c, Estresses e, int src);