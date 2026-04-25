#include "io.h"
#include <iostream>
#include <string>

using namespace std;

DateRange readDateRange() {
    string startStr, endStr;

    cin >> startStr >> endStr;
    return DateRange {
        parseDate(startStr), 
        parseDate(endStr)
    };
}

CategoryList parseCategories(const string& line, size_t start);
CategoryList buildCategoryNode(const string& token, const string& line, size_t nextStart);
CategoryList handleToken(const string& line, size_t start, size_t end);
size_t findCategoryEnd(const string& line, size_t start);


size_t findCategoryEnd(const string& line, size_t start) {
    size_t end = line.find_first_of(", ", start);
    return (end != string::npos) ? end :
           line.length();
}

CategoryList buildCategoryNode(const string& token, const string& line, size_t nextStart) {
    CategoryList rest = parseCategories(line, nextStart);
    return CategoryList {
        new CategoryNode{
            token, 
            rest.head
        }, 
        rest.size + 1
    };
}

CategoryList handleToken(const string& line, size_t start, size_t end) {
    string token =  line.substr(start, end - start);
    return token.empty() ? parseCategories(line, start + 1) :
           buildCategoryNode(token, line, end + 1);
}

CategoryList parseCategories(const string& line, size_t start) {
    return start >= line.length() ? CategoryList { nullptr, 0 } :
           handleToken(line, start, findCategoryEnd(line, start));

}


CategoryList readCategoryList() {
    string line;
    getline(cin >> ws, line);
    return parseCategories(line, 0);
}

void printCategoriesRecursively(const CategoryNode* current) {
    cout << current->name << (current->next != nullptr ? ", " : "");
    return current->next != nullptr ? printCategoriesRecursively(current->next) : 
           void();
}

void printCategoryList(const CategoryList& categoryList) {
    return categoryList.head != nullptr ? printCategoriesRecursively(categoryList.head) :
           void();
}


Order readOrder() {
    int id, amount; 
    char sep; 
    string category, dateStr;
    
    cin >> id >> sep >> amount >> sep >> category >> dateStr;

    return Order {
        id, 
        amount, 
        category.substr(0, category.length() - 1), 
        parseDate(dateStr)
    };
}

OrderList buildOrderList(Order order, OrderList rest) {
    return OrderList{new OrderNode{order, rest.head}, rest.count + 1};
}

OrderList readOrderList() {
    return (cin >> ws).eof() ? OrderList {nullptr, 0} : 
           [order = readOrder()]() -> OrderList {
            OrderList rest = readOrderList();
            return buildOrderList(order, rest);
           } ();
}

void printOrder(const Order& order) {
    cout << order.id << ", " << order.amount << ", " << order.category << ", " << dateToString(order.date) << endl;
}

void printOrdersReccursively(const OrderNode* current) {
    printOrder(current->order);
    return current->next != nullptr ? printOrdersReccursively(current->next) : 
           void();
}

void printOrderList(const OrderList& orderList) {
    return orderList.head != nullptr ? printOrdersReccursively(orderList.head) :
           void();
}