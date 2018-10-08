#include <vector>
#include <deque>
#include <queue>
#include <functional>
#include "construction.h"

using namespace std;

typedef pair<int, vector<int> > Caminho;

deque<int> shortestPathToLeaf(Grafo g, Creditos c, Estresses e, int src);
deque<int> criticalPath(Grafo g, Creditos c, Estresses e, int src);