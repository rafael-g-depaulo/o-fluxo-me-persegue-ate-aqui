#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef vector<vector<int> > Grafo;
typedef vector<int> Node;

void BFS(Grafo grafo, function<void (int)> bar) {
    queue<int> aVisitar;
    vector<bool> visitados(grafo.size(), false);

    int vertAtual = 0;

    do {
        for (int vizinho: grafo[vertAtual]) {
            if (!visitados[vizinho]) aVisitar.push(vizinho);
        }

        bar(vertAtual);
            
        visitados[vertAtual] = true;
        vertAtual = aVisitar.front;
        aVisitar.pop();

    } while (!aVisitar.empty());
}