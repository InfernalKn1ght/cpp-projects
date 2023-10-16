#include <iostream>

int main(int argc, char *argv[]) {
    int n = 0;

    std::cin >> n;

    int *data = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> data[i];
    }

    int **answer = new int *[n];

    for (int i = 0; i < n; ++i) {
        answer[i] = new int[2];
    }

    int counter = 0;
    for (int i = n / 2; i >= 0; --i) {
        int min_index = -1;
        int index = i;
        while (min_index != index) {
            min_index = index;
            int l = 2 * index + 1;
            if (l < n && data[l] < data[min_index]) {
                min_index = l;
            }
            int r = 2 * index + 2;
            if (r < n && data[r] < data[min_index]) {
                min_index = r;
            }
            if (min_index != index) {
                std::swap(data[index], data[min_index]);

                answer[counter][0] = index;
                answer[counter][1] = min_index;
                ++counter;

                std::swap(index, min_index);
            }
        }
    }

    std::cout << counter << '\n';
    for (int i = 0; i < counter; ++i) {
        std::cout << answer[i][0] << ' ' << answer[i][1] << '\n';
    }

    for (int i = 0; i < counter; ++i) {
        delete[] answer[i];
    }

    delete[] answer;
    delete[] data;

    return EXIT_SUCCESS;
}