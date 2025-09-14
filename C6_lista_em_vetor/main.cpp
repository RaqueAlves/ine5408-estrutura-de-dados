#include <iostream>
#include "ArrayList.h"

int main() {
    structures::ArrayList<int> lista(5);  // lista de inteiros com capacidade 5

    // Inserindo elementos
    lista.push_back(10);
    lista.push_back(20);
    lista.push_back(30);

    std::cout << "Lista apos push_back: ";
    for (std::size_t i = 0; i < lista.size(); i++) {
        std::cout << lista[i] << " ";  // usando operator[]
    }
    std::cout << std::endl;

    // Inserindo no início
    lista.push_front(5);
    std::cout << "Lista apos push_front(5): ";
    for (std::size_t i = 0; i < lista.size(); i++) {
        std::cout << lista.at(i) << " ";  // usando at()
    }
    std::cout << std::endl;

    // Inserindo em posição específica
    lista.insert(15, 2);
    std::cout << "Lista apos insert(15, pos 2): ";
    for (std::size_t i = 0; i < lista.size(); i++) {
        std::cout << lista[i] << " ";
    }
    std::cout << std::endl;

    // Inserindo em ordem
    lista.insert_sorted(25);
    std::cout << "Lista apos insert_sorted(25): ";
    for (std::size_t i = 0; i < lista.size(); i++) {
        std::cout << lista[i] << " ";
    }
    std::cout << std::endl;

    // Removendo do fim
    int removido = lista.pop_back();
    std::cout << "Elemento removido do fim: " << removido << std::endl;

    // Removendo do início
    removido = lista.pop_front();
    std::cout << "Elemento removido do inicio: " << removido << std::endl;

    // Removendo posição específica
    removido = lista.pop(1);
    std::cout << "Elemento removido da posicao 1: " << removido << std::endl;

    std::cout << "Lista final: ";
    for (std::size_t i = 0; i < lista.size(); i++) {
        std::cout << lista[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
