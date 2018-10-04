#include <vector>
#include "construction.h"

void DFS_post(Grafo& grafo, int start, void foo(int));
void DFS_post_util(Grafo& grafo, int atual, vector<bool>& visited, void foo(int));