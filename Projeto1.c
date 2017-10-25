#include<stdlib.h>
#include<stdio.h>

// Sudoku utilizando busca em profundidade. Busca não-informada
void estado_inicial(int (*Matriz)[9]){

	
	// Considerado fácil, exemplo professor
	/*
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
	*/
	/*
	// Considerado fácil, exemplo professor
	Matriz[0][0] = 0;
	Matriz[0][1] = 0;
	Matriz[0][2] = 0;
	Matriz[0][3] = 2;
	Matriz[0][4] = 6;
	Matriz[0][5] = 0;
	Matriz[0][6] = 7;
	Matriz[0][7] = 0;
	Matriz[0][8] = 1;

	Matriz[1][0] = 6;
	Matriz[1][1] = 8;
	Matriz[1][2] = 0;
	Matriz[1][3] = 0;
	Matriz[1][4] = 7;
	Matriz[1][5] = 0;
	Matriz[1][6] = 0;
	Matriz[1][7] = 9;
	Matriz[1][8] = 0;

	Matriz[2][0] = 1;
	Matriz[2][1] = 9;
	Matriz[2][2] = 0;
	Matriz[2][3] = 0;
	Matriz[2][4] = 0;
	Matriz[2][5] = 4;
	Matriz[2][6] = 5;
	Matriz[2][7] = 0;
	Matriz[2][8] = 0;

	Matriz[3][0] = 8;
	Matriz[3][1] = 2;
	Matriz[3][2] = 0;
	Matriz[3][3] = 1;
	Matriz[3][4] = 0;
	Matriz[3][5] = 0;
	Matriz[3][6] = 0;
	Matriz[3][7] = 4;
	Matriz[3][8] = 0;

	Matriz[4][0] = 0;
	Matriz[4][1] = 0;
	Matriz[4][2] = 4;
	Matriz[4][3] = 6;
	Matriz[4][4] = 0;
	Matriz[4][5] = 2;
	Matriz[4][6] = 9;
	Matriz[4][7] = 0;
	Matriz[4][8] = 0;

	Matriz[5][0] = 0;
	Matriz[5][1] = 5;
	Matriz[5][2] = 0;
	Matriz[5][3] = 0;
	Matriz[5][4] = 0;
	Matriz[5][5] = 3;
	Matriz[5][6] = 0;
	Matriz[5][7] = 2;
	Matriz[5][8] = 8;

	Matriz[6][0] = 0;
	Matriz[6][1] = 0;
	Matriz[6][2] = 9;
	Matriz[6][3] = 3;
	Matriz[6][4] = 0;
	Matriz[6][5] = 0;
	Matriz[6][6] = 0;
	Matriz[6][7] = 7;
	Matriz[6][8] = 4;

	Matriz[7][0] = 0;
	Matriz[7][1] = 4;
	Matriz[7][2] = 0;
	Matriz[7][3] = 0;
	Matriz[7][4] = 5;
	Matriz[7][5] = 0;
	Matriz[7][6] = 0;
	Matriz[7][7] = 3;
	Matriz[7][8] = 6;

	Matriz[8][0] = 7;
	Matriz[8][1] = 0;
	Matriz[8][2] = 3;
	Matriz[8][3] = 0;
	Matriz[8][4] = 1;
	Matriz[8][5] = 8;
	Matriz[8][6] = 0;
	Matriz[8][7] = 0;
	Matriz[8][8] = 0;
	*/
	/*
	// Considerado intermediário, exemplo professor
	Matriz[0][0] = 0;
	Matriz[0][1] = 2;
	Matriz[0][2] = 0;
	Matriz[0][3] = 6;
	Matriz[0][4] = 0;
	Matriz[0][5] = 8;
	Matriz[0][6] = 0;
	Matriz[0][7] = 0;
	Matriz[0][8] = 0;

	Matriz[1][0] = 5;
	Matriz[1][1] = 8;
	Matriz[1][2] = 0;
	Matriz[1][3] = 0;
	Matriz[1][4] = 0;
	Matriz[1][5] = 9;
	Matriz[1][6] = 7;
	Matriz[1][7] = 0;
	Matriz[1][8] = 0;

	Matriz[2][0] = 0;
	Matriz[2][1] = 0;
	Matriz[2][2] = 0;
	Matriz[2][3] = 0;
	Matriz[2][4] = 4;
	Matriz[2][5] = 0;
	Matriz[2][6] = 0;
	Matriz[2][7] = 0;
	Matriz[2][8] = 0;

	Matriz[3][0] = 3;
	Matriz[3][1] = 7;
	Matriz[3][2] = 0;
	Matriz[3][3] = 0;
	Matriz[3][4] = 0;
	Matriz[3][5] = 0;
	Matriz[3][6] = 5;
	Matriz[3][7] = 0;
	Matriz[3][8] = 0;

	Matriz[4][0] = 6;
	Matriz[4][1] = 0;
	Matriz[4][2] = 0;
	Matriz[4][3] = 0;
	Matriz[4][4] = 0;
	Matriz[4][5] = 0;
	Matriz[4][6] = 0;
	Matriz[4][7] = 0;
	Matriz[4][8] = 4;

	Matriz[5][0] = 0;
	Matriz[5][1] = 0;
	Matriz[5][2] = 8;
	Matriz[5][3] = 0;
	Matriz[5][4] = 0;
	Matriz[5][5] = 0;
	Matriz[5][6] = 0;
	Matriz[5][7] = 1;
	Matriz[5][8] = 3;

	Matriz[6][0] = 0;
	Matriz[6][1] = 0;
	Matriz[6][2] = 0;
	Matriz[6][3] = 0;
	Matriz[6][4] = 2;
	Matriz[6][5] = 0;
	Matriz[6][6] = 0;
	Matriz[6][7] = 0;
	Matriz[6][8] = 0;

	Matriz[7][0] = 0;
	Matriz[7][1] = 0;
	Matriz[7][2] = 9;
	Matriz[7][3] = 8;
	Matriz[7][4] = 0;
	Matriz[7][5] = 0;
	Matriz[7][6] = 0;
	Matriz[7][7] = 3;
	Matriz[7][8] = 6;

	Matriz[8][0] = 0;
	Matriz[8][1] = 0;
	Matriz[8][2] = 0;
	Matriz[8][3] = 3;
	Matriz[8][4] = 0;
	Matriz[8][5] = 6;
	Matriz[8][6] = 0;
	Matriz[8][7] = 9;
	Matriz[8][8] = 0;
	
	/*
	// Considerado intermediário
	Matriz[0][0] = 0;
	Matriz[0][1] = 0;
	Matriz[0][2] = 0;
	Matriz[0][3] = 0;
	Matriz[0][4] = 0;
	Matriz[0][5] = 6;
	Matriz[0][6] = 0;
	Matriz[0][7] = 0;
	Matriz[0][8] = 4;

	Matriz[1][0] = 0;
	Matriz[1][1] = 0;
	Matriz[1][2] = 0;
	Matriz[1][3] = 8;
	Matriz[1][4] = 0;
	Matriz[1][5] = 0;
	Matriz[1][6] = 1;
	Matriz[1][7] = 0;
	Matriz[1][8] = 0;

	Matriz[2][0] = 2;
	Matriz[2][1] = 4;
	Matriz[2][2] = 0;
	Matriz[2][3] = 1;
	Matriz[2][4] = 0;
	Matriz[2][5] = 0;
	Matriz[2][6] = 0;
	Matriz[2][7] = 5;
	Matriz[2][8] = 0;

	Matriz[3][0] = 0;
	Matriz[3][1] = 0;
	Matriz[3][2] = 8;
	Matriz[3][3] = 0;
	Matriz[3][4] = 9;
	Matriz[3][5] = 0;
	Matriz[3][6] = 2;
	Matriz[3][7] = 0;
	Matriz[3][8] = 0;

	Matriz[4][0] = 9;
	Matriz[4][1] = 0;
	Matriz[4][2] = 7;
	Matriz[4][3] = 0;
	Matriz[4][4] = 8;
	Matriz[4][5] = 0;
	Matriz[4][6] = 0;
	Matriz[4][7] = 0;
	Matriz[4][8] = 6;

	Matriz[5][0] = 5;
	Matriz[5][1] = 0;
	Matriz[5][2] = 0;
	Matriz[5][3] = 0;
	Matriz[5][4] = 2;
	Matriz[5][5] = 0;
	Matriz[5][6] = 9;
	Matriz[5][7] = 0;
	Matriz[5][8] = 3;

	Matriz[6][0] = 0;
	Matriz[6][1] = 0;
	Matriz[6][2] = 1;
	Matriz[6][3] = 0;
	Matriz[6][4] = 0;
	Matriz[6][5] = 2;
	Matriz[6][6] = 0;
	Matriz[6][7] = 0;
	Matriz[6][8] = 0;

	Matriz[7][0] = 6;
	Matriz[7][1] = 0;
	Matriz[7][2] = 0;
	Matriz[7][3] = 4;
	Matriz[7][4] = 0;
	Matriz[7][5] = 0;
	Matriz[7][6] = 0;
	Matriz[7][7] = 0;
	Matriz[7][8] = 0;

	Matriz[8][0] = 0;
	Matriz[8][1] = 7;
	Matriz[8][2] = 0;
	Matriz[8][3] = 0;
	Matriz[8][4] = 0;
	Matriz[8][5] = 3;
	Matriz[8][6] = 0;
	Matriz[8][7] = 9;
	Matriz[8][8] = 1;
	*/
	// Considerado dificil, exemplo professor
	/*
	Matriz[0][0] = 0;
	Matriz[0][1] = 0;
	Matriz[0][2] = 0;
	Matriz[0][3] = 6;
	Matriz[0][4] = 0;
	Matriz[0][5] = 0;
	Matriz[0][6] = 4;
	Matriz[0][7] = 0;
	Matriz[0][8] = 0;

	Matriz[1][0] = 7;
	Matriz[1][1] = 0;
	Matriz[1][2] = 0;
	Matriz[1][3] = 0;
	Matriz[1][4] = 0;
	Matriz[1][5] = 3;
	Matriz[1][6] = 6;
	Matriz[1][7] = 0;
	Matriz[1][8] = 0;

	Matriz[2][0] = 0;
	Matriz[2][1] = 0;
	Matriz[2][2] = 0;
	Matriz[2][3] = 0;
	Matriz[2][4] = 9;
	Matriz[2][5] = 1;
	Matriz[2][6] = 0;
	Matriz[2][7] = 8;
	Matriz[2][8] = 0;

	Matriz[3][0] = 0;
	Matriz[3][1] = 0;
	Matriz[3][2] = 0;
	Matriz[3][3] = 0;
	Matriz[3][4] = 0;
	Matriz[3][5] = 0;
	Matriz[3][6] = 0;
	Matriz[3][7] = 0;
	Matriz[3][8] = 0;

	Matriz[4][0] = 0;
	Matriz[4][1] = 5;
	Matriz[4][2] = 0;
	Matriz[4][3] = 1;
	Matriz[4][4] = 8;
	Matriz[4][5] = 0;
	Matriz[4][6] = 0;
	Matriz[4][7] = 0;
	Matriz[4][8] = 3;

	Matriz[5][0] = 0;
	Matriz[5][1] = 0;
	Matriz[5][2] = 0;
	Matriz[5][3] = 3;
	Matriz[5][4] = 0;
	Matriz[5][5] = 6;
	Matriz[5][6] = 0;
	Matriz[5][7] = 4;
	Matriz[5][8] = 5;

	Matriz[6][0] = 0;
	Matriz[6][1] = 4;
	Matriz[6][2] = 0;
	Matriz[6][3] = 2;
	Matriz[6][4] = 0;
	Matriz[6][5] = 0;
	Matriz[6][6] = 0;
	Matriz[6][7] = 6;
	Matriz[6][8] = 0;

	Matriz[7][0] = 9;
	Matriz[7][1] = 0;
	Matriz[7][2] = 3;
	Matriz[7][3] = 0;
	Matriz[7][4] = 0;
	Matriz[7][5] = 0;
	Matriz[7][6] = 0;
	Matriz[7][7] = 0;
	Matriz[7][8] = 0;

	Matriz[8][0] = 0;
	Matriz[8][1] = 2;
	Matriz[8][2] = 0;
	Matriz[8][3] = 0;
	Matriz[8][4] = 0;
	Matriz[8][5] = 0;
	Matriz[8][6] = 1;
	Matriz[8][7] = 0;
	Matriz[8][8] = 0;
	*/
	
	Matriz[0][0] = 0;
	Matriz[0][1] = 0;
	Matriz[0][2] = 0;
	Matriz[0][3] = 0;
	Matriz[0][4] = 0;
	Matriz[0][5] = 2;
	Matriz[0][6] = 0;
	Matriz[0][7] = 0;
	Matriz[0][8] = 8;

	Matriz[1][0] = 0;
	Matriz[1][1] = 0;
	Matriz[1][2] = 0;
	Matriz[1][3] = 6;
	Matriz[1][4] = 5;
	Matriz[1][5] = 0;
	Matriz[1][6] = 0;
	Matriz[1][7] = 1;
	Matriz[1][8] = 9;

	Matriz[2][0] = 0;
	Matriz[2][1] = 0;
	Matriz[2][2] = 0;
	Matriz[2][3] = 1;
	Matriz[2][4] = 0;
	Matriz[2][5] = 0;
	Matriz[2][6] = 6;
	Matriz[2][7] = 0;
	Matriz[2][8] = 5;

	Matriz[3][0] = 1;
	Matriz[3][1] = 0;
	Matriz[3][2] = 0;
	Matriz[3][3] = 7;
	Matriz[3][4] = 0;
	Matriz[3][5] = 3;
	Matriz[3][6] = 0;
	Matriz[3][7] = 8;
	Matriz[3][8] = 0;

	Matriz[4][0] = 0;
	Matriz[4][1] = 4;
	Matriz[4][2] = 0;
	Matriz[4][3] = 0;
	Matriz[4][4] = 6;
	Matriz[4][5] = 0;
	Matriz[4][6] = 1;
	Matriz[4][7] = 9;
	Matriz[4][8] = 0;

	Matriz[5][0] = 8;
	Matriz[5][1] = 0;
	Matriz[5][2] = 7;
	Matriz[5][3] = 0;
	Matriz[5][4] = 2;
	Matriz[5][5] = 0;
	Matriz[5][6] = 0;
	Matriz[5][7] = 0;
	Matriz[5][8] = 6;

	Matriz[6][0] = 9;
	Matriz[6][1] = 3;
	Matriz[6][2] = 0;
	Matriz[6][3] = 0;
	Matriz[6][4] = 7;
	Matriz[6][5] = 6;
	Matriz[6][6] = 0;
	Matriz[6][7] = 0;
	Matriz[6][8] = 0;

	Matriz[7][0] = 0;
	Matriz[7][1] = 8;
	Matriz[7][2] = 0;
	Matriz[7][3] = 2;
	Matriz[7][4] = 0;
	Matriz[7][5] = 0;
	Matriz[7][6] = 0;
	Matriz[7][7] = 0;
	Matriz[7][8] = 0;

	Matriz[8][0] = 0;
	Matriz[8][1] = 1;
	Matriz[8][2] = 2;
	Matriz[8][3] = 0;
	Matriz[8][4] = 0;
	Matriz[8][5] = 9;
	Matriz[8][6] = 0;
	Matriz[8][7] = 0;
	Matriz[8][8] = 0;
	

}

int Verifica_matriz3x3(int (*Matriz)[9], int n, int m){
	int cont = 0;
	int l, c;
	// Quadrado 0x0
	if((n == 0 || n == 1 || n ==2) && (m==0 || m ==1 || m==2)){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(Matriz[n][m] == Matriz[i][j])
					cont++;
				if(cont == 2)
					return 1;
			}
		}
		return 0;
	}

	// Quadrado 0x1
	if((n == 0 || n == 1 || n ==2) && (m==3 || m ==4 || m==5)){
		for(int i=0;i<3;i++){
			for(int j=3;j<6;j++){
				if(Matriz[n][m] == Matriz[i][j])
					cont++;
				if(cont == 2)
					return 1;
			}
		}
		return 0;
	}

	//Quadrado 0x2
	if((n == 0 || n == 1 || n ==2) && (m==6 || m ==7 || m==8)){
		for(int i=0;i<3;i++){
			for(int j=6;j<9;j++){
				if(Matriz[n][m] == Matriz[i][j])
					cont++;
				if(cont == 2)
					return 1;
			}
		}
		return 0;
	}

	// Quadrado 1x0
	if((n == 3 || n == 4 || n ==5) && (m==0 || m ==1 || m==2)){
		for(int i=3;i<6;i++){
			for(int j=0;j<3;j++){
				if(Matriz[n][m] == Matriz[i][j])
					cont++;
				if(cont == 2)
					return 1;
			}
		}
		return 0;
	}

	// Quadrado 1x1
	if((n == 3 || n == 4 || n ==5) && (m==3 || m ==4 || m==5)){
		for(int i=3;i<6;i++){
			for(int j=3;j<6;j++){
				if(Matriz[n][m] == Matriz[i][j])
					cont++;
				if(cont == 2)
					return 1;
			}
		}
		return 0;
	}

	// Quadrado 1x2
	if((n == 3 || n == 4 || n ==5) && (m==6 || m ==7 || m==8)){
		for(int i=3;i<6;i++){
			for(int j=6;j<9;j++){
				if(Matriz[n][m] == Matriz[i][j])
					cont++;
				if(cont == 2)
					return 1;
			}
		}
		return 0;
	}

	// Quadrado 2x0
	if((n == 6 || n == 7 || n ==8) && (m==0 || m ==1 || m==2)){
		for(int i=6;i<9;i++){
			for(int j=0;j<3;j++){
				if(Matriz[n][m] == Matriz[i][j])
					cont++;
				if(cont == 2)
					return 1;
			}
		}
		return 0;
	}

	// Quadrado 2x1
	if((n == 6 || n == 7 || n ==8) && (m==3 || m ==4 || m==5)){
		for(int i=6;i<9;i++){
			for(int j=3;j<6;j++){
				if(Matriz[n][m] == Matriz[i][j])
					cont++;
				if(cont == 2)
					return 1;
			}
		}
		return 0;
	}

	// Quadrado 2x2
	if((n == 6 || n == 7 || n ==8) && (m==6 || m ==7 || m==8)){
		for(int i=6;i<9;i++){
			for(int j=6;j<9;j++){
				if(Matriz[n][m] == Matriz[i][j])
					cont++;
				if(cont == 2)
					return 1;
			}
		}
		return 0;
	}	 
}

// Esta função verifica se já existe o numero na mesma linha ou na mesma coluna.
int Verifica(int (*Matriz)[9],int n, int m){
	int i;
	int cont = 0;
	// Verifica se possui o mesmo numero na linha
	for(i=0;i<9;i++){
		if(Matriz[n][m] == Matriz[n][i])
			cont++;
		if(cont == 2)
			return 1;
	}
	cont = 0;
	// Verifica se possui o mesmo numero na coluna
	for(i=0;i<9;i++){
		if(Matriz[n][m] == Matriz[i][m])
			cont++;
		if(cont == 2)
			return 1;
	}
	int aux = Verifica_matriz3x3(Matriz, n, m);
	return aux;
}

int substitui_rec(int (*vetor)[9]){

	int cont = 1;
	int i, j;
	int aux = 1;
	for(i=0;i<9;i++){
		for(j=0;j<9; j++){
			if(vetor[i][j] == 0){
				while(cont < 10 && (aux ==1)){
					vetor[i][j] = cont;
					printf("i = %d, j = %d. vetor = %d \n", i+1, j+1, vetor[i][j]);
					aux = Verifica(vetor, i, j);
					//Se o número que foi atribuido para aquila posição não for válido, então aux recebe 1. Senão a proxima posição
					// que contem 0 é chamada recursivamente.
					if(aux == 1){
						cont++;
						vetor[i][j] = 0;
					}
					else 
						aux = substitui_rec(vetor);
					// Se for retornado 2 da chamada recursiva, significa que todas as possibilidades da posição eram inválidos
					// então a posição anterior que tinha o 0 é alterada.
					if(aux == 2){
						cont++;
						aux = 1;
						vetor[i][j] = 0;
					}

				}
				// Se aux continua 1, significa que todas as possibilidades foram testadas.
				if(aux == 1)
					return 2;
			}
			cont = 1;
		}
	}
	return 0;

}

int main(){
	int Matriz[9][9];
	estado_inicial(Matriz);
	int aux;
	int i, j;
	aux = substitui_rec(Matriz);
	printf("\n");
	if(aux == 2)
		printf("Não é possivel resolver");
	else
		for(i=0;i<9;i++){
			for(j=0;j<9; j++){
				printf("%d ", Matriz[i][j]);
			}
			printf("\n");
		}
}