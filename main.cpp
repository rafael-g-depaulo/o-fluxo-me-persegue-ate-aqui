// Projeto 2 de Teoria e Aplicação de Grafos, Turma A
// Prof.: Díbio
// Autores: Rafael Gonçalves de Paulo (17/0043959)
//          João Lucas Azevedo Yamin Rodrigues da Cunha (17/0013731)
// main.cpp: Arquivo de execução principal do programa

#include <iostream>
#include <vector>
#include <list>
#include "construction.h"
#include "ordenacao.h"
#include "caminho.h"
#include "dfs.h"

using namespace std;

void a(int v) {
	cout << v << " ";
}

int main(int argc, char** argv) {


	// Nomes names;
	Creditos credits;
	Estresses stress;

	// Grafo karate = createGrafo ("grafo.txt", names, credits, stress);
	Grafo g;
	for (int i = 0; i < 5; i++)
		g.push_back(vector<int>());
	g[0].push_back(1);
	g[0].push_back(2);
	g[1].push_back(3);
	g[2].push_back(4);
	g[3].push_back(4);

	credits.push_back(3);
	credits.push_back(4);
	credits.push_back(6);
	credits.push_back(3);
	credits.push_back(0);

	stress.push_back(1.0);
	stress.push_back(1.0);
	stress.push_back(1.0);
	stress.push_back(1.0);
	stress.push_back(1.0);

	// deque<int> caminho = criticalPath(g, credits, stress, 0);
	credits = getCredit("grafo.txt");
	stress = getStress("grafo.txt");
	
	return 0;

}