// Copyright [2025] <Raquel Alves Pinto>

#include <string>
#include "C6_lista_em_vetor/ArrayList.h"


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


/*
(1) seleciona alunos de uma lista 'turma_entrada', cujos nomes iniciam com uma determinada 'letra', produzinda uma lista 'turma_saida' como resposta.
Exemplo:
  turma_entrada = [{'Fulano',1010}, {'Beltrano',2020}, {'Fulana',7070}, {'Cicrana':1515}, {'Beltrana',8080}]
  letra = 'F'
  turma_saida = [{'Fulano',1010}, {'Fulana',7070}]
*/

structures::ArrayList<Aluno> selecao_nome(structures::ArrayList<Aluno> &turma_entrada, char letra) {
    structures::ArrayList<Aluno> turma_saida(turma_entrada.size());

    // ... COLOQUE SEU CÓDIGO AQUI ...
    for (std::size_t i = 0; i < turma_entrada.size(); ++i) {
        Aluno aluno = turma_entrada.at(i);
        std::string nome = aluno.devolveNome();
        
        if (!nome.empty() && nome[0] == letra) {
            turma_saida.push_back(aluno);
        }
    }

    return turma_saida;
}

/*
(2) amostra alunos a cada 'k' posições de uma lista 'turma_entrada'.
Exemplo: 
  turma_entrada: [A,B,C,D,E,F,G,H]
  k = 3
  turma_saida: [C,F]
*/

structures::ArrayList<Aluno> selecao_amostra(structures::ArrayList<Aluno> &turma_entrada, int k) {
    structures::ArrayList<Aluno> turma_saida(turma_entrada.size());

    // ... COLOQUE SEU CÓDIGO AQUI ...
    for (std::size_t i = k - 1; i < turma_entrada.size(); i += k) {
        turma_saida.push_back(turma_entrada.at(i));
    }

    return turma_saida;
}