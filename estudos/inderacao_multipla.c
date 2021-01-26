/*
Um ponteiro apontando para outro ponteiro que aponta
para o valor final
*/

#include <stdio.h>

int main(void)
{
    int x, *p, **q;
    
    x = 10;
    p = &x;
    q = &p;
    printf("%d \n", **q); // imprime o valor de x    

    return 0;
}
