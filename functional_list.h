#pragma once

using namespace std;

template<typename T>
struct Node
{
    T data;
    Node* next;
};

template<typename T>
struct List {
    Node<T>* head;
    size_t length;
};

template<typename T>
inline List<T> emptyList() {
    return List<T>{nullptr, 0};
}

template<typename T>
inline List<T> cons(T data, List<T> rest) {
    return List<T>{new Node<T>{data, rest.head}, rest.length + 1};
}

template<typename T, typename F>
inline void stream(List<T> list, F action) {
    return list.head == nullptr ? void() :
           (action(list.head->data),
            stream(List<T>{list.head->next, list.length - 1}, action));
}

