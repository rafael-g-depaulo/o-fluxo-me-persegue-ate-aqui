// Projeto 2 de Teoria e Aplicação de Grafos, Turma A
// Prof.: Díbio
// Autores: Rafael Gonçalves de Paulo (17/0043959)
//          João Lucas Azevedo Yamin Rodrigues da Cunha (17/0013731)
// construction.h: Declaração de funções necessárias para a montagem do grafo e seus vetores auxiliares

#include <string>
#include <vector>
#include <fstream>

using namespace std;

typedef vector<vector<int> > Grafo;
typedef vector<string> Nomes;
typedef vector<int> Creditos;
typedef vector<float> Estresses;

// createGrafo: A partir do nome do arquivo, chama as funções para criação do grafo.
vector<vector<int> > createGrafo (const string& fileName);

// grafoSize: A partir do arquivo, procura onde "node" é citado para retornar número de vértices. 
size_t grafoSize (fstream& fileStream);

// makeNodes: Adiciona, a cada índice do vetor principal (que armazena os vértices), um vetor
// vazio para armazenar as adjacências.
void makeNodes (size_t size, vector<vector<int> >& grafo);

// monta os vetores com informações sobre as matérias
// setupNames: através do arquivo, cria e retorna um vetor constando todos os nomes lidos no arquivo 
vector<string> setupNames (fstream& fileStream);

// setupCredits: através do arquivo, cria e retorna um vetor constando todos os créditos lidos no arquivo 
vector<int> setupCredits (fstream& fileStream);

// setupStress: através do arquivo, cria e retorna um vetor constando todos as dificuldades lidas no arquivo 
vector<float> setupStress (fstream& fileStream);

// connectEdge: a partir do vetor principal do grafo e de dois vértices, adiciona às listas 
// de adjacência de um o vértice do outro.
void connectEdge (vector<vector<int> >& grafo, int v1, int v2);

// makeEdges: utilizando o arquivo e a função connectEdge, essa função lê o arquivo e identifica
// as palavras 'source' e 'edge' para definir os vizinhos de cada vértice.
void makeEdges (fstream& fileStream, vector<vector<int> >& grafo);