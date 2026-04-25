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
    size_t count;
};

template<typename T>
inline List<T> emptyList() {
    return List<T>{nullptr, 0};
}

template<typename T>
inline List<T> cons(T data, List<T> rest) {
    return List<T>{new Node<T>{data, rest.head}, rest.count + 1};
}

