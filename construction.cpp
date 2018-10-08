// Projeto 1 de Teoria e Aplicação de Grafos, Turma A
// Prof.: Díbio
// Autores: Rafael Gonçalves de Paulo (17/0043959)
//          João Lucas Azevedo Yamin Rodrigues da Cunha (17/0013731)
// construction.cpp: Arquivo de implementação das funções necessárias para construção do grafo

#include <string>
#include <vector>
#include <regex>
#include <fstream>
#include <iostream>
#include "construction.h"

using namespace std;

// createGrafo: A partir do nome do arquivo, chama as funções para criação do grafo.
vector<vector<int> > createGrafo (const string& fileName, Nomes names, Creditos credits, Estresses stress) {
    fstream arquivo(fileName);

    int _size = grafoSize(arquivo); 

    Grafo g;
	cout << "tamanho " << _size << "\n";
    
    makeNodes(_size, g);
    makeEdges(arquivo, g);

	cout << "terminou 0\n";
    fstream file(fileName);
	cout << "terminou 1\n";
    setupInfo(file, names, credits, stress);
	cout << "terminou 3\n";
    return g;
}

// grafoSize: A partir do arquivo, procura onde "node" é citado para retornar número de vértices. 
size_t grafoSize (fstream& fileStream) {

	string buffer;
	size_t size = 0;

	if (fileStream.is_open()) {
		while (getline (fileStream, buffer)) {
			if (buffer.find("node") != string::npos)
				size++;
			else if (buffer.find("edge") != string::npos)
				break;
		}
	}
	else {
		throw "Erro ao ler o arquivo!";
	}
	return size;
}

// makeNodes: Adiciona, a cada índice do vetor principal (que armazena os vértices), um vetor
// vazio para armazenar as adjacências.
void makeNodes (size_t size, vector<vector<int> >& grafo) {
	for (size_t i = 0; i < size; i++) {
		grafo.push_back(vector<int>());
	}
}

// connectEdge: a partir do vetor principal do grafo e de dois vértices, adiciona às listas 
// de adjacência de um o vértice do outro.
void connectEdge (vector<vector<int> >& grafo, int v1, int v2) {

	if ((unsigned int) v1 >= grafo.size() || (unsigned int) v2 >= grafo.size())
		throw "Este vertice nao existe"; //caso o vértice não exista

	grafo[v1].push_back(v2);

}

// makeEdges: utilizando o arquivo e a função connectEdge, essa função lê o arquivo e identifica
// as palavras 'source' e 'edge' para definir os vizinhos de cada vértice.
void makeEdges (fstream& fileStream, vector<vector<int> >& grafo) {

	if (!fileStream.is_open())
		throw "Erro ao ler o arquivo";

	string buffer;
	while (getline(fileStream, buffer)) {
		if (buffer.find("source") != string::npos) {
			int v1 = 0, v2 = -25;

            sscanf(buffer.c_str(), "    source %d", &v1);
            getline(fileStream, buffer);
            sscanf(buffer.c_str(), "    target %d", &v2);

            // -1 porque o arquivo trabalha com indices começando em 1
            // e o nosso código trabalha com indices começando em 0
            connectEdge(grafo, v1 - 1, v2 - 1);
		}
	}
}

Creditos getCredit (const string& fileName) {
	fstream fileStream(fileName);
	if (!fileStream.is_open())
		throw "Erro ao ler o arquivo";

	Creditos cred;
	string buffer;
	while (getline(fileStream, buffer)) {
		if (buffer.find("creditos") != string::npos) {
			int   credit;
			sscanf(buffer.c_str(), "    creditos %d", &credit);
			cred.push_back(credit);
		}

		if (buffer.find("edge") != string::npos)
			break;
	}

	return cred;
}

Estresses getStress (const string& fileName){
	fstream fileStream(fileName);
	if (!fileStream.is_open())
		throw "Erro ao ler o arquivo";

	Estresses stress;
	string buffer;
	while (getline(fileStream, buffer)) {
		if (buffer.find("dificuldade") != string::npos) {
			float dif;
			sscanf(buffer.c_str(), "    dificuldade %f", &dif);
			stress.push_back(dif);
		}

		if (buffer.find("edge") != string::npos)
			break;
	}

	return stress;
}

// monta os vetores com informações sobre as matérias
void setupInfo (fstream& fileStream, vector<string>& names, vector<int>& credits, vector<float>& stress) {
	if (!fileStream.is_open()){
		throw "Erro ao ler o arquivo";
	}

	string buffer;
	while (getline(fileStream, buffer)) {
		if (buffer.find("nome") != string::npos) {
			int   credit = 0;
			char  name [40];
			string name_str;
			float estresse = 0;

			sscanf(buffer.c_str(), "    nome %s", name);
			getline(fileStream, buffer);
			sscanf(buffer.c_str(), "    creditos %d", &credit);
			getline(fileStream, buffer);
			sscanf(buffer.c_str(), "    dificuldade %f", &estresse);

			name_str.insert(0, name);
			names.push_back(name_str);
			credits.push_back(credit);
			stress.push_back(estresse);
		}

		if (buffer.find("edge") != string::npos) {
      		
			  cout << "terminou 2\n";
			  return;
    	}
	}
}