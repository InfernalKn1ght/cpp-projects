#include <iostream>

int main(int argc, char *argv[])
{
    std::string s;
    std::cin >> s;

    int n = s.size();

    int *pi = new int[n]{0};

    for (int i = 1; i < n; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == s[j])
        {
            ++j;
        }
        pi[i] = j;
    }

    std::cout << s << "\n";

    for (int i = 0; i < n; ++i)
    {
        std::cout << pi[i] << " ";
    }

    return EXIT_SUCCESS;
}