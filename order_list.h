#pragma once
#include "order.h"

struct OrderNode {
    Order data;
    OrderNode* next;
};

struct OrderList {
    OrderNode* head;
    size_t count;
};