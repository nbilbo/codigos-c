#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

void reverse(char string[]){
  //tamanho da string
  int len = strlen(string);
  //variavel auxiliar
  char aux;
  //trocando os caracteres de lugar
  for(int i = 0; i < len / 2; i++){
    aux = string[i];
    string[i] = string[len - 1 - i];
    string[len - 1 - i] = aux;
  }
}

void left_strip(char string[] ){
  //alocando memoria
  char* aux = malloc(sizeof(char) * strlen(string));
  int quant = 0;
  //atualizando aux
  strcpy(aux, string);
  //removendo os espacos
  for(;*aux == ' ';aux++, quant++);
  //atualizando string
  strcpy(string, aux);
  //liberando memoria
  for(;quant > 0; quant--, aux--);
  free(aux);
}

void right_strip(char string[]){
  reverse(string);
  left_strip(string);
  reverse(string);
}

void strip(char string[]){
  //removendo os espacos da esquerda
  left_strip(string);
  //removendo os espacos da direita
  right_strip(string);
}

int main(void)
{
  char string[] = "  hello world     ";
  strip(string);
  printf("%s", string);
	return 0;
}
