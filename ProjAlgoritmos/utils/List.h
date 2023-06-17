#pragma once

#include "INode.h"
#include <functional>

using namespace std;

namespace utils {
    template<class T>
    class List {
    private:
        INode<T> *head;
        INode<T> *tail;
        int size;

    public:
        List() {
            head = tail = nullptr;
            size = 0;
        }

        void add(T data) {
            auto *newNode = new INode<T>(data);
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            size++;
        }

        void add(T data, int index) {
            if (index < 0 || index > size) {
                throw "Index out of bounds";
            }
            if (index == size) {
                add(data);
                return;
            }
            auto *newNode = new INode<T>(data);
            if (index == 0) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } else {
                INode<T> *temp = head;
                for (int i = 0; i < index - 1; i++) {
                    temp = temp->next;
                }
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next->prev = newNode;
                temp->next = newNode;
            }
            size++;
        }

        T remove(int index) {
            if (index < 0 || index >= size) {
                throw "Index out of bounds";
            }
            INode<T> *temp = head;
            if (index == 0) {
                head = head->next;
                head->prev = nullptr;
            } else if (index == size - 1) {
                temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
            } else {
                for (int i = 0; i < index; i++) {
                    temp = temp->next;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            T data = temp->data;
            delete temp;
            size--;
            return data;
        }

        T get(int index) {
            if (index < 0 || index >= size) {
                throw "Index out of bounds";
            }
            INode<T> *temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp->data;
        }

        void set(T data, int index) {
            if (index < 0 || index >= size) {
                throw "Index out of bounds";
            }
            INode<T> *temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            temp->data = data;
        }

        int getSize() {
            return size;
        }

        bool isEmpty() {
            return size == 0;
        }

        List<T> search(function<bool(T)> predicate) {
            List<T> list;
            INode<T> *temp = head;
            while (temp != nullptr) {
                if (predicate(temp->data)) {
                    list.add(temp->data);
                }
                temp = temp->next;
            }
            return list;
        }

        T& find_first(function<bool(T)> predicate) {
            List<T> list = search(predicate);
            if (list.isEmpty())
                throw "Not found";

            return list.get(0);
        }

        explicit operator T *() {
            T *array = new T[size];
            INode<T> *temp = head;
            for (int i = 0; i < size; i++) {
                array[i] = temp->data;
                temp = temp->next;
            }
            return array;
        }
    };
}
