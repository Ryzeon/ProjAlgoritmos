#pragma once

#include "INode.h"

 namespace utils {

    template<class T>
    class Stack {
    private:
        INode<T> *node;
        int size;

    public:
        Stack() {
            node = nullptr;
            size = 0;
        }

        void push(T data) {
            auto *newNode = new INode<T>(data);
            if (node == nullptr) {
                node = newNode;
            } else {
                newNode->next = node;
                node = newNode;
            }
            size++;
        }

        T pop() {
            if (node == nullptr) {
                throw "Stack is empty";
            }
            INode<T> *temp = node;
            node = node->next;
            T data = temp->data;
            delete temp;
            size--;
            return data;
        }

        T peek() {
            if (node == nullptr) {
                throw "Stack is empty";
            }
            return node->data;
        }

        bool isEmpty() {
            return node == nullptr;
        }

        void clear() {
            while (!isEmpty()) {
                pop();
            }
        }

        ~Stack() {
            clear();
        }
    };
}