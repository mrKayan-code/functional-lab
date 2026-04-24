#include "io.h"
#include <iostream>
#include <string>

using namespace std;

DateRange readDateRange() {
    string startStr, endStr;

    cin >> startStr >> endStr;
    return {parseDate(startStr), parseDate(endStr)};
}