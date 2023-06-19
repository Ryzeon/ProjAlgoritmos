#pragma once

#include "INode.h"
#include <functional>

using namespace std;

namespace utils {
    template<class T>
    class BinaryTree {
        typedef function<int(T, T)> comp;
        INode<T> *root;
        comp compare;
    private:
        bool search(INode<T> *node, T e) {
            if (node == nullptr)
                return false;
            else {
                int r = compare(node->data, e);
                if (r == 0)
                    return true;
                else if (r < 0) {
                    return search(node->next, e);
                } else
                    return search(node->prev, e);
            }
        }

        INode<T> *obtain(INode<T> *INode, T e) {
            if (INode == nullptr)
                return nullptr;
            else {
                int r = compare(INode->elem, e);
                if (r == 0)
                    return INode;
                else if (r < 0) {
                    return search(INode->rigth, e);
                } else
                    return search(INode->left, e);
            }
        }

        bool insert(INode<T> *&node, T e) {
            if (node == nullptr) {
                node = new INode<T>();
                node->elem = e;
                return true;
            } else {
                int r = compare(node->data, e);
                if (r == 0)
                    return false;
                else if (r < 0) {
                    return insert(node->next, e);
                } else
                    return insert(node->prev, e);
            }
        }

        bool remove(INode<T> *&node, T e) {
            if (node == nullptr) return false;
            else {
                int r = compare(node->data, e);
                if (r < 0) {
                    return remove(node->next, e);
                } else if (r > 0) {
                    return remove(node->prev, e);
                } else {
                    if (node->next == nullptr && node->prev == nullptr) {
                        node = nullptr;
                        delete node;
                        return true;
                    } else if (node->prev == nullptr) {
                        node = node->next;
                        return true;
                    } else if (node->next == nullptr) {
                        node = node->prev;
                        return true;
                    } else {
                        INode<T> *aux = node->next;
                        while (aux->prev != nullptr) {
                            aux = aux->prev;
                        }
                        node->elem = aux->data;
                        return remove(node->next, aux->data);
                    }
                }
            }
        }

        bool isEmpty() {
            return root = nullptr;
        }

    public:
        explicit BinaryTree() {
            this->compare = [](T a, T b) -> int {
                return a - b;
            };
            root = nullptr;
        }

        void setCompare(comp compare) {
            this->compare = compare;
        }

        bool Insert(T e) {
            return insert(root, e);
        }

        bool Remove(T e) {
            return remove(root, e);
        }

        // method #1
        bool Search(T e) {
            return search(root, e);
        }

        // method #2
        int find_first(function<bool(int)> predicate) {

        }

        //method #3
        int remove_if(function<bool(int)> predicate) {

        }

    };
}

