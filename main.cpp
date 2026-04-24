#include <iostream>
#include <string>

using namespace std;

struct  Date
{
    int year;
    int month;
    int day;
};

Date parseDate(string stringDate) {
    int y = stoi(stringDate.substr(0, 4));
    int m = stoi(stringDate.substr(5, 2));
    int d = stoi(stringDate.substr(8, 2));
    
    return {y, m, d};
}

bool isDateOlder(const Date& dateA, const Date& dateB) {
    return (dateA.year != dateB.year) ? (dateA.year < dateB.year) :
           (dateA.month != dateB.month) ? (dateA.month < dateB.month) :
           (dateA.day < dateB.day);
}

bool isDateInRange(const Date& date, const Date& start, const Date& end) {
    return !isDateOlder(date, start) && isDateOlder(date, end);
}

string dateToSring(const Date& date) {
    string monthString = (date.month < 10) ? ("0" + std::to_string(date.month)) : std::to_string(date.month);
    string dayString = (date.day < 10) ? ("0" + std::to_string(date.day)) : std::to_string(date.day);
    return std::to_string(date.year) + "-" + monthString + "-" + dayString;
}

struct Order {
    int id;
    int amount;
    string category;
    Date date;
};


int main() {

    cout << "Hello, World!" << endl;

    return 0;
}