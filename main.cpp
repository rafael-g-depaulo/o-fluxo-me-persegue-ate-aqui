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


	Nomes names;
	Creditos credits;
	Estresses stress;
	fstream arquivo1("grafo.txt");
	fstream arquivo2("grafo.txt");
	fstream arquivo3("grafo.txt");

	Grafo fluxo = createGrafo ("grafo.txt");
	names = setupNames(arquivo1);
	credits = setupCredits(arquivo2);
	stress = setupStress(arquivo3);

	deque<int> ordenado = ordenacaoTopologica(fluxo);
	deque<int> caminho  = criticalPath(fluxo, credits, stress, 0);

	cout << endl << "Fluxo de matérias: " << endl << endl;
	for (unsigned int i = 0; i < fluxo.size(); i++) {
		cout << i << ": " << names[i] << ". Adjacências: ";
		if (fluxo[i].size() == 0) {
				cout << "--";
		} else {
			for (auto v : fluxo[i]){
				cout << v << "; ";
			}
		} 
		
		cout << endl;
	}
	
	cout << endl << "Ordenação topológica: " << endl;
	int j = 0;
	for (auto v : ordenado) {
		j++;
		cout << j << ": " << v << " - " << names[v] << endl;
	}
	j = 0;
	cout << endl << "Caminho crítico: " << endl;
	for (auto v : caminho) {
		j++;
		cout << j << ": " << v << " - " << names[v] << endl;
	}

	return 0;

}