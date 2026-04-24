#include <iostream>
#include <string>

using namespace std;

struct  Date
{
    int year;
    int month;
    int day;
};

Date parseDate(string stringDate) { // YYYY-MM-DD
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