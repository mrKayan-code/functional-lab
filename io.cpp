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

List<string> parseCategoriesLine(const string& line, size_t start);
List<string> handleCategoryToken(const string& line, size_t start, size_t end);
size_t findCategoryEnd(const string& line, size_t start);


size_t findCategoryEnd(const string& line, size_t start) {
    size_t end = line.find_first_of(", ", start);
    return (end != string::npos) ? 
            end 
            : line.length();
}

List<string> handleCategoryToken(const string& line, size_t start, size_t end) {
    string token =  line.substr(start, end - start);
    return token.empty() ? 
            parseCategoriesLine(line, start + 1) 
            : cons(token, parseCategoriesLine(line, end + 1));
}

List<string> parseCategoriesLine(const string& line, size_t start) {
    return start >= line.length() ? 
            emptyList<string>() 
            : handleCategoryToken(line, start, findCategoryEnd(line, start));
}

List<string> readCategoryList() {
    string line;
    getline(cin >> ws, line);
    return parseCategoriesLine(line, 0);
}

void printCategoryList(const List<string>& categoryList) {
    bool isFirst = true;
    stream(categoryList, [&isFirst](const string& name) {
        cout << (isFirst ? "" : ", ") << name;
        isFirst = false;
    });
}

Order readOrder() {
    int id, amount;
    string category, dateString;
    char sep;

    cin >> id >> sep >> amount >> sep >> category >> dateString;

    category = (category.length() > 0 && category.back() == ',') ?
                category.substr(0, category.length() - 1)
                : category;
    
    return Order {
        id,
        amount,
        category,
        parseDate(dateString)
    };
}

List<Order> readOrderList() {
    return (cin >> ws).eof() ?
            emptyList<Order>()
            : [order = readOrder()]() -> List<Order> {
                return cons(
                    order,
                    readOrderList()
                );
            }();
}

void printOrderList(const List<Order>& orderList) {
    stream(orderList, [](const Order& o){
        cout << o.id << ", " << o.amount << ", " << o.category 
             << ", " << dateToString(o.date) << endl;
    });
}