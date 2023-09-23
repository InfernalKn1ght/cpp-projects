#include <iostream>
#define ll long long

int main(int argc, char *argv[])
{
    int n = 0;

    std::cin >> n;

    ll *arr = new ll[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    
    ll min = arr[0];
    ll max = arr[n-1];

    bool f = 1;

    for (int i = 0; i < n - 1; ++i)
    {
        ll delta = arr[i + 1] - arr[i];

        if (delta < 0)
        {
            f = 0;
        }
    }

    if (f) std::cout << max-min;
    else std::cout << -1; 

    delete[] arr;

    return EXIT_SUCCESS;
}