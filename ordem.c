#include <stdio.h>
#include <stdbool.h>

int ordem(int v[], int n) {
    bool aumentou = false;
    bool diminuiu = false;

    for (int i = 0; i < n - 1; i++) {
        if (v[i] < v[i + 1]) aumentou = true;
        if (v[i] > v[i + 1]) diminuiu = true;
        if (aumentou && diminuiu) return (0); //SEM ORDEM
    }
    
    if (aumentou) return (1);
    if (diminuiu) return (-1);
    return (9); //CONSTANTE
}

void main() {

}