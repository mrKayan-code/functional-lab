#pragma once
#include "date.h"
#include <string>

struct Order {
    int id;
    int amount;
    string category;
    Date date;
};