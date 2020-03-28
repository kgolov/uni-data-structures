#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int ALPHABET_SIZE = 26;

struct Trie {
    int words;
    Trie* transitions[ALPHABET_SIZE] = {};

    Trie() {
        words = 0;
    }

    // Insert a word into our trie
    void insert(string word) {
        Trie* current = this;

        // For each node, mark that a new word is inserted
        for (int i = 0; i < word.length(); i++) {
            current->words++;

            if (current->transitions[word[i] - 'a'] == nullptr) {
                current->transitions[word[i] - 'a'] = new Trie();
            }

            current = current->transitions[word[i] - 'a'];

            if (i == word.length() - 1) {
                current->words++;
            }
        }
    }

    const int autocomplete(string word) {
        Trie* current = this;

        for (int i = 0; i < word.length(); i++) {
            if (current->transitions[word[i] - 'a'] != nullptr) {
                current = current->transitions[word[i] - 'a'];
            }
            else {
                // There is no such prefix at all
                return 0;
            }
        }

        // We have reached where our prefix ends, so just print how much words start with it
        return current->words;
    }
};

int main() {
    int n, q;
    std::cin >> n >> q;
    string input;
    Trie trie;

    for (int i = 0; i < n; i++) {
        std::cin >> input;

        trie.insert(input);
    }

    for (int i = 0; i < q; i++) {
        std::cin >> input;

        printf("%d\n", trie.autocomplete(input));
    }

    return 0;
}
