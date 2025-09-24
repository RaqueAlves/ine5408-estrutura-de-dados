// Copyright [2025] <Raquel Alves Pinto>

#include <cstdint>

namespace structures {

template<typename T>
class DoublyCircularList {
 public:
    DoublyCircularList();
    ~DoublyCircularList();

    void clear();

    void push_back(const T& data);
    void push_front(const T& data);
    void insert(const T& data, std::size_t index);
    void insert_sorted(const T& data);

    T pop(std::size_t index);
    T pop_back();
    T pop_front();
    void remove(const T& data);

    bool empty() const;
    bool contains(const T& data) const;

    T& at(std::size_t index);
    const T& at(std::size_t index) const;

    std::size_t find(const T& data) const;
    std::size_t size() const;

 private:
    class Node {
     public:
        explicit Node(const T& data):
            data_{data}
        {}
        Node(const T& data, Node* next):
            data_{data}, next_{next} 
        {}

        Node(const T& data, Node* prev, Node* next):
            data_{data}, prev_{prev}, next_{next} 
        {}

        T& data() { return data_; }
        const T& data() const { return data_; }

        Node* prev() { return prev_; }
        const Node* prev() const { return prev_; }
        void prev(Node* node) { prev_ = node; }

        Node* next() { return next_; }
        const Node* next() const { return next_; }
        void next(Node* node) { next_ = node; }

     private:
        T data_;
        Node* prev_;
        Node* next_;
    };

    Node* head;
    std::size_t size_;
};

}  

template<typename T>
structures::DoublyCircularList<T>::DoublyCircularList() {
    head = nullptr;
    size_ = 0;
}

template<typename T>
structures::DoublyCircularList<T>::~DoublyCircularList() {
    clear();
}

template<typename T>
void structures::DoublyCircularList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template<typename T>
bool structures::DoublyCircularList<T>::empty() const {
    return size_ == 0;
}

template<typename T>
std::size_t structures::DoublyCircularList<T>::size() const {
    return size_;
}

template<typename T>
void structures::DoublyCircularList<T>::push_front(const T& data) {
    Node* novo = new Node(data);
    if (empty()) {
        novo->next(novo);
        novo->prev(novo);
        head = novo;
    } else {
        Node* tail = head->prev();
        novo->next(head);
        novo->prev(tail);
        head->prev(novo);
        tail->next(novo);
        head = novo;
    }
    size_++;
}

template<typename T>
void structures::DoublyCircularList<T>::push_back(const T& data) {
    if (empty()) {
        push_front(data);
    } else {
        Node* tail = head->prev();
        Node* novo = new Node(data, tail, head);
        tail->next(novo);
        head->prev(novo);
        size_++;
    }
}

template<typename T>
void structures::DoublyCircularList<T>::insert(const T& data, std::size_t index) {
    if (index > size_) {
        throw std::out_of_range("indice invalido");
    } else if (index == 0) {
        push_front(data);
    } else if (index == size_) {
        push_back(data);
    } else {
        Node* current = head;
        for (std::size_t i = 0; i < index; i++) {
            current = current->next();
        }
        Node* prev = current->prev();
        Node* novo = new Node(data, prev, current);
        prev->next(novo);
        current->prev(novo);
        size_++;
    }
}

template<typename T>
void structures::DoublyCircularList<T>::insert_sorted(const T& data) {
    if (empty() || data <= head->data()) {
        push_front(data);
        return;
    }

    Node* current = head;
    do {
        if (current->data() >= data) break;
        current = current->next();
    } while (current != head);

    if (current == head) {
        push_back(data); // maior que todos
    } else {
        Node* prev = current->prev();
        Node* novo = new Node(data, prev, current);
        prev->next(novo);
        current->prev(novo);
        size_++;
    }
}

template<typename T>
T structures::DoublyCircularList<T>::pop_front() {
    if (empty()) throw std::out_of_range("lista vazia");

    Node* p = head;
    T aux = p->data();

    if (size_ == 1) {
        head = nullptr;
    } else {
        Node* tail = head->prev();
        head = head->next();
        head->prev(tail);
        tail->next(head);
    }

    delete p;
    size_--;
    return aux;
}

template<typename T>
T structures::DoublyCircularList<T>::pop_back() {
    if (empty()) throw std::out_of_range("lista vazia");
    Node* tail = head->prev();
    if (size_ == 1) return pop_front();

    T aux = tail->data();
    Node* prev = tail->prev();
    prev->next(head);
    head->prev(prev);
    delete tail;
    size_--;
    return aux;
}

template<typename T>
T structures::DoublyCircularList<T>::pop(std::size_t index) {
    if (index >= size_) throw std::out_of_range("indice invalido");
    if (index == 0) return pop_front();
    if (index == size_-1) return pop_back();

    Node* current = head;
    for (std::size_t i = 0; i < index; i++) {
        current = current->next();
    }
    Node* prev = current->prev();
    Node* next = current->next();
    prev->next(next);
    next->prev(prev);
    T aux = current->data();
    delete current;
    size_--;
    return aux;
}

template<typename T>
void structures::DoublyCircularList<T>::remove(const T& data) {
    if (empty()) return;

    Node* current = head;
    std::size_t i = 0;
    do {
        if (current->data() == data) {
            pop(i);
            return;
        }
        current = current->next();
        i++;
    } while (current != head);
}

template<typename T>
T& structures::DoublyCircularList<T>::at(std::size_t index) {
    if (index >= size_) throw std::out_of_range("indice invalido");
    Node* current = head;
    for (std::size_t i = 0; i < index; i++) {
        current = current->next();
    }
    return current->data();
}

template<typename T>
const T& structures::DoublyCircularList<T>::at(std::size_t index) const {
    if (index >= size_) throw std::out_of_range("indice invalido");
    Node* current = head;
    for (std::size_t i = 0; i < index; i++) {
        current = current->next();
    }
    return current->data();
}

template<typename T>
bool structures::DoublyCircularList<T>::contains(const T& data) const {
    if (empty()) return false;
    Node* current = head;
    do {
        if (current->data() == data) return true;
        current = current->next();
    } while (current != head);
    return false;
}

template<typename T>
std::size_t structures::DoublyCircularList<T>::find(const T& data) const {
    if (empty()) return size_;
    Node* current = head;
    std::size_t i = 0;
    do {
        if (current->data() == data) return i;
        current = current->next();
        i++;
    } while (current != head);
    return size_;
}