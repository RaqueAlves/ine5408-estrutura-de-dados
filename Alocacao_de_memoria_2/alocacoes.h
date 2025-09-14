// Copyright [2025] <COLOQUE SEU NOME AQUI...>
#include <string>

class Aluno {
 public:
    Aluno() {}  // construtor
    ~Aluno() {}  // destrutor
    std::string devolveNome() {
        return nome;
    }
    int devolveMatricula() {
        return matricula;
    }
    void escreveNome(std::string nome_) {
        nome = nome_;
    }
    void escreveMatricula(int matricula_) {
        matricula = matricula_;
    }
 private:
    std::string nome;
    int matricula;
};


Aluno *turma_filtra(Aluno t[], int N, int menor_matr) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (t[i].devolveMatricula() >= menor_matr) {
            count++;
        }
    }

    Aluno *tf = new Aluno[count];

    int j = 0;
    for (int i = 0; i < N; i++) {
        if (t[i].devolveMatricula() >= menor_matr) {
            tf[j] = t[i];
            j++;
        }
    }

    return tf;
}


int *turma_conta(Aluno t[], int N) {
    int *c;
    c = new int[26]();

    for (int i = 0; i < N; i++) {   
        std::string nome = t[i].devolveNome();
        char primeira = nome[0];

        if (primeira >= 'A' && primeira <= 'Z') {
            int x = primeira - 'A';
            c[x]++;
        }
    }
    return c;
}


Aluno **grupos_por_iniciais(Aluno t[], int N) {
    Aluno **g;
    g = new Aluno*[26];  // vetor de ponteiros;
                         // cada posição aponta para um vetor de alunos;
                         // g deve ser alocado com o seguinte:
                         //   g[0] é um ponteiro para alunos com letra 'A'
                         //   g[1] é um ponteiro para alunos com letra 'B'
                         //   ...
                         //   g[25] é um ponteiro para alunos com letra 'Z'

    // DICA: utilize a função 'turma_conta' (implementada no execício 5) para
    //       definir o tamanho de cada um dos 26 vetores
    // int *c = turma_conta(t, N);

    // COLOQUE SEU CÓDIGO AQUI ...

    int *c = turma_conta(t, N);

    for (int i = 0; i < 26; i++) {
        g[i] = new Aluno[c[i]];
    }

    int pos[26] = {0};

    for (int i = 0; i < N; i++) {
        char inicial = t[i].devolveNome()[0];
        if (inicial >= 'A' && inicial <= 'Z') {
            int idx = inicial - 'A';
            g[idx][pos[idx]] = t[i];
            pos[idx]++;
        } 
    }

    delete[] c;

    return g;
}



/*
    *** Importante ***

    A função 'main()' não deve ser escrita aqui, pois é parte do código dos testes e já está implementada

*/