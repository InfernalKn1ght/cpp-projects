#include <algorithm>
#include <iostream>

struct Node {
    long long data;
    Node *left;
    Node *right;
    Node *parent;
    int height;

    Node(long long data = 0, int height = 0) : left(nullptr), right(nullptr), height(height), data(data), parent(nullptr) {}
};

class Tree {
private:
    void print_subtree(Node *&root, int depth) {
        if (root == nullptr) {
            return;
        }
        print_subtree(root->right, depth + 1);
        for (int i = 0; i < depth; ++i) {
            std::cout << "\t";
        }
        std::cout << root->data << "|" << root->height << "|";
        if (root->parent) std::cout << root->parent->data << "|";
        std::cout << std::endl;
        print_subtree(root->left, depth + 1);
    }

    void fix_subtree(Node *&root) {
        if (!root) return;
        root->height = std::max(get_height(root->left), get_height(root->right)) + 1;
        Node *temp = rebalance(root);
        if (temp) root = temp;
        if (root->parent) fix_subtree(find(root->parent->data));
    }

    Node *&get_node(Node *&root, int key) {
        if (!root || root->data == key) {
            return root;
        }
        if (key < root->data) {
            return get_node(root->left, key);
        } else {
            return get_node(root->right, key);
        }
    }

public:
    Node *root;

    Node *rebalance(Node *root) {
        if (!root || std::abs(get_height(root->left) - get_height(root->right)) <= 1) {
            return nullptr;
        }
        if (get_height(root->right) - get_height(root->left) > 1) {
            if (get_height(root->right->right) >= get_height(root->right->left)) {
                Node *temp = root;

                root = root->right;
                temp->right = temp->right->left;
                root->left = temp;

                root->parent = temp->parent;

                temp->parent = root;
                if (temp->right) temp->right->parent = temp->right;
            } else {
                Node *temp = root;
                Node *temp1 = root->right->left->left;
                Node *temp2 = root->right->left->right;

                temp->right->left->parent = temp->parent;

                root = root->right->left;

                root->right = temp->right;
                root->right->left = temp2;

                root->left = temp;
                root->left->right = temp1;
            }
        } else {
            if (get_height(root->left->left) >= get_height(root->left->right)) {
                Node *temp = root;

                root = root->left;
                temp->left = temp->left->right;
                root->right = temp;

                root->parent = temp->parent;

                temp->parent = root;
                if (temp->left) temp->left->parent = temp->left;
            } else {
                Node *temp = root;
                Node *temp1 = root->left->right->right;
                Node *temp2 = root->left->right->left;

                temp->left->right->parent = temp->parent;

                root = root->left->right;

                root->left = temp->left;
                root->left->right = temp2;

                root->right = temp;
                root->right->left = temp1;
            }
        }
        root->right->height = std::max(get_height(root->right->right), get_height(root->right->left)) + 1;
        root->left->height = std::max(get_height(root->left->right), get_height(root->left->left)) + 1;
        root->height = std::max(get_height(root->left), get_height(root->right)) + 1;

        if (root) {
            if (root->right) root->right->parent = root;
            if (root->left) root->left->parent = root;
            if (root->right->right) root->right->right->parent = root->right;
            if (root->right->left) root->right->left->parent = root->right;
            if (root->left->right) root->left->right->parent = root->left;
            if (root->left->left) root->left->left->parent = root->left;
        }

        return root;
    }

    void update_height(Node *root) {
        if (!root) return;
        root->height = std::max(get_height(root->left), get_height(root->right)) + 1;
        update_height(root->parent);
    }

    void insert(long long key) {
        if (get_height(root) == 0) {
            root->data = key;
            root->height++;
        } else {
            Node *temp = root;
            while (temp->left || temp->right) {
                if (key < temp->data) {
                    if (!temp->left) break;
                    temp = temp->left;
                } else {
                    if (!temp->right) break;
                    temp = temp->right;
                }
            }

            if (temp->data > key) {
                temp->left = new Node;
                temp->left->parent = temp;
                temp->left->data = key;
                temp->left->height++;
            } else {
                temp->right = new Node;
                temp->right->parent = temp;
                temp->right->data = key;
                temp->right->height++;
            }
            fix_subtree(find(temp->data));
        }
    }

    Node *&find(int key) {
        return get_node(root, key);
    }

    void remove(int key) {
        Node *&temp_root = find(key);

        if (!temp_root) return;

        if (!temp_root->left && !temp_root->right) {
            temp_root = nullptr;
        } else if (temp_root->left && !temp_root->right) {
            temp_root->left->parent = temp_root->parent;
            temp_root = temp_root->left;
        } else if (!temp_root->left && temp_root->right) {
            temp_root->right->parent = temp_root->parent;
            temp_root = temp_root->right;
        } else {
            Node *temp = temp_root->left;
            if (!temp->right) {
                temp->right = temp_root->right;

                temp->parent = temp_root->parent;

                temp_root = temp;
            } else {
                while (temp->right->right) {
                    temp = temp->right;
                }
                Node *temp1 = temp->right;
                temp->right = nullptr;

                temp1->left = temp_root->left;
                temp1->right = temp_root->right;

                temp1->parent = temp_root->parent;

                temp_root = temp1;
            }
        }

        if (temp_root) {
            if (temp_root->right) {
                temp_root->right->parent = temp_root;
                if (temp_root->right->right) temp_root->right->right->parent = temp_root->right;
                if (temp_root->right->left) temp_root->right->left->parent = temp_root->right;
            }
            if (temp_root->left) {
                temp_root->left->parent = temp_root;
                if (temp_root->left->right) temp_root->left->right->parent = temp_root->left;
                if (temp_root->left->left) temp_root->left->left->parent = temp_root->left;
            }
        }

        fix_subtree(temp_root);
    }

    int get_height(Node *root) {
        if (root) {
            return root->height;
        }
        return 0;
    }

    void update_tree_height() {
        update_height(root);
    }

    int get_tree_height() {
        return get_height(root);
    }

    Node *get_root() {
        return root;
    }

    void print() {
        print_subtree(root, 0);
        std::cout << '\n'
                  << '\n';
    }

    Node *max() {
        Node *temp = root;
        while (temp->right) {
            temp = temp->right;
        }
        return temp;
    }

    Tree() : root(new Node) {}
};

Node *merge_with_root(Node *v1, Node *v2, Node *T) {
    T->left = v1;
    T->right = v2;

    T->height = std::max(v1->height, v2->height) + 1;
    T->parent = nullptr;

    v1->parent = T;
    v2->parent = T;

    return T;
}

Node* avl_merge_with_root(Node *v1, Node *v2, Node *T) {
    if (std::abs(v1->height - v2->height) <= 1) {
        T = merge_with_root(v1, v2, T);
        return T;
    }
    else if (v1->height > v2->height) {
        Node* temp_T = avl_merge_with_root(v1->right, v2, T);
        v1->right = temp_T;
        temp_T->parent = v1;
        return ;
    }
}

// Tree *merge(Tree *v1, Tree *v2) {
//     Tree *T = new Tree;
//     T->root = v1->max();
//     v1->max()->parent = nullptr;
//     v1->remove(v1->max()->data);
//     return merge_with_root(v1, v2, T);
// }

int main(int argc, char *argv[]) {

    Tree *tree1 = new Tree;
    Tree *tree2 = new Tree;
    Tree *tree3 = new Tree;

    tree1->insert(10);

    tree2->insert(3);
    tree2->print();
    tree2->insert(4);
    tree2->print();
    tree2->insert(5);
    tree2->print();
    tree2->insert(1);
    tree2->print();
    tree2->insert(6);

    tree2->print();

    tree3->insert(36);
    tree3->insert(3);
    tree3->insert(19);
    tree3->insert(8);
    tree3->insert(9);
    tree3->insert(22);
    tree3->insert(15);
    tree3->insert(14);
    tree3->insert(13);
    tree3->insert(23);
    tree3->insert(24);
    tree3->insert(25);
    tree3->insert(26);
    tree3->insert(27);
    tree3->insert(28);
    tree3->insert(28);

    tree3->print();

    tree1->print();

    return EXIT_SUCCESS;
}