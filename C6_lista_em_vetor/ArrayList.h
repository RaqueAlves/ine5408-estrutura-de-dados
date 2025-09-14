// Copyright [2025] <Raquel Alves Pinto>
#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>   // std::size_t
#include <stdexcept> // C++ Exceptions

namespace structures {

template<typename T>
//! classe ArrayList
class ArrayList {
 public:
    //! construtor padrão
    ArrayList();
    //! construtor com parâmetro
    explicit ArrayList(std::size_t max_size);
    //! destrutor padrão
    ~ArrayList();

    //! limpa a lista
    void clear();

    //! insere no fim
    void push_back(const T& data);
    //! insere no início
    void push_front(const T& data);
    //! insere em uma posição específica
    void insert(const T& data, std::size_t index);
    //! insere em ordem
    void insert_sorted(const T& data);

    //! retira do fim
    T pop_back();
    //! retira do início
    T pop_front();
    //! retira em uma posição específica
    T pop(std::size_t index);

    //! acesso seguro
    T& at(std::size_t index);
    //! acesso por operador []
    T& operator[](std::size_t index);

    //! retorna tamanho atual
    std::size_t size() const;
    //! retorna capacidade máxima
    std::size_t max_size() const;
    //! verifica se está vazia
    bool empty() const;
    //! verifica se está cheia
    bool full() const;

 private:
    T* contents;
    std::size_t size_;       // tamanho atual da lista
    std::size_t max_size_;   // capacidade máxima
    static const auto DEFAULT_SIZE = 10u;
};

}  // namespace structures

#endif

template<typename T>
structures::ArrayList<T>::ArrayList() {
    max_size_ = DEFAULT_SIZE;
    contents = new T[max_size_];
    size_ = 0;
}

template<typename T>
structures::ArrayList<T>::ArrayList(std::size_t max_size) {
    max_size_ = max_size;
    contents = new T[max_size_];
    size_ = 0;
}

template<typename T>
structures::ArrayList<T>::~ArrayList() {
    delete [] contents;
}

template<typename T>
void structures::ArrayList<T>::clear() {
    size_ = 0;
}

template<typename T>
std::size_t structures::ArrayList<T>::size() const {
    return size_;
}

template<typename T>
std::size_t structures::ArrayList<T>::max_size() const {
    return max_size_;
}

template<typename T>
bool structures::ArrayList<T>::empty() const {
    return size_ == 0;
}

template<typename T>
bool structures::ArrayList<T>::full() const {
    return size_ == max_size_;
}

template<typename T>
void structures::ArrayList<T>::push_back(const T& data) {
    if (full()) {
        throw std::out_of_range("Lista cheia");
    }
    contents[size_] = data;
    size_++;
}

template<typename T>
void structures::ArrayList<T>::push_front(const T& data) {
    if (full()) {
        throw std::out_of_range("Lista cheia");
    }
    for (std::size_t i = size_; i > 0; i--) {
        contents[i] = contents[i-1];
    }
    contents[0] = data;
    size_++;
}

template<typename T>
void structures::ArrayList<T>::insert(const T& data, std::size_t index) {
    if (full()) {
        throw std::out_of_range("Lista cheia");
    }
    if (index > size_) {
        throw std::out_of_range("Índice inválido");
    }
    for (std::size_t i = size_; i > index; i--) {
        contents[i] = contents[i-1];
    }
    contents[index] = data;
    size_++;
}

template<typename T>
void structures::ArrayList<T>::insert_sorted(const T& data) {
    if (full()) {
        throw std::out_of_range("Lista cheia");
    }
    std::size_t pos = 0;
    while (pos < size_ && contents[pos] < data) {
        pos++;
    }
    insert(data, pos);
}

template<typename T>
T structures::ArrayList<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("Lista vazia");
    }
    size_--;
    return contents[size_];
}

template<typename T>
T structures::ArrayList<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("Lista vazia");
    }
    T removed = contents[0];
    for (std::size_t i = 0; i < size_-1; i++) {
        contents[i] = contents[i+1];
    }
    size_--;
    return removed;
}

template<typename T>
T structures::ArrayList<T>::pop(std::size_t index) {
    if (empty()) {
        throw std::out_of_range("Lista vazia");
    }
    if (index >= size_) {
        throw std::out_of_range("Índice inválido");
    }
    T removed = contents[index];
    for (std::size_t i = index; i < size_-1; i++) {
        contents[i] = contents[i+1];
    }
    size_--;
    return removed;
}

template<typename T>
T& structures::ArrayList<T>::at(std::size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Índice inválido");
    }
    return contents[index];
}

template<typename T>
T& structures::ArrayList<T>::operator[](std::size_t index) {
    return contents[index];  // sem checagem
}

template<typename T>
void resize() {
    std::size_t new_max = max_size_ * 2;
    T* new_contents = new T[new_max];
    for (std::size_t i = 0; i < size_; i++) {
        new_contents[i] = contents[i];
    }
    delete[] contents;
    contents = new_contents;
    max_size_ = new_max;
}