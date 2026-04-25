#include <iostream>
#include <string>
#include <optional>
#include "date.h"
#include "order.h"
#include "io.h"
#include "functional_list.h"

using namespace std;

int main() {
    DateRange dateRange = readDateRange();
    List<string> categories = readCategoryList();

    List<Order> orders = readOrderList();

    List<Order> filtered = filter(
        orders,
        [&dateRange](const Order& order) {
            return isDateInRange(
                order.date,
                dateRange.start,
                dateRange.end
            );
        }
    );

    filtered = filter(
        filtered,
        [](const Order& order) {
            return order.amount > 0;
        }
    );

    filtered = filter(
        filtered,
        [&categories](const Order& order) {
            return contains(categories, order.category);
        }
    );

    printOrderList(filtered);

    int totalAmount = fold(
        filtered,
        0,
        [](int left, const Order& order) {
            return left + order.amount;
        }
    );

    cout << totalAmount << endl;

    optional<Order> maxAmountOrder = reduce(
        filtered,
        [] (const Order& left, const Order& right) {
            return left.amount > right.amount ?
                    left
                    : right;
        }
    );

    string maxAmountResult = maxAmountOrder.has_value() ?
            to_string(maxAmountOrder.value().amount)
            : "no data";
    
    cout << maxAmountResult << endl;
    


    return 0;
}