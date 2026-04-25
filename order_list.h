#pragma once
#include "order.h"

struct OrderNode {
    Order order;
    OrderNode* next;
};

struct OrderList {
    OrderNode* head;
    size_t count;
};