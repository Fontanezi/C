#include <stdio.h>

int main()
{
    int x = 7;
    int y = 13;
    int *z = &x;
    printf("x: %i   y: %i   z: %p\n", x, y, z);
    printf("&x: %p   &y: %p   &z: %p\n", &x, &y, &z);
    *z = x + y;
    printf("Novo valor de x: %i\n", x);
    return 0;
}

// SAÍDA
/*x: 7  y: 13  z: 00x000001
  &x: 00x000001  &y: 01x00100  &z: 11x0111010
  Novo valor de x: 20 */