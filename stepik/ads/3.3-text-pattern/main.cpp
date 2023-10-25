#include <iostream>

int main(int argc, char *argv[]) {
    std::string pattern;
    std::string text;

    std::cin >> pattern >> text;

    const long long val = 263;
    const long long p = 1000000007;
    long long x = 1;
    int size = ((text.size() - pattern.size() + 1) > 0 ? text.size() - pattern.size() + 1 : 1);
    long long *hash_table = new long long[size]{0};
    long long patern_hash = 0;

    for (int i = 0; i < pattern.size() - 1; ++i) {
        x = (x * val) % p;
    }

    for (long long i = 0, j = 1; i < pattern.size(); ++i) {
        patern_hash = (patern_hash + ((j * pattern[i]) % p)) % p;

        j = (j * val) % p;
    }

    for (long long i = text.size() - pattern.size(), j = 1; i < text.size(); ++i) {
        hash_table[0] = (hash_table[0] + ((j * text[i]) % p)) % p;

        j = (j * val) % p;
    }

    for (long long i = text.size() - 2, j = 1; i >= pattern.size() - 1 && i >= 0; --i, ++j) {
        hash_table[j] = (hash_table[j - 1] - ((text[i + 1] * x) % p)) * val;
        hash_table[j] = ((hash_table[j] % p) + p) % p;
        hash_table[j] = (hash_table[j] + text[i - pattern.size() + 1]) % p;
    }

    for (int i = 0; i < size; ++i) {
        if (hash_table[size - i - 1] == patern_hash) {
            bool f = 1;
            for (int j = 0; j < pattern.size(); ++j) {
                if (pattern[j] != text[i + j]) {
                    f = 0;
                    break;
                }
            }
            if (f) {
                std::cout << i << " ";
            }
        }
    }

    return EXIT_SUCCESS;
}