#include <vector>
#include <functional>
#include "construction.h"

using namespace std;

void DFS_post(Grafo& grafo, vector<int> start, function<void (int)> foo);
void DFS_post_util(Grafo& grafo, int atual, vector<bool>& visited, function<void (int)> foo);