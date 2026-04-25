#pragma once
#include "date.h"
#include "order.h"
#include "functional_list.h"
#include "stats.h"
#include <string>


using namespace std;

DateRange readDateRange();

List<string> readCategoryList();
List<Order> readOrderList();

template<typename T, typename F>
inline void printList(const List<T>& list, F displayFunc) {
    stream(
        list,
        displayFunc
    );
}

void printCategoryList(const List<string>& categoryList);
void printOrderList(const List<Order>& orderList);
void printCategoryStatsList(const List<CategoryStat>& categoryStatsList);