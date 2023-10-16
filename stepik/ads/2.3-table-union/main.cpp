#include <iostream>

int find(int i, int *parent) {
    if (parent[i] != i) {
        parent[i] = find(parent[i], parent);
    }
    return parent[i];
}

int main(int argc, char *argv[]) {
    int n = 0;
    int m = 0;

    std::cin >> n >> m;

    int *data = new int[n];
    int *parent = new int[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> data[i];
        parent[i] = i;
    }

    int max = 0;
    for (int i = 0; i < n; ++i) {
        max = std::max(max, data[i]);
    }

    int *answer = new int[m];
    for (int i = 0; i < m; ++i) {
        int destination = 0;
        int source = 0;

        std::cin >> destination >> source;

        int destinationIndex = find(destination - 1, parent);
        int sourceIndex = find(source - 1, parent);

        if (destinationIndex != sourceIndex) {
            data[destinationIndex] += data[sourceIndex];
            parent[sourceIndex] = parent[destinationIndex];
            max = std::max(max, data[destinationIndex]);
        }

        answer[i] = max;
    }

    for (int i = 0; i < m; ++i) {
        std::cout << answer[i] << '\n';
    }

    return EXIT_SUCCESS;
}