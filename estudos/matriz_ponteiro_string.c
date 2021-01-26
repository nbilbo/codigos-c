/*
Matriz de ponteiros normalmente são usados como ponteiros para strings.
Uma função que exibe uma mensagem de rror, quando é dado seu número
de código.
*/

#include <stdio.h>

void erro(int cod)
{
    char *errors[] = {
        "Arquivo não pode ser aberto\n",
        "Erro de leitura\n",
        "Erro de escrita\n"
    };

    puts(errors[cod]);
}

int main(void)
{
    erro(0);
    erro(1);
    erro(2); 

    return 0;
}
