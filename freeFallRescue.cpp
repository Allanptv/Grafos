/* @Author: Allan Vivekananda
 * @Version: 1.0
 * */

#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int timer; //Variável Global
#define MAXTAM 10000

double* criaVetorVertices(int n){
	double* vet = new double[n];

	for(int i = 0; i < n; i++){
		vet[i] = 999999999.0;
	}
	return vet;
}

/*method that initializes an adjacencies matrix
 * */

void pointVectors(int* x, int* y, int n){
	int i;

	for(i = 0; i < n; i++){
		cin >> x[i];
		cin >> y[i];
	}
}

double distanceBetweenTwoPoints(int x1, int x2, int y1, int y2){
	double distance = 0.0, difference1 = 0.0, difference2 = 0.0;
	
	difference1 = x2-x1;
	difference2 = y2-y1;

	distance = sqrt(pow(difference1,2) + pow(difference2,2)); 	
	return distance;
}

double** adjacenciesMatrixCreate(int n){
	int i = 0, j = 0, k, l;
	double** matrix = new double*[MAXTAM];
	int* x = new int[n];
	int* y = new int[n];
	
	pointVectors(x, y, n);
	
	for(i; i< MAXTAM; i++){
		matrix[i] = new double[MAXTAM];
	}
	for(k = 0; k < n; k++){
		for(l = 0; l < n; l++){
			matrix[k][l] = distanceBetweenTwoPoints(x[k], x[l], y[k], y[l]);
		}
	}
	return matrix;
}

int posMin(double* q, int n){
	double menor = 99999999;
	int  i, pos = 0 ;
	for(i = 0; i < n; i++){
		if((q[i] < menor) && (q[i] != -1)){
			menor = q[i];
			pos = i;
		
		}
	}	
	return pos;
}

void prim(double** matrix, int n){
	int i, u = 0, counter = 0;
	double tamanhoTeia = 0.0;
	
	double* q = criaVetorVertices(n);
	q[0] = -1;
	while(counter < n-1){
		for(i = 0; i < n; i++){
			if((u != i) && (q[i] != -1)){
				if(matrix[u][i] < q[i]){
					q[i] = matrix[u][i];
				}
			}
		}
		u = posMin(q, n);
	       	tamanhoTeia += q[u]; 
		q[u] = -1;
		counter++;	
	}
	tamanhoTeia /= 100;
	cout << fixed << setprecision (2) << tamanhoTeia << endl << endl;
	free(q);
}

void printMatrix(double** matrix, int n){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			cout << matrix[i][j] << " | ";
		}
		cout << "\n";
	}
}

int main(void){
	int qtdCasos = 0;
	cin >> qtdCasos;
	int n;
	int e;
	double** matrix;
	while(qtdCasos > 0){
		n = 0;
		cin >> n;
		matrix = adjacenciesMatrixCreate(n);
//		printMatrix(matrix, n);	
		prim(matrix, n);
		qtdCasos--;
		for(int i = 0; i < n; i++){
			free(matrix[i]);
		}	
		free(matrix);
	}
	return 0;
}

