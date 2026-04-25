#include <iostream>
#include <string>
#include <optional>
#include "date.h"
#include "order.h"
#include "io.h"
#include "functional_list.h"
#include "stats.h"

using namespace std;

List<Order> filterOrdersByDatePositiveAmountCategories(const List<Order>& orders, const DateRange& dateRange, const List<string>& categories) {
    // List<Order> filtered = filter(
    //     orders,
    //     [&dateRange](const Order& order) {
    //         return isDateInRange(
    //             order.date,
    //             dateRange.start,
    //             dateRange.end
    //         );
    //     }
    // );

    // filtered = filter(
    //     filtered,
    //     [](const Order& order) {
    //         return order.amount > 0;
    //     }
    // );

    // filtered = filter(
    //     filtered,
    //     [&categories](const Order& order) {
    //         return contains(categories, order.category);
    //     }
    // );

    // return filtered;

    return filter(
        filter(
            filter(
                orders,
                [&dateRange](const Order& order) {
                    return isDateInRange(
                        order.date,
                        dateRange.start,
                        dateRange.end
                    );
                }
            ),
            [](const Order& order) {
                return order.amount > 0;
            }
        ),
        [&categories](const Order& order) {
            return contains(categories, order.category);
        }
    );
}

int findTotalAmount(const List<Order>& orders) {
    return fold(
        orders,
        0,
        [](int left, const Order& order) {
            return left + order.amount;
        }
    );
}

optional<Order> findOrderWithMaxAmount(const List<Order>& orders) {
    return reduce(
        orders,
        [] (const Order& left, const Order& right) {
            return left.amount > right.amount ?
                    left
                    : right;
        }
    );
}

void printMaxAmountResult(const optional<Order>& maxAmountOrder) {
    string maxAmountResult = maxAmountOrder.has_value() ?
            to_string(maxAmountOrder.value().amount)
            : "no data";
    
    cout << maxAmountResult << endl;
}

List<CategoryStat> findAverageAmountByCategoriesList(const List<string>& categories, const List<Order>& orders) {
    return map(
        categories,
        [&orders] (const string& category) -> CategoryStat {
            List<Order> ordersByCategory = filter(
                orders,
                [&category] (const Order& order) {
                    return order.category == category;
                }
            );

            int sumAmount = fold(
                ordersByCategory,
                0,
                [](int left, const Order& order) {
                    return left + order.amount;
                }
            );

            double averageAmount = ordersByCategory.length > 0 ?
                    double(sumAmount) / ordersByCategory.length
                    : 0.0;
            
            return CategoryStat {category, averageAmount};
        }
    );
}

int main() {
    DateRange dateRange = readDateRange();
    List<string> categories = readCategoryList();
    List<Order> orders = readOrderList();

    List<Order> filtered = filterOrdersByDatePositiveAmountCategories(
        orders,
        dateRange,
        categories
    );

    printOrderList(filtered);

    int totalAmount = findTotalAmount(filtered);

    cout << totalAmount << endl;

    optional<Order> maxAmountOrder = findOrderWithMaxAmount(filtered);

    printMaxAmountResult(maxAmountOrder);
    
    List<CategoryStat> averageAmountByCategories = findAverageAmountByCategoriesList(
        categories,
        filtered
    );

    printCategoryStatsList(averageAmountByCategories);

    return 0;
}