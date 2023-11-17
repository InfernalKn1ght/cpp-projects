#include <iostream>
#include <vector>

struct Node {
    long long data;
    Node *left;
    Node *right;
    int height;

    Node(long long data = 0, int height = 0) : left(nullptr), right(nullptr) {}
};

class Tree {
private:
    Node *root;

    void balance_tree(Node *&root) {
        if (!root || std::abs(get_height(root->left) - get_height(root->right)) <= 1) {
            return;
        }
        if (get_height(root->right) - get_height(root->left) > 1) {
            Node *temp = root;
            root = root->right;
            temp->right = root->left;
            root->left = temp;
        }
        else {
            Node *temp = root;
            root = root->left;
            temp->left = root->right;
            root->left = temp;
        }
    }

public:
    Tree() : root(new Node) {}

    int get_height(Node *root) {
        if (root) {
            return root->height;
        }
        return 0;
    }
};

int main(int argc, char *argv[]) {

    return EXIT_SUCCESS;
}