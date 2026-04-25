#include <iostream>
#include <string>
#include "date.h"
#include "order.h"
#include "category_list.h"
#include "order_list.h"
#include "io.h"

using namespace std;

int main() {
    CategoryList cl = readCategories();
    
    printCategories(cl);

    return 0;
}