#pragma once
#include <string>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

struct  DateRange {
    Date start;
    Date end;
};

Date parseDate(const string& stringDate);
bool isDateOlder(const Date& dateA, const Date& dateB);
bool isDateInRange(const Date& date, const Date& start, const Date& end);
string dateToString(const Date& date);