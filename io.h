#pragma once
#include "date.h"
#include "order.h"
#include "category_list.h"
#include "order_list.h"


using namespace std;

DateRange readDateRange();
CategoryList readCategories();
OrderList readOrders();

void printCategories(const CategoryList& categories);