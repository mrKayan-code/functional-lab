#pragma once
#include "date.h"
#include "order.h"
#include "category_list.h"
#include "order_list.h"


using namespace std;

DateRange readDateRange();

CategoryList readCategoryList();
void printCategoryList(const CategoryList& categoryList);

Order readOrder();
OrderList readOrderList();
void printOrder(const Order& order);
void printOrderList(const OrderList& orderList);
