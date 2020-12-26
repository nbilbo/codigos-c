/*
 Armazenar em uma matriz notas de alunos.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CLASSES 2
#define GRADE 5

void limpar_buffer(void);
void digitar_notas(int matriz[][GRADE]);
void mostrar_notas(int matriz[][GRADE]);
int digitar_nota(int indice);

int main(void){
	char opc = '\0';
	int notas[CLASSES][GRADE];

	for(;;){
		puts("(D)igitar notas");
		puts("(M)ostrar notas");
		puts("(S)air");
		printf("Opcao:");

		scanf("%c", &opc);
		opc = toupper(opc);
		limpar_buffer();
		
		switch(opc){
			case 'D':
				digitar_notas(notas);
				break;

			case 'M':
				mostrar_notas(notas);
				break;

			case 'S':
				exit(0);
		}
	}

	return 0;
}

void limpar_buffer(void){
	char ch;
	
	while( (ch=getchar()) != '\n' && ch != EOF ) {}
}

void digitar_notas(int matriz[][GRADE]){
	for(register int i=0; i<CLASSES; i++){
		printf("CLASSE %d \n", i+1);
		for(register int j=0; j<GRADE; j++){
			matriz[i][j] = digitar_nota(j+1);
		}
	}
}

void mostrar_notas(int matriz[][GRADE]){
	for(register int i=0; i<CLASSES; i++){
		printf("Notas da classe %d \n", i+1);
		for(register int j=0; j<GRADE; j++){
			printf("Aluno %d: %d \n", j+1, matriz[i][j]);
		}
	}
}

int digitar_nota(int indice){
	int nota;

	printf("Digite a nota do aluno %d: ", indice);
	scanf("%d", &nota);

	return nota;
}
