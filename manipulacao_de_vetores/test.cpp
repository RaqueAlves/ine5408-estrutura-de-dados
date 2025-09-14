#include <iostream>
#include <stdlib.h>
#include "functions.h"

int* soma_colunas(int **mat, int M, int N); // declaração

int main() {
    int M = 3;  // linhas
    int N = 4;  // colunas

    int **mat = new int*[M];
    for (int i = 0; i < M; i++)
        mat[i] = new int[N];

    int dados[3][4] = {
        {10, 30, 10, 40},
        {30, 80, 10, 60},
        {70, 20, 30, 20}
    };

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            mat[i][j] = dados[i][j];

    int *soma = soma_colunas(mat, M, N);

    std::cout << "Soma de cada coluna: ";
    for (int j = 0; j < N; j++)
        std::cout << soma[j] << " ";
    std::cout << std::endl;

    // liberar memória
    delete[] soma;
    for (int i = 0; i < M; i++)
        delete[] mat[i];
    delete[] mat;

    return 0;
}