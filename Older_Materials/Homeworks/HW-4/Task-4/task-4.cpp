#include <iostream>
#include <list>
#include <cstring>

using std::list;
using std::string;

int main() {
    int num;
    std::cin >> num;

    list<int> order;

    for (int i = 0; i < num; i++) {
        string input;
        std::cin >> input;

        if (input == "add") {
            int data;
            std::cin >> data;

            order.push_back(data);
        }
        else if (input == "gun") {
            order.pop_back();
        }
        else if (input == "milen") {
            int toMove = order.size();
            toMove /= 2;

            for (int j = 0; j < toMove; j++) {
                order.push_back(order.front());
                order.pop_front();
            }
        }
    }

    std::cout << order.size() << std::endl;

    while (!order.empty()) {
        std::cout << order.front() << " ";
        order.pop_front();
    }

    return 0;
}
