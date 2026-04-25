#pragma once
#include "date.h"
#include "order.h"
#include "functional_list.h"
#include <string>


using namespace std;

DateRange readDateRange();

List<string> readCategoryList();
List<Order> readOrderList();

void printCategoryList(const List<string>& categoryList);
void printOrderList(const List<Order>& orderList);
