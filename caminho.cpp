#include <iostream>
#include "caminho.h"

using namespace std;

#define INF 99999999

typedef tuple<int, int, int> Cam;

deque<int> shortestPathToLeaf(Grafo g, Creditos c, Estresses e, int v1) {
    priority_queue<Cam, vector<Cam>, function<bool (Cam, Cam)> >
    caminhos([] (Cam c1, Cam c2) {
        int c1Dist, c2Dist;
        tie (ignore, ignore, c1Dist) = c1;
        tie (ignore, ignore, c2Dist) = c2;
        return c1 > c2;
    });

    queue<pair<int, int> > finished;
    // colocar os adjacentes do vertice inicial na queue
    caminhos.push(make_tuple(v1, v1, 0));

    // bool chegouV2 = false;
    int counter = 10;
    int distProx, distChegada = INF;
    do {
        // pegar o vertice do caminho atualmente mais curto
        int atual, prev, distAtual;
        tie (atual, prev, distAtual) = caminhos.top();
        cout << "..... atual: " << atual << endl;
        // para cada adjacente do vértice atual, adicioná-lo aos caminhos
        for (int v: g[atual]) {
            caminhos.push(make_tuple(v, atual, distAtual +  c[atual] * e[atual]));
            cout << "atual: " << v << " anterior: " << atual << " dist: " << distAtual << "\n";
            // se chegou em uma folha
            if (g[atual].empty()) {
                distChegada = distAtual;
                cout << "querida, cheguei!!!\n";
            }
        }
        finished.push(pair<int, int>(atual, prev));
        caminhos.pop();
        tie (ignore, ignore, distProx) = caminhos.top();
    } while (/* !chegouV2 */distChegada >= distProx && counter-- > 0);
    cout << "\npara\n";
    // agora construir um caminho reverso a partir da queue com as informações dadas
    int vAtualRev;
    deque<int> caminhoMenor;
    while (vAtualRev != v1) {
        int vAt, vPrev;
        tie (vAt, vPrev, ignore) = caminhos.top();
        caminhos.pop();

        // se achou o vertice atual do caminho reverso
        if (vAt == vAtualRev) {
            // coloca o vértice atual no deque do caminho
            caminhoMenor.push_front(vAt);
            // muda o vAtualRev pra ser o próximo vertice no caminho reverso
            vAtualRev = vPrev;
        }
    }

    cout << "caminhos.size: " << caminhos.size() << endl;
    cout << "finished.size: " << finished.size() << endl;
    cout << "caminhoMenor.size: " << caminhoMenor.size() << endl;
    return caminhoMenor;
}