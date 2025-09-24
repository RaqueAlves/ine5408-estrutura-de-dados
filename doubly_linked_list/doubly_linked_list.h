// Copyright [2025] <Raquel Alves Pinto>
#ifndef STRUCTURES_DOUBLYLINKEDLIST_H
#define STRUCTURES_DOUBLYLINKEDLIST_H

#include <cstdint>   // std::size_t
#include <stdexcept> // C++ Exceptions

namespace structures {

    template<typename T>
    //classe DoublyLinkedList
    class DoublyLinkedList {
        public:
        //construtor padrão
        DoublyLinkedList();
        //destrutor padrão
        ~DoublyLinkedList();

        //limpa a lista
        void clear();

        //insere no fim
        void push_back(const T& data);
        //insere no início
        void push_front(const T& data);
        //insere em uma posição específica
        void insert(const T& data, std::size_t index);

        //retira do fim
        T pop_back();
        //retira no início
        T pop_front();
        //retira em uma posição específica
        T pop(std::size_t index);

        //acessar um elemento na posição index
        T& at(std::size_t index);
        //acesso por operador []
        T& operator[](std::size_t index);  

        //retorna tamanho atual
        std::size_t size() const;
        //retorna capacidade máxima
        std::size_t max_size() const;
        //verifica se está vazia
        bool empty() const;
        //verifica se está cheia
        bool full() const;
        
        private:
        class Node {
            public:
            explicit Node(const T& data):
                data_{data}
            {}

            Node(const T& data, Node* next):
                data_{data},
                next_{next}
            {}

            T& data() {  // getter: dado
                return data_;
            }

            const T& data() const {  // getter const: dado
                return data_;
            }

            Node* next() {  // getter: próximo
                return next_;
            }

            const Node* next() const {  // getter const: próximo
                return next_;
            }

            void next(Node* node) {  // setter: próximo
                next_ = node;
            }
        
            private:
            T data_;
            Node* next_{nullptr};
            Node* prev_{nullptr};
        };

        Node* posiciona_dupla(std::size_t index) {

        }

        Node* head{nullptr};
        Node* tail{nullptr};
        std::size_t size_{0u};
    };
}

#endif

template <typename T>
structures::DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size_ = 0u;
}

template <typename T>
structures::DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template <typename T>
void structures::DoublyLinkedList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template <typename T>
void structures::DoublyLinkedList<T>::push_back(const T& data) {
    
}

template <typename T>
void structures::DoublyLinkedList<T>::push_front(const T& data) {
    Node* novo;
    novo = new Node(data, head);

    novo ->data_ = data;
    novo ->prev_ = nullptr;
    novo ->next_ = head;

    if (!empty()) {
        head ->prev_ = novo;
    }
    head = novo;

    if (empty()) {
        tail = novo;
    }
    size_++
}

template <typename T>
void structures::DoublyLinkedList<T>::insert(const T& data, std::size_t index) {
    
}

template <typename T>
T structures::DoublyLinkedList<T>::pop_back() {
    
}

template <typename T>
T structures::DoublyLinkedList<T>::pop_front() {
    
}

template <typename T>
T structures::DoublyLinkedList<T>::pop(std::size_t index) {
    
}

template <typename T>
T& structures::DoublyLinkedList<T>::at(std::size_t index) {
    
}

template <typename T>
T& structures::DoublyLinkedList<T>::operator[](std::size_t index) {
    
}

template <typename T>
std::size_t structures::DoublyLinkedList<T>::size() const {
    
}

template <typename T>
std::size_t structures::DoublyLinkedList<T>::max_size() const {
    
}

template <typename T>
bool structures::DoublyLinkedList<T>::empty() const {
    
}

template <typename T>
bool structures::DoublyLinkedList<T>::full() const {
    
}