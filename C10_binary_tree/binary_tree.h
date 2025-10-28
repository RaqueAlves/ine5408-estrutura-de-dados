// Copyright [2025] <Raquel Alves Pinto>

#include "array_list.h"

namespace structures {

// AS IMPLEMENTAÇÕES PODEM SER RECURSIVAS OU NÃO
// SE NECESSÁRIO, OPERAÇÕES ALTERNATIVAS OU AUXILIARES PODEM SER ADICIONADAS
// (NESTE CASO, A OPERAÇÃO TESTADA É BASICAMENTE UMA CHAMADA A OUTRO MÉTODO)

template<typename T>
class BinaryTree {
public:
    BinaryTree();

    ~BinaryTree();

    void insert(const T& data);

    void remove(const T& data);

    bool contains(const T& data) const;

    bool empty() const;

    std::size_t size() const;

    ArrayList<T> pre_order() const;

    ArrayList<T> in_order() const;

    ArrayList<T> post_order() const;

private:
    struct Node {
        explicit Node(const T& data_) {
            data = data_;
            left = nullptr;
            right = nullptr;
        }

        T data;
        Node* left;
        Node* right;

        void insert(const T& data_) {
            // COLOQUE SEU CÓDIGO AQUI... SE IMPLEMENTAÇÃO RECURSIVA
            if (data_ < data) {
                if (left == nullptr) {
                    left = new Node(data_);
                } else {
                    left->insert(data_);
                }
            } else if (data_ > data) {
                if (right == nullptr) {
                    right = new Node(data_);
                } else {
                    right->insert(data_);
                }
            }
        }

        bool remove(const T& data_) {
            return true;
        }

        bool contains(const T& data_) const {
            if (data_ == data) {
                return true;
            } else if (data_ < data) {
                if (left != nullptr) {
                    return left->contains(data_);
                } else {
                    return false;
                }
            } else {  // data_ > data
                if (right != nullptr) {
                    return right->contains(data_);
                } else {
                    return false;
                }
            }
        }

        void pre_order(ArrayList<T>& v) const {
            // COLOQUE SEU CÓDIGO AQUI...
            v.push_back(data);
            if (left != nullptr) {
                left->pre_order(v);
            }
            if (right != nullptr) {
                right->pre_order(v);
            }
        }

        void in_order(ArrayList<T>& v) const {
            // COLOQUE SEU CÓDIGO AQUI...
            if (left != nullptr) {
                left->in_order(v);
            }
            v.push_back(data);
            if (right != nullptr) {
                right->in_order(v);
            }
        }

        void post_order(ArrayList<T>& v) const {
            // COLOQUE SEU CÓDIGO AQUI...
            if (left != nullptr) {
                left->post_order(v);
            }
            if (right != nullptr) {
                right->post_order(v);
            }
            v.push_back(data);
        }
    };

    Node* root;
    std::size_t size_;
};

}  // namespace structures

//-------------------------------------

template<typename T>
structures::BinaryTree<T>::BinaryTree() {
    root = nullptr;
    size_ = 0;
}

template<typename T>
structures::BinaryTree<T>::~BinaryTree() {
    // COLOQUE SEU CÓDIGO AQUI...
    delete(root);
}

template<typename T>
void structures::BinaryTree<T>::insert(const T& data) {
    Node* novo = new Node(data);
    if (novo == nullptr) {
        throw std::out_of_range("Erro ao alocar novo nó");
    }

    if (empty()) {
        root = novo;
    } else {
        Node* p = root;
        Node* q = nullptr;

        while (p != nullptr) {
            q = p;
            if (data == p->data) {
                return;
            } else if (data < p->data) {
                p = p->left;
            } else {
                p = p->right;
            }
        }

        if (data < q->data) {
            q->left = novo;
        } else {
            q->right = novo;
        }
    }

    size_++;
}

template<typename T>
void structures::BinaryTree<T>::remove(const T& data) {
    if (root == nullptr) {
        return;
    }

    Node* p = root; 
    Node* q = nullptr;
    while (p != nullptr && p->data != data) {
        q = p;
        if (data < p->data) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    if (p == nullptr) {
        return;
    }
    
    if (p->left == nullptr && p->right == nullptr) {
        if (p == root) {
            root = nullptr;
        } else if (p == q->left) {
            q->left = nullptr;
        } else {
            q->right = nullptr;
        }
        delete p;
        size_--;

    } else if (p->left == nullptr || p->right == nullptr) {
        Node* r = nullptr;
        if (p->left != nullptr) {
            r = p->left;
        } else {
            r = p->right;
        }

        if (p == root) {
            root = r;
        } else if (p == q->left) {
            q->left = r;
        } else { 
            q->right = r;
        }
        delete p;
        size_--;
        
    } else {
        Node* s = p->right;
        Node* qs = p;

        while (s->left != nullptr) {
            qs = s;
            s = s->left;
        }
        p->data = s->data;
        
        if (qs == p) { 
            qs->right = s->right;
        } else { 
            qs->left = s->right;
        }

        delete s;
    }
    size_--;
}

template<typename T>
bool structures::BinaryTree<T>::contains(const T& data) const {
    if (root != nullptr) {
        return root->contains(data);
    } else {
        return false;
    }
}

template<typename T>
bool structures::BinaryTree<T>::empty() const {
    return size() == 0;
}

template<typename T>
std::size_t structures::BinaryTree<T>::size() const {
    return size_;
}

template<typename T>
structures::ArrayList<T> structures::BinaryTree<T>::pre_order() const {
    structures::ArrayList<T> L;
	if (root != nullptr) {
		root->pre_order(L);
	}
	return L;
}

template<typename T>
structures::ArrayList<T> structures::BinaryTree<T>::in_order() const {
    structures::ArrayList<T> L;
	if (root != nullptr) {
		root->in_order(L);
	}
	return L;
}

template<typename T>
structures::ArrayList<T> structures::BinaryTree<T>::post_order() const {
    structures::ArrayList<T> L;
	if (root != nullptr) {
		root->post_order(L);
	}
	return L;
}