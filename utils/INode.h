#pragma once

namespace utils {

    template<class T>
    class INode {
    public:
        INode *next;
        INode *prev;
        T data;

        explicit INode(T data) {
            this->data = data;
            next, prev = nullptr;
        };
    };
}