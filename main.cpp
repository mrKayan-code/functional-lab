#include <iostream>
#include <string>

using namespace std;

struct  Date
{
    int y;
    int m;
    int d;
};


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