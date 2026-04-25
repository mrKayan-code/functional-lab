#pragma once
#include <type_traits>

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
inline void stream(List<T> list, F f) {
    return list.head == nullptr ? 
            void() 
            : (f(list.head->data),
             stream(List<T>{list.head->next, list.length - 1}, f));
}

template<typename T, typename Predicate>
inline List<T> filter(List<T> list, Predicate predicate) {
    return list.head == nullptr ? 
            emptyList<T>() 
            : (predicate(list.head->data) ? 
                cons(list.head->data, filter(List<T>{list.head->next, list.length - 1}, predicate)) 
                : filter(List<T>{list.head->next, list.length - 1}, predicate));
}

template<typename T, typename Accumulator, typename F>
inline Accumulator fold(List<T> list, Accumulator first, F f) {
    return list.head == nullptr ? 
            first
            : fold(
                List<T>{list.head->next, list.length - 1},
                f(first, list.head->data),
                f
            );
}

template<typename T, typename F, typename U = invoke_result_t<F, T>>
inline List<U> map(List<T> list, F f) {
    return list.head == nullptr ?
            emptyList<U>() 
            : cons(f(list.head->data), map(List<T>{list.head->next, list.length - 1}, f));
}

