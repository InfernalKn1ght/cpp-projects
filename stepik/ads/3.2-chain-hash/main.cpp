#include <cmath>
#include <iostream>
#include <vector>
#define ll long long

ll h(std::string s, ll m) {
    const ll x = 263;
    const ll p = 1000000007;
    ll hash = 0;
    ll x_p = 1;

    for (ll i = 0; i < s.size(); ++i) {
        ll temp = (s[i] % p) * (x_p % p);
        hash += temp;
        hash %= p;
        x_p *= x;
        x_p %= p;
    }

    return hash % m;
}

struct Node {
    std::string data;
    Node *next;

    Node() : next(nullptr) {}
};

class List {
private:
    Node *root;
    ll size = 0;

public:
    void push_front(std::string key) {
        if (find(key) == 1) {
            return;
        }
        if (size == 0) {
            root->data = key;
            root->next = new Node;
        } else {
            Node *buf1 = root;
            Node *buf2 = new Node;
            buf2->data = key;
            root = buf2;
            root->next = buf1;
        }
        ++size;
    }

    void remove(std::string key) {
        int i = find_index(key);
        if (i == -1) {
            return;
        }
        if (i == 1) {
            root = root->next;
        } else {
            Node *temp = root;
            for (int i = 0; i < size; ++i) {
                if (temp->next->data == key) {
                    temp->next = temp->next->next;
                    break;
                }
                temp = temp->next;
            }
        }
        --size;
    }

    int find_index(std::string key) {
        Node *temp = root;
        for (int i = 0; i < size; ++i) {
            if (temp->data == key) {
                return i + 1;
            }
            temp = temp->next;
        }
        return -1;
    }

    bool find(std::string key) {
        if (find_index(key) == -1) {
            return 0;
        } else {
            return 1;
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    Node *get_root() {
        return root;
    }

    void print() {
        Node *temp = root;
        for (int i = 0; i < size; ++i) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }

    List(int size = 0) : root(new Node), size(size) {}
    ~List() {}
};

int main(int argc, char *argv[]) {
    ll n = 0;
    ll m = 0;
    std::cin >> m >> n;

    List **table = new List *[m];
    for (ll i = 0; i < m; ++i) {
        table[i] = new List;
    }

    std::vector<std::vector<std::string>> answer;

    for (ll i = 0; i < n; ++i) {
        std::string command;
        std::string name;
        std::cin >> command;
        if (command == "check") {
            ll j = 0;
            std::cin >> j;
            std::vector<std::string> buf;
            if (!table[j]->isEmpty()) {
                Node *temp = table[j]->get_root();
                while (temp != nullptr) {
                    buf.push_back(temp->data);
                    temp = temp->next;
                }
                answer.push_back(buf);
            }
            else {
                buf.push_back("");
                answer.push_back(buf);
            }
        } else {
            std::cin >> name;

            if (command == "add") {
                table[h(name, m)]->push_front(name);
            } 
            if (command == "del") {
                table[h(name, m)]->remove(name);
            } 
            if (command == "find") {
                std::vector<std::string> buf;
                if (table[h(name, m)]->find(name)) {
                    buf.push_back("yes");
                } else {
                    buf.push_back("no");
                }
                answer.push_back(buf);
            }
        }
    }

    for (int i = 0; i < answer.size(); ++i) {
        for (int j = 0; j < answer[i].size(); ++j) {
            std::cout << answer[i][j] << " ";
        }
        std::cout << '\n';
    }

    return EXIT_SUCCESS;
}