#pragma once
#include <string>

using namespace std;

struct CategoryNode {
    string name;
    CategoryNode* next;
};

struct CategoryList {
    CategoryNode* head;
    size_t size;
};