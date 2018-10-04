#include <vector>
#include <deque>
#include "construction.h"

using namespace std;

deque<int> ordenacaoTopologica(Grafo& grafo);
// void ordenacaoTopologica(Grafo& grafo, deque<int>& ordTop);

vector<int> getRoots(Grafo& grafo); // pega todos os vertices que são referenciados por nenhum outro vértice