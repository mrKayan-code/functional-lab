#pragma once
#include <type_traits>
#include <optional>

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
inline Accumulator fold(List<T> list, Accumulator left, F f) {
    return list.head == nullptr ? 
            left
            : fold(
                List<T>{list.head->next, list.length - 1},
                f(left, list.head->data),
                f
            );
}

template<typename T, typename F>
inline optional<T> reduce(List<T> list, F f) {
    return list.head == nullptr ?
            nullopt
            : optional<T>{ fold(
                List<T>{list.head->next, list.length - 1},
                list.head->data,
                f
            )};
}

template<typename T, typename F, typename U = invoke_result_t<F, T>>
inline List<U> map(List<T> list, F f) {
    return list.head == nullptr ?
            emptyList<U>() 
            : cons(f(list.head->data), map(List<T>{list.head->next, list.length - 1}, f));
}

template<typename T>
inline bool contains(List<T> list, const T& element) {
    return list.head == nullptr ?
            false
            : list.head->data == element ?
                true
                : contains(
                    List<T>{list.head->next, list.length - 1},
                    element
                );
}



// template<typename T, typename Comparator>
// inline optional<T> findMax(List<T> list, Comparator comparator) {
//     return list.head == nullptr ?
//             nullopt
//             : [
//                 current = list.head->data, 
//                 rest = List<T>{list.head->next, list.length - 1}
//             ] () {
//                 optional<T> maxOfRest = findMax(
//                     rest,
//                     comparator
//                 );
//                 return maxOfRest.has_value() ?
//                         (comparator(*maxOfRest, current) ? 
//                             *maxOfRest
//                             : current)
//                         : current;
//             }
// }