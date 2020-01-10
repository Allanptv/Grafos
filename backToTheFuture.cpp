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
		vetorVertice[i] = -1;	// Cada vertice do grafo é inicializado com cor branca "0";
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

void fillMatrix(int** matrix, int n, int m){
	int v1, v2, v3;
	while(m > 0){
		cin >> v1;
		cin >> v2;
		cin >> v3;

		matrix[v1 - 1][v2 - 1] = v3;
		matrix[v2 - 1][v1 -1] = v3;
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
	
int getCaminho(int** matrix, int v, int* k){
	int resultado = 0;

	while(k[v] != -1){
		resultado += matrix[v][k[v]];
		matrix[v][k[v]] = 0;
		matrix[k[v]][v] = 0;
		v = k[v];
	}
	if(v == 0){
		return resultado;
	}else{
		return -1;
	}
}

int DIJKSTRA(int** matrix, int n){
	int* k = criaVetorVerticesCor(n);
	int* d = criaVetorVertices(n);
	int u = 0, counter = 0;

	d[0] = -1;

	while(counter < n-1){
		for(int i = 0; i < n; i++){
			if(matrix[u][i] != 0){
				if(d[i] > (d[u] + matrix[u][i])){
					d[i] = d[u] + matrix[u][i];
					k[i] = u ;
				//cout << k[i] << " | " ;
				} 
			}
		}
		//cout << endl;
		u = posMin(d,n);
		d[u] = -1;
		counter++;
	}
	/*for(int j = 0; j < n; j++){
		cout << k[j] << " | ";
	}*/
	
	return getCaminho(matrix, n-1, k);
}

void printMatrix(int** matrix, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << matrix[i][j] << " | ";
		}
		cout << endl;
	}
}

int main(void){
	int n = 0, m = 0, d = 0, l = 0, counter = 1, res, ans;
	int** matrix;
	
	while(counter < 4){
		res = 0;
		ans = 0;
		cin >> n;
		cin >> m;

		matrix = adjacenciesMatrixCreate(n);

		fillMatrix(matrix, n, m);
	
		//printMatrix(matrix, n);
	/*	cout << endl;
	printMatrix(matrixT, n);
		cout << endl;
	*/
	
		cin >> d;
		cin >> l;

		do{
			if(l > d){
				res = DIJKSTRA(matrix, n);
				if(res != -1){
					ans += d*res;
				}else{
					break;
				}
			}else{
				res = DIJKSTRA(matrix, n);
				if(res != -1){
					ans += l*res;
				}else{
					break;
				}
			}
			d -= l; 
		}while(d>0);
			
		cout << "Instancia " << counter << endl << endl;
		if(res != -1){
			cout << ans << endl << endl << endl << endl;
		}else{
			cout << "impossivel" << endl << endl << endl << endl;
		}
		counter++;	
	}
	

	return 0;
}
