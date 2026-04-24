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


CategoryList readCategories() {
    string line;
    getline(cin >> ws, line);
    return parseCategories(line, 0);
}

void printCategoriesRecursive(const CategoryNode* current) {
    cout << current->name << (current->next != nullptr ? ", " : "");
    return current->next != nullptr ? printCategoriesRecursive(current->next) : 
           void();
}

void printCategories(const CategoryList& categories) {
    return categories.head != nullptr ? printCategoriesRecursive(categories.head) :
           void();
}