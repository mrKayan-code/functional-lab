#pragma once
#include "date.h"
#include <string>

struct Order {
    int id;
    int amount;
    std::string category;
    Date date;
};