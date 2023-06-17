#pragma once

#include "INode.h"

namespace utils {
    template<class T>
    class Queue {
    public:
        INode<T> *head;
        INode<T> *tail;

        Queue() {
            head = tail = nullptr;
        }

        void enqueue(T data) {
            auto *newNode = new INode<T>(data);
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        T dequeue() {
            if (head == nullptr) {
                throw "Queue is empty";
            }
            INode<T> *temp = head;
            head = head->next;
            T data = temp->data;
            delete temp;
            return data;
        }

        T peek() {
            if (head == nullptr) {
                throw "Queue is empty";
            }
            return head->data;
        }

        bool isEmpty() {
            return head == nullptr;
        }

        void clear() {
            while (!isEmpty()) {
                dequeue();
            }
        }

        ~Queue() {
            clear();
        }

    };
}