/* @Author: Allan Vivekananaa
 * @Version: 1.0
 * */

/* Method that initializes an adjacencies matrix
 * */

#include <iostream>
using namespace std;


int timer;


int* criaVetorVertices(int n){			//Este metodo cria o vetor de cores que será usado na busca em profundidade
	int* vetorVertice = new int[n];		//Além de criar o vetor, ele incializa cada uma de suas posições com 0 (cor branca)
						//As cores são '0' - Branca
	for(int i = 0; i < n; i++){		// '1' - Cinza
		vetorVertice[i] = 0;		// '2' - Preta
	}	
	return vetorVertice;
}


int** adjacenciesMatrixCreate(int n){ 		// Este metodo cria a matriz de adjacências nxn//N é a quantidade de vertices do grafo
	int i = 0, j = 0;			// Onde n é a quantidade de vértices do grafo
	int** matrix = new int*[n];		// Cada uma das posições da matriz é iniciada com 0
	for(i; i < n; i++){			// O '0' indica que o não há adjacência entre os vértices
		matrix[i] = new int[n];		// O '1' indica que há uma ligação entre os vértices
	}

	for(i = 0; i < n; i++){	
		for(j = 0; j < n; j++){	
			matrix[i][j] = 0;
		}
	
	}

	
	return matrix;
}



void fillMatrix(int** matrix, int n, int e){
	char v1, v2;					//Este metodo preenche a matriz de adjacências colocando '1'
	while(e > 0){					//na posição em que os vértices são conectados
		cin >> v1;
		cin >> v2;
	
		matrix[v1 - 97][v2 - 97] = 1;
		matrix[v2 - 97][v1 - 97] = 1;
	
		e--;
	}
}

void printMatrix(int ** matrix, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << matrix[i][j] << " | ";
		}
		cout << "\n";
	}
}

void DFSVISIT(int** matrix, int u, int n, int* vetorVertices, int* aux){
	//char vertice = ' ';
	int* d = new int[10000000];
	int* f = new int[10000000];
						//Este método é a segunda parte da busca em profundidade
	vetorVertices[u] = 1;
	aux[u] = 1;
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

void DFS(int** matrix, int n){
	int* vetorVertices = criaVetorVertices(n);	
	int counter = 0;
	timer = 0;

	for(int i = 0; i < n; i++){
		if(vetorVertices[i] == 0){
			int* aux = criaVetorVertices(n);
			DFSVISIT(matrix, i, n, vetorVertices, aux);
			for(int j=0;j<n;j++)
				if(aux[j] == 1)
					cout << (char) (j+97) << ',';
			cout << "\n";
			counter++;
		}// end if
	}// end for
	cout << counter << " connected components" << "\n\n";
	free(vetorVertices);
}// end method


int main(void){
	int qtdGrafos = 0, counter = 1;
	
	cin >> qtdGrafos;
		
	int n;
	int e;
	int** matrix;
	while(qtdGrafos > 0){
		n = 0;
		cin >> n;
		e = 0;
		cin >> e;
		
		matrix = adjacenciesMatrixCreate(n);
		
		fillMatrix(matrix, n, e);
		
		//printMatrix(matrix, n);
		
		cout << "Case #" << counter << ":" << "\n";
		
		DFS(matrix, n);
		
		qtdGrafos--;
		counter++;
		for(int i = 0; i < n; i++){
			free(matrix[i]);
		}
		free(matrix);
		matrix = NULL;	
	}
	
	return 0;
}
