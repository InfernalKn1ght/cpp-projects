#include <iostream>
#include <vector>

struct Node {
    long long data;
    Node *left;
    Node *right;
    Node(long long data = 0) : left(nullptr), right(nullptr) {}
};

void tree_check(Node *root, std::vector<long long> &v) {
    if (root->left) {
        tree_check(root->left, v);
    }

    v.push_back(root->data);

    if (root->right) {
        tree_check(root->right, v);
    }
}

int main(int argc, char *argv[]) {
    int n = 0;
    std::cin >> n;
    int size = n > 0 ? n : 1;
    Node **tree = new Node *[size];

    for (int i = 0; i < size; ++i) {
        tree[i] = new Node;
    }

    for (int i = 0; i < n; ++i) {
        int left = 0;
        int right = 0;
        long long data = 0;
        std::cin >> data >> left >> right;

        tree[i]->data = data;

        if (left != -1) {
            tree[i]->left = tree[left];
        }
        if (right != -1) {
            tree[i]->right = tree[right];
        }
    }

    std::vector<long long> v;

    tree_check(tree[0], v);

    bool f = 1;

    for (int i = 0; i < n - 1; ++i) {
        if (v[i] > v[i + 1]) {
            f = 0;
            break;
        }
    }

    if (f) {
        std::cout << "CORRECT";
    } else {
        std::cout << "INCORRECT";
    }

    return EXIT_SUCCESS;
}