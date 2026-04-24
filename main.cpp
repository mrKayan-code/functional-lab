#include <iostream>
#include <string>
#include "date.h"
#include "order.h"
#include "io.h"

using namespace std;

int main() {
    DateRange dr = readDateRange();

    cout << dateToString(dr.start) << " - " << dateToString(dr.end) << endl;
    
    return 0;
}