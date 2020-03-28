#include <iostream>
#include <queue>
#include <string>

using std::queue;
using std::string;

struct Person {
    string name;
    int timeEntered;
    int group;

    Person(string name, int group, int entered) {
        this->name = name;
        this->group = group;
        timeEntered = entered;
    }
};

struct Node {
    queue<Person> que;
    int group;
    Node* left;
    Node* right;

    Node(Person pers) {
        group = pers.group;
        que.push(pers);
        left = nullptr;
        right = nullptr;
    }

    ~Node() {
        delete left;
        delete right;
    }

    void add(Person pers) {
        if (pers.group == group) {
            que.push(pers);
        }
        else if (pers.group < group) {
            if (left == nullptr) {
                left = new Node(pers);
            }
            else {
                left->add(pers);
            }
        }
        else {
            if (right == nullptr) {
                right = new Node(pers);
            }
            else {
                right->add(pers);
            }
        }
    }

    Node* search(int group) {
        if (this->group == group) {
            return this;
        }
        else if (group < this->group && left != nullptr) {
            return left->search(group);
        }
        else if (group > this->group&& right != nullptr) {
            return right->search(group);
        }
        return nullptr;
    }
};

int main() {
    int currentTime = 0;
    queue<int> groups;

    int students;
    std::cin >> students;
    int maxGroup;
    std::cin >> maxGroup;

    string inputName;
    int inputGroup;
    std::cin >> inputName;
    std::cin >> inputGroup;

    Person input(inputName, inputGroup, currentTime);
    Node* tree = new Node(input);
    groups.push(inputGroup);

    string output = "";

    for (int i = 1; i < students; i++) {
        currentTime++;

        std::cin >> inputName;
        std::cin >> inputGroup;

        input = Person(inputName, inputGroup, currentTime);
        Node* searched = tree->search(inputGroup);
        if (!searched || searched->que.empty()) {
            // Add group to queue
            groups.push(inputGroup);
        }
        tree->add(input);

        if (currentTime % 2 == 0) {
            int nextGroup = groups.front();
            Node* next = tree->search(nextGroup);

            Person toDequeue = next->que.front();
            output += toDequeue.name;
            output += " ";
            output += std::to_string(toDequeue.timeEntered);
            output += " ";
            output += std::to_string(currentTime);
            output += "\n";
            next->que.pop();

            if (next->que.empty()) {
                groups.pop();
            }
        }
    }

    while (!groups.empty()) {
        currentTime++;
        if (currentTime % 2 == 0) {
            int nextGroup = groups.front();
            Node* next = tree->search(nextGroup);

            Person toDequeue = next->que.front();
            output += toDequeue.name;
            output += " ";
            output += std::to_string(toDequeue.timeEntered);
            output += " ";
            output += std::to_string(currentTime);
            output += "\n";
            next->que.pop();

            if (next->que.empty()) {
                groups.pop();
            }
        }
    }

    std::cout << output;

    return 0;
}
