/* @Author: Allan Vivekananaa
 * @Version: 1.0
 * */

/* Method that initializes an adjacencies matrix
 * */

#include <iostream>
#include <iomanip>
using namespace std;

int timer;  //Variável Global


int* criaVetorVertices(int n){
	int* vetorVertice = new int[n];
	
	for(int i = 0; i < n; i++){	// Cada vertice do grafo é inicializado
		vetorVertice[i] = 0;	// com cor branca "0";
	}// end for	
	return vetorVertice;
}// end criaVetorVertices

void fillColors(int* colors, int n, int k){
	int x = 0;

	for(int i = 0; i < n; i++){
		cin >> x;			//O vetor é preenchido com as cores dos
	       	if(x <= k){			//vertices em ordem de inserçao. Se o
	       		colors[i] = x;		//numero da cor for maior do que a 
	       	}else{				//quantidade de cores, é lido novamente
			cin >> x;
		}//end else	
	}//end for
}//end fillColors

int** adjacenciesMatrixCreate(int n){ //N é a quantidade de vertices do grafo
	int i = 0, j = 0;			//Aqui são criadas n linhas da matrix
	int** matrix = new int*[n]; 		//

	for(i; i < n; i++){			//Este for cria a partir das n linhas
		matrix[i] = new int[n];		//criadas, n colunas, tendo no final
	}//end for				//uma matrix completa

	for(i = 0; i < n; i++){			//Este for inicializa todas as posições
		for(j = 0; j < n; j++){		//da matrix com 0
			matrix[i][j] = 0;	
		}//end for j
	}//end for i
	return matrix;
}//end adjacenciesMatrixCreate

void fillMatrix(int** matrix, int n, int m){
	int v1, v2;
	while(m > 0){
		cin >> v1;
		cin >> v2;
	
		matrix[v1 - 1][v2 - 1] = 1;
		matrix[v2 - 1][v1 - 1] = 1;
	
		m--;
	}
}

bool matrixIsChanged(int** matrix, int* colors, int n, int p){
	bool isChanged = false;

	int counter = 0;

	while(p > 0){

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(colors[i] != colors[j]){
					if(matrix[i][j] == 0){
						counter++;
						matrix[i][j] = 1;
						i = j = n;
					}
				}
			}
		}
		p--;
	}

	if(counter == 0){
		isChanged = false;
	}else{
		isChanged = true;
	}

	return isChanged;

}

void printMatrix(int ** matrix, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << matrix[i][j] << " | ";
		}
		cout << "\n";
	}
}

/*void DFSVISIT(int** matrix, int u, int n, int* vetorVertices, int* aux){
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
	free(d);
	free(f);
}

int DFS(int** matrix, int n){
	int* vetorVertices = criaVetorVertices(n);	
	int counter = 0;
	timer = 0;

	for(int i = 0; i < n; i++){
		if(vetorVertices[i] == 0){
			int* aux = criaVetorVertices(n);
			DFSVISIT(matrix, i, n, vetorVertices, aux);
			counter++;
		}// end if
	}// end for
	free(vetorVertices);
	return counter;
}// end method*/


int main(void){
	int qtdCasos = 0, counter = 0;
	int* colors;
	bool isChanged = false;
	
	cin >> qtdCasos;
		
	int n = 0, m = 0, p = 0, k = 0;
	int** matrix;
	while(qtdCasos > 0){
		cin >> n;
		cin >> m;
		cin >> p;
		cin >> k;
		
		matrix = adjacenciesMatrixCreate(n);
		colors = criaVetorVertices(n);
		fillColors(colors, n, k);
		fillMatrix(matrix, n, m);
		
		isChanged = matrixIsChanged(matrix, colors, n, p);

		if(isChanged == false){
			cout << "N" << endl << endl;
		}else{
			counter	= DFS(matrix, n);
			if(counter > 1){
				cout << "N" << endl << endl;
			}else{
				cout << "Y" << endl << endl;
			}
		}

		//printMatrix(matrix, n);
		
		
		qtdCasos--;
		for(int i = 0; i < n; i++){
			free(matrix[i]);
		}
		free(matrix);
		matrix = NULL;	
	}
	return 0;
}

