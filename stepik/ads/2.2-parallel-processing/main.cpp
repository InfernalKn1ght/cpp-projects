#include <iostream>

#define ll long long

class Heap {
private:
    ll *data;
    ll *number;
    int size;
    int capacity;

    void expand() {
        ll *temp = new ll[capacity * 2];
        ll *temp1 = new ll[capacity * 2];

        for (int i = 0; i < size; ++i) {
            temp[i] = data[i];
        }
        for (int i = 0; i < size; ++i) {
            temp1[i] = number[i];
        }

        // delete[] data;
        // delete[] number;

        data = temp;
        number = temp1;

        capacity *= 2;
    }

    int getParent(int i) {
        return (i - 1) / 2;
    }

    void siftDown(int i) {
        int min_index = i;
        int l = 2 * i + 1;
        if (l < size && data[l] < data[min_index]) {
            min_index = l;
        }
        int r = 2 * i + 2;
        if (r < size && data[r] < data[min_index]) {
            min_index = r;
        }

        if (l < size && r < size && data[l] == data[r]) {
            if (l < size && number[l] < number[min_index]) {
                min_index = l;
            }
            if (r < size && number[r] < number[min_index]) {
                min_index = r;
            }
        }

        if (min_index != i) {
            std::swap(data[i], data[min_index]);
            std::swap(number[i], number[min_index]);
            siftDown(min_index);
        }
    }

    void siftUp(int i) {
        while (i > 0 && (data[i] < data[getParent(i)] || (data[i] == data[getParent(i)] && number[i] < number[getParent(i)]))) {
            std::swap(data[i], data[getParent(i)]);
            std::swap(number[i], number[getParent(i)]);
            i = getParent(i);
        }
    }

public:
    ll getMin() {
        if (size > 0) {
            return data[0];
        } else {
            return -1;
        }
    }
    ll getNum() {
        if (size > 0) {
            return number[0];
        } else {
            return -1;
        }
    }

    void insert(ll p, ll n) {
        if (size + 1 > capacity) {
            expand();
        }

        data[size] = p;
        number[size] = n;
        siftUp(size);
        ++size;
    }

    void extractMin() {
        data[0] = data[size - 1];
        number[0] = number[size - 1];
        siftDown(0);
        --size;
    }

    void Print() {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " " << number[i] << " | ";
        }
        std::cout << "\n";
    }

    Heap(int size = 0, int capacity = 4) : data(new ll[size]), number(new ll[size]), size(size), capacity(capacity) {}

    ~Heap() {}
};

int main(int argc, char *argv[]) {
    ll n = 0;
    ll m = 0;
    Heap h;

    std::cin >> n >> m;

    ll **answer = new ll *[m];

    for (int i = 0; i < m; ++i) {
        answer[i] = new ll[2];
    }

    for (int i = 0; i < n; ++i) {
        h.insert(0, i);
    }

    for (int i = 0; i < m; ++i) {
        ll data = 0;
        std::cin >> data;

        ll p = h.getMin();
        ll num = h.getNum();
        h.extractMin();
        h.insert(data + p, num);
        answer[i][0] = num;
        answer[i][1] = p;
    }

    for (int i = 0; i < m; ++i) {
        std::cout << answer[i][0] << " " << answer[i][1] << '\n';
    }

    return EXIT_SUCCESS;
}