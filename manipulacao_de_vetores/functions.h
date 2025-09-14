#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct coord {
    int x;
    int y;
};

int minimo(int **mat, int M, int N);
coord coordenada_menor(int **mat, int M, int N);
void minimo_matrizes(int **mat1, int **mat2, int M, int N);
int *diagonal(int **mat, int N);
int *soma_colunas(int **mat, int M, int N);

#endif