#include <stdio.h>
#include <stdlib.h>

void clear_buffer(void){
	char ch;

	while( (ch=getchar()) != '\n' && ch != EOF ){}
}
