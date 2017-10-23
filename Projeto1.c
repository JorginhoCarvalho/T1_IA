#include<stdlib.h>
#include<stdio.h>

void estado_inicial(int (*Matriz)[9]){

	Matriz[0][0] = 4;
	Matriz[0][1] = 3;
	Matriz[0][2] = 5;
	Matriz[0][3] = 0;
	Matriz[0][4] = 0;
	Matriz[0][5] = 9;
	Matriz[0][6] = 7;
	Matriz[0][7] = 8;
	Matriz[0][8] = 1;

	Matriz[1][0] = 0;
	Matriz[1][1] = 0;
	Matriz[1][2] = 2;
	Matriz[1][3] = 5;
	Matriz[1][4] = 7;
	Matriz[1][5] = 1;
	Matriz[1][6] = 4;
	Matriz[1][7] = 0;
	Matriz[1][8] = 3;

	Matriz[2][0] = 1;
	Matriz[2][1] = 9;
	Matriz[2][2] = 7;
	Matriz[2][3] = 8;
	Matriz[2][4] = 3;
	Matriz[2][5] = 4;
	Matriz[2][6] = 0;
	Matriz[2][7] = 6;
	Matriz[2][8] = 2;

	Matriz[3][0] = 8;
	Matriz[3][1] = 2;
	Matriz[3][2] = 6;
	Matriz[3][3] = 1;
	Matriz[3][4] = 9;
	Matriz[3][5] = 5;
	Matriz[3][6] = 3;
	Matriz[3][7] = 4;
	Matriz[3][8] = 7;

	Matriz[4][0] = 3;
	Matriz[4][1] = 7;
	Matriz[4][2] = 0;
	Matriz[4][3] = 0;
	Matriz[4][4] = 8;
	Matriz[4][5] = 2;
	Matriz[4][6] = 0;
	Matriz[4][7] = 1;
	Matriz[4][8] = 5;

	Matriz[5][0] = 9;
	Matriz[5][1] = 5;
	Matriz[5][2] = 1;
	Matriz[5][3] = 7;
	Matriz[5][4] = 4;
	Matriz[5][5] = 3;
	Matriz[5][6] = 6;
	Matriz[5][7] = 2;
	Matriz[5][8] = 8;

	Matriz[6][0] = 5;
	Matriz[6][1] = 1;
	Matriz[6][2] = 9;
	Matriz[6][3] = 3;
	Matriz[6][4] = 2;
	Matriz[6][5] = 6;
	Matriz[6][6] = 8;
	Matriz[6][7] = 7;
	Matriz[6][8] = 4;

	Matriz[7][0] = 2;
	Matriz[7][1] = 4;
	Matriz[7][2] = 8;
	Matriz[7][3] = 9;
	Matriz[7][4] = 5;
	Matriz[7][5] = 7;
	Matriz[7][6] = 1;
	Matriz[7][7] = 3;
	Matriz[7][8] = 0;

	Matriz[8][0] = 0;
	Matriz[8][1] = 6;
	Matriz[8][2] = 0;
	Matriz[8][3] = 4;
	Matriz[8][4] = 0;
	Matriz[8][5] = 8;
	Matriz[8][6] = 2;
	Matriz[8][7] = 5;
	Matriz[8][8] = 9;

}
// Esta função verifica se já existe o numero na mesma linha ou na mesma coluna.
int Verifica(int (*Matriz)[3], int n, int m){
	int i;
	int cont = 0;
	// Verifica se possui o mesmo numero na linha
	for(i=0;i<3;i++){
		if(Matriz[n][m] == Matriz[n][i])
			cont++;
		if(cont == 2)
			return 1;
	}
	cont = 0;
	// Verifica se possui o mesmo numero na coluna
	for(i=0;i<3;i++){
		if(Matriz[n][m] == Matriz[i][m])
			cont++;
		if(cont == 2)
			return 1;
	}
	return 0;
}
/*
// Verifica se o numero já existe na matriz 3x3
// Variaveis n e m é a posição da matriz que tem o numero 0 e vamos alterar.
// Não está completa
int Verifica_matriz3x3(int (*Matriz)[9], int n, int m){

	int auxn = n +1;
	int auxm = m + 1;
	int l, c;
	if((auxn % 3 == 0) && (auxm % 3 == 0)){
		for(int i=auxn-2;i<=auxn;i++){
			for(int j=auxm-2;j<=auxn;j++){
				if((n != i-1) || (m != j-1) && Matriz[n][m] == Matriz[i-1][j-1]){
					return 0;
				}
			}
		}
	}
	 
}*/

// Função que verifica se o numero pertence sub-matriz 3x3.
/*int pertence(int (*vetor)[3], int n){
	for(int i=0;i<3;i++){
		for(int j=0;j<3; j++){
			if(vetor[i][j] == n){
				return 1;
			}
		}
	}	
	return 0; 
}*/

// Essa função altera o valor na matriz onde está o numero 0.
void substitui(int (*vetor)[3]){
	int cont = 1;
	int i, j;
	int aux = 1;
	for(i=0;i<3;i++){
		for(j=0;j<3; j++){
			if(vetor[i][j] == 0){
				while(cont < 4 && (aux ==1)){
					vetor[i][j] = cont;
					aux = Verifica(vetor, i, j);
					if(aux == 1){
						cont++;
						vetor[i][j] = 0;
					}
				}
			}
			cont = 1;
			aux = 1;
		}
	}
}

int main(){
	int Matriz[9][9];
	//estado_inicial(Matriz);
	int vetor1[3][3] = {{0, 0, 3}, {0, 2, 1}, {1,0,2}};
	int i, j;
	/*|2 1 3|
	  |3 2 1|
	  |1 3 2|
	*/
	substitui(vetor1);
	printf("\n");
	for(i=0;i<3;i++){
		for(j=0;j<3; j++){
			printf("%d", vetor1[i][j]);
		}
		printf("\n");
	}
}