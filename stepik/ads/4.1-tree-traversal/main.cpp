#include <iostream>

struct Node {
    long long data;
    Node *left;
    Node *right;
    Node(long long data = 0) : left(nullptr), right(nullptr) {}
};

void in_order(Node *root) {
    if (root->left) {
        in_order(root->left);
    }
    std::cout << root->data << " ";
    if (root->right) {
        in_order(root->right);
    }
}

void pre_order(Node *root) {
    std::cout << root->data << " ";
    if (root->left) {
        pre_order(root->left);
    }
    if (root->right) {
        pre_order(root->right);
    }
}

void post_order(Node *root) {
    if (root->left) {
        post_order(root->left);
    }
    if (root->right) {
        post_order(root->right);
    }
    std::cout << root->data << " ";
}

int main(int argc, char *argv[]) {
    int n = 0;
    std::cin >> n;
    Node **tree = new Node *[n];

    for (int i = 0; i < n; ++i) {
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

    in_order(tree[0]);
    std::cout << '\n';
    pre_order(tree[0]);
    std::cout << '\n';
    post_order(tree[0]);

    return EXIT_SUCCESS;
}