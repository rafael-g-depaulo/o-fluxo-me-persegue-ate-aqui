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
#include "dfs.h"

using namespace std;

void a(int v) {
	cout << v << " ";
}

int main(int argc, char** argv) {

	Grafo karate = createGrafo ("grafo.txt");

	deque<int> ordTop = ordenacaoTopologica(karate);

	for (auto vert: ordTop) {
		cout << vert << " ";
	}
	cout << "\n";
	
	return 0;

}