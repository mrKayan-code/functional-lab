#include "date.h"

using namespace std;

Date parseDate(const string& stringDate) {
    int y = stoi(stringDate.substr(0, 4));
    int m = stoi(stringDate.substr(5, 2));
    int d = stoi(stringDate.substr(8, 2));
    
    return {
        y,
        m, 
        d
    };
}

bool isDateOlder(const Date& dateA, const Date& dateB) {
    return (dateA.year != dateB.year) ? 
            (dateA.year < dateB.year) :
            (dateA.month != dateB.month) ?
                (dateA.month < dateB.month) :
                (dateA.day < dateB.day);
}

bool isDateInRange(const Date& date, const Date& start, const Date& end) {
    return !isDateOlder(date, start) && !isDateOlder(end, date);
}

string dateToString(const Date& date) {
    string monthString = (date.month < 10) ? 
                            ("0" + to_string(date.month)) : 
                            to_string(date.month);

    string dayString = (date.day < 10) ? 
                        ("0" + to_string(date.day)) : 
                        to_string(date.day);
    
    return to_string(date.year) + "-" + monthString + "-" + dayString;
}