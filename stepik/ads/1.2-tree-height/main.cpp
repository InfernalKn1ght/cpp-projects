#include <iostream>

int height(int tree[], int key, int value)
{
    if (key == -1)
        return value;
    else
        return height(tree, tree[key], value + 1);
}

int main(int argc, char *argv[])
{
    int n = 0;
    std::cin >> n;
    int *tree = new int[n];

    for (int i = 0; i < n; ++i)
        std::cin >> tree[i];

    int solution = 0;
    for (int i =0; i < n; ++i)
    {
        solution = std::max(solution, height(tree, tree[i], 1));
    }

    std::cout << solution;

    delete[] tree;
}