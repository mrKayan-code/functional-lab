#pragma once
#include <string>

struct Date {
    int year;
    int month;
    int day;
};

Date parseDate(const std::string& stringDate);
bool isDateOlder(const Date& dateA, const Date& dateB);
bool isDateInRange(const Date& date, const Date& start, const Date& end);
std::string dateToString(const Date& date);