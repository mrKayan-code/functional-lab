#include <iostream>
#include <string>
#include "date.h"
#include "order.h"

using namespace std;

int main() {
    string input = "2024-03-10";
    Date d = parseDate(input);

    cout << "Parsed: " << dateToString(d) << endl;


    Date start = {2024, 1, 1};
    Date end   = {2024, 12, 31};
    bool inRange = isDateInRange(d, start, end);
    
    cout << (inRange ? "In range\n" : "Out of range\n");

    return 0;
}