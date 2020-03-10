#include <iostream>
#include <string>

using namespace std;

string encodePassword(const string& pass) {
    int index = 0;
    int counter = 1;
    string output;

    while (index < pass.length()) {
        while (pass[index] == pass[index + 1]) {
            counter++;
            index++;
        }

        output += to_string(counter);
        counter = 1;
        output += pass[index];
        index++;
    }

    return output;
}

int main() {
    string input;
    cin >> input;
    string output = encodePassword(input);
    cout << output;

    return 0;
}
