// Copyright [2025] <Raquel Alves Pinto>
#include <string>
#include "C3_fila_em_vetor/array_queue.h"

structures::ArrayQueue<char> editaTexto(std::string texto) {
    structures::ArrayQueue<char> fila(500);

    for (std::size_t i = 0; i < texto.length(); i++) {
        char c = texto[i];

        if (c == '<') {
            fila.dequeue();
        } else if (c == '>') {
            char ultimo = fila.back();
            fila.enqueue(ultimo);
        } else {
            fila.enqueue(c);
        }
    }

    return fila;
}