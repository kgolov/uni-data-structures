#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
using pll = pair<long long, long long>;
using pii = pair<int, int>;

const int p = 257;
const long long mod = 1610612741;
const long long mod2 = 1000000009;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

string mostFrequent(const string& hstack, int len) {
    // To store number of occurences of hashes - the key is the hash
    // The value is a pair, the first number of which is the number of times a hash is found
    // and the second number is the last index at which there was an occurence
    unordered_map<pll, pii, hash_pair> hashes;

    long long curHash = 0;
    long long curHash2 = 0;
    long long power = 1;
    for (int i = 0; i < len; i++) {
        power = (power * p) % mod;
    }

    // Calculate hash of starting string with length len
    for (int i = 0; i < len; i++) {
        curHash = curHash * p + hstack[i];
        curHash %= mod;
        curHash2 = curHash2 * p + hstack[i];
        curHash2 %= mod2;
    }
    hashes.insert( { {curHash, curHash2}, {1, len - 1} } );

    // Rolling hash - calculate a new hash by removing the first letter and appending another one
    for (int i = len; i < hstack.size(); i++) {
        curHash = curHash * p + hstack[i];
        curHash %= mod;
        curHash -= (power * hstack[i - len]) % mod;
        if (curHash < 0) {
            curHash += mod;
        }
        curHash2 = curHash2 * p + hstack[i];
        curHash2 %= mod2;
        curHash2 -= (power * hstack[i - len]) % mod2;
        if (curHash2 < 0) {
            curHash2 += mod2;
        }

        // If there is an occurence of the hash, update its values, else store an occurence
        auto found = hashes.find( {curHash, curHash2} );
        if (found != hashes.end()) {
            (found->second).first++;
            (found->second).second = i;
        }
        else {
            hashes.insert({ {curHash, curHash2}, {1, i} });
        }
    }

    // Find which hash is the most frequent one
    auto maxHash = hashes.begin();
    auto it = hashes.begin();
    for (; it != hashes.end(); it++) {
        if (it->second > maxHash->second) {
            maxHash = it;
        }
    }

    // Start again to find to which substring the hash corresponds
    curHash = 0;
    curHash2 = 0;
    for (int i = 0; i < len; i++) {
        curHash = curHash * p + hstack[i];
        curHash %= mod;
        curHash2 = curHash2 * p + hstack[i];
        curHash2 %= mod2;
    }
    // The hash corresponds to the first substring
    if (maxHash->first == make_pair(curHash, curHash2)) {
        return hstack.substr(0, len);
    }

    for (int i = len; i < hstack.size(); i++) {
        curHash = curHash * p + hstack[i];
        curHash %= mod;
        curHash -= (power * hstack[i - len]) % mod;
        if (curHash < 0) {
            curHash += mod;
        }
        curHash2 = curHash2 * p + hstack[i];
        curHash2 %= mod2;
        curHash2 -= (power * hstack[i - len]) % mod2;
        if (curHash2 < 0) {
            curHash2 += mod2;
        }

        // We have found to which substring the hash corresponds
        if (maxHash->first == make_pair(curHash, curHash2)) {
            return hstack.substr(i - len + 1, len);
        }
    }

    return "";
}

int main() {
    int n, len;
    std::cin >> n >> len;
    string input;
    std::cin.ignore();
    getline(cin, input);

    std::cout << mostFrequent(input, len);

    return 0;
}
