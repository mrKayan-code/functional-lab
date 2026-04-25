#include <iostream>
#include <string>
#include "date.h"
#include "order.h"
#include "io.h"
#include "functional_list.h"

using namespace std;

int main() {
    List<Order> ol = readOrderList();
    
    printOrderList(ol);

    return 0;
}
