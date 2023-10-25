#include <iostream>

class DisjointSet {
private:
    int *parent;
    int *rank;
    int capacity;

    void expand() {
        int *temp1 = new int[capacity * 2];
        int *temp2 = new int[capacity * 2];

        for (int i = 0; i < capacity; ++i) {
            temp1[i] = parent[i];
            temp2[i] = rank[i];
        }
        for (int i = capacity; i < capacity * 2; ++i) {
            temp1[i] = -1;
        }

        // delete[] parent;
        // delete[] rank;

        parent = temp1;
        rank = temp2;
        capacity *= 2;
    }

public:
    void makeSet(int i) {
        if (i >= capacity) {
            expand();
        }
        parent[i] = i;
        rank[i] = 0;
    }

    int find(int i) {
        if (i < capacity && parent[i] != -1) {
            if (i != parent[i]) {
                parent[i] = find(parent[i]);
            }
            return parent[i];
        } else {
            makeSet(i);
            return i;
        }
    }

    void Union(int i, int j) {
        int i_ind = find(i);
        int j_ind = find(j);

        if (i_ind == j_ind) return;
        if (rank[i_ind] > rank[j_ind]) {
            parent[j_ind] = i_ind;
        } else {
            parent[i_ind] = j_ind;
            if (rank[i_ind] == rank[j_ind]) ++rank[j_ind];
        }
    }

    void print() {
        for (int i = 0; i < capacity; ++i) {
            std::cout << parent[i] << ' ';
        }
        std::cout << "\n";
    }

    DisjointSet(int capacity = 10) : parent(new int[capacity]), rank(new int[capacity]), capacity(capacity) {
        for (int i = 0; i < capacity; ++i) {
            this->parent[i] = -1;
        }
    }

    ~DisjointSet() {}
};

int main(int argc, char *argv[]) {
    int n = 0;
    int e = 0;
    int d = 0;
    bool answer = 1;

    std::cin >> n >> e >> d;
    DisjointSet set(n);

    for (int i = 0; i < e; ++i) {
        int x_i = 0;
        int x_j = 0;

        std::cin >> x_i >> x_j;

        set.Union(set.find(x_i - 1), set.find(x_j - 1));
    }

    for (int i = 0; i < d; ++i) {
        int x_i = 0;
        int x_j = 0;

        std::cin >> x_i >> x_j;

        if (set.find(x_i - 1) == set.find(x_j - 1)) {
            answer = 0;
        }
    }

    std::cout << answer;

    return EXIT_SUCCESS;
}