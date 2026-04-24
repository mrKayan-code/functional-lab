#pragma once
#include "date.h"
#include "order.h"
#include "category_list.h"
#include <string>

using namespace std;

DateRange readDateRange();
CategoryList readCategories();

void printCategories(const CategoryList& categories);