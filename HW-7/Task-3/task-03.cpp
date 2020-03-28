#include <iostream>
#include <string>
#include <map>

using namespace std;

class Directory {
    string name;
    string fullpath;
    Directory* parent;
    map<string, Directory*> children;

public:
    Directory(const string& name = "", Directory* parent = nullptr) {
        this->name = name;

        if (parent) {
            fullpath = parent->fullpath + this->name + "/";
        }
        else {
            fullpath = this->name + "/";
        }

        this->parent = parent;
    }

    const bool mkdir(const string& name) {
        if (children.count(name) > 0) {
            return false;
        }

        Directory* newDir = new Directory(name, this);
        children.insert({ name, newDir });
        return true;
    }

    const string ls() const {
        string output = "";

        for (auto child : children) {
            output += child.first;
            output += " ";
        }

        output += "\n";

        return output;
    }

    const string pwd() const {
        return fullpath;
    }

    Directory* cd(const string& name) const {
        if (name == "..") {
            return parent;
        }
        else if (children.count(name) == 0) {
            return nullptr;
        }

        return children.find(name)->second;
    }
};

int main() {
    Directory* current = new Directory();

    int commands;
    std::cin >> commands;
    string input, dir;

    for (int i = 0; i < commands; i++) {
        std::cin >> input;

        if (input == "cd") {
            std::cin >> dir;

            Directory* next = current->cd(dir);
            if (!next) {
                std::cout << "No such directory\n";
            }
            else {
                current = next;
            }
        }
        else if (input == "mkdir") {
            std::cin >> dir;

            if (!current->mkdir(dir)) {
                std::cout << "Directory already exists\n";
            }
        }
        else if (input == "ls") {
            std::cout << current->ls();
        }
        else if (input == "pwd") {
            std::cout << current->pwd() << "\n";
        }
    }

    return 0;
}
