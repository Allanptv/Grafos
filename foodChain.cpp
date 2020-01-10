/* @Author: Allan Vivekananda
 * @Version: 1.0
 * */

#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int timer;

#define MAXTAM 100000
#define INFINITER 9999999
int* criaVetorVerticesCor(int n){
	int* vetorVertice = new int[n];
	
	for(int i = 0; i < n; i++){
		vetorVertice[i] = 0;	// Cada vertice do grafo é inicializado com cor branca "0";
	}	
	return vetorVertice;
}
int* criaVetorVertices(int n){
	int* vet = new int[n];

	for(int i = 0; i < n; i++){
		vet[i] = INFINITER;
	}
	return vet;
}

int** adjacenciesMatrixCreate(int n){
	int i = 0, j = 0, k, l;
	int** matrix = new int*[n];
	
	for(i; i < n; i++){
		matrix[i] = new int[n];
	}

	for(k; k < n; k++){
		for(l; l < n; l++){
			matrix[k][l] = 0;
		}
	}
	return matrix;
}

void fillMatrix(int** matrix, int** matrixT, int n, int m){
	int v1, v2;
	while(m > 0){
		cin >> v1;
		cin >> v2;

		matrix[v1 - 1][v2 - 1] = 1;
		matrixT[v2 - 1][v1 -1] = 1;
		m--;
	}
}

int posMin(int* d, int n){
	int menor = INFINITER;
	int i, pos = 0;

	for(i = 0; i < n; i++){
		if((d[i] < menor) && (d[i] != -1)){
			menor = d[i];
			pos = i;
		}
	}
	return pos;
}

void DFSVISIT(int** matrix, int u, int n, int* vetorVertices, int* aux){
	//char vertice = ' ';
	int* d = new int[10000000];
	int* f = new int[10000000];

	vetorVertices[u] = 1;
	aux[u] = 1;
	//vertice = (char)(u + 97);
	//cout << vertice << ",";
	timer++;
	d[u] = timer;

	for(int j = 0; j < n; j++){
		if((matrix[u][j] == 1) && (vetorVertices[j] == 0)){
			DFSVISIT(matrix, j, n, vetorVertices, aux);
		}
	}
	vetorVertices[u] = 2;
	f[u] = ++timer;
	aux[u] = f[u];
	//cout << f[u];
	free(d);
	free(f);
}

int* DFS(int** matrix, int n){
	int* vetorVertices = criaVetorVerticesCor(n);	
	int* vetorVertices2 = criaVetorVerticesCor(n);	
	int counter = 0;
	timer = 0;

	for(int i = 0; i < n; i++){
		if(vetorVertices[i] == 0){
			int* aux = criaVetorVerticesCor(n);
			DFSVISIT(matrix, i, n, vetorVertices, aux);
			//for(int j=0;j<n;j++){
				//if(aux[j] != 0)
				//	cout << (char) (j+97) << ',';
			//	cout << aux[j]  << ',';
			//}
			vetorVertices2 = aux;
			//cout << "\n";
			counter++;
		}// end if
	}// end for
	//cout << counter << " connected components" << "\n\n";
	free(vetorVertices);
	return vetorVertices2;
}// end method

void printMatrix(int** matrix, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << matrix[i][j] << " | ";
		}
		cout << endl;
	}
}

int main(void){
	int n = 0, m = 0;
	int* v1 = criaVetorVerticesCor(n);
	int* v2 = criaVetorVerticesCor(n);
	int** matrix;
	int** matrixT;
	bool bolado1, bolado2;
	bolado1 = bolado2 = false;

	cin >> n;
	cin >> m;

	matrix = adjacenciesMatrixCreate(n);
	matrixT = adjacenciesMatrixCreate(n);	

	fillMatrix(matrix, matrixT, n, m);
	
	/*printMatrix(matrix, n);
		cout << endl;
	printMatrix(matrixT, n);
		cout << endl;
	*/

	v1 = DFS(matrix, n);
	//cout << endl;
	v2 = DFS(matrixT, n);

	for(int i = 0; i < n; i++){
		if(v1[i] != 0){
			bolado1 = true;
			//cout << "Bolada" << endl;
		}else{
			bolado1 = false;
			break;
		}
	}
	
	for(int i = 0; i < n; i++){
		if(v2[i] != 0){
			bolado2 = true;
			//cout << "Bolada" << endl;
		}else{
			bolado2 = false;
			break;
		}
	}

	if(bolado1 || bolado2){
		cout << "Bolada" << endl;
	}else{
		cout << "Nao Bolada" << endl;
	}



	return 0;
}

