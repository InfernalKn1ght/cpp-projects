#include <iostream>

class Stack {
private:
    int *data;
    int top;
    int len;

    void expand() {
        int *temp = new int[len * 2];

        for (int i = 0; i < len; ++i) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        len *= 2;
    }

    bool validLen() { return top < len; }

public:
    bool isEmpty() { return top == 0; }

    void Push(int key) {
        if (!validLen()) {
            expand();
        }

        data[top] = key;
        top++;
    }

    void Pop() {
        if (!isEmpty()) {
            top--;
        }
    }

    int getTop() {
        if (!isEmpty()) {
            return data[top - 1];
        } else {
            return -1;
        }
    }

    int getLen() { return top; }

    Stack(int len = 1) : data(new int[len]), top(0), len(len) {}
    ~Stack() { delete[] data; }
};

class MaxStack {
private:
    Stack *data;
    Stack *maxData;

public:
    int max() { return maxData->getTop(); }

    void push(int key) {
        data->Push(key);
        maxData->Push(std::max(key, maxData->getTop()));
    }

    void pop() {
        data->Pop();
        maxData->Pop();
    }

    bool isEmpty() { return data->isEmpty(); }

    int getLen() { return data->getLen(); }

    int getTop() { return data->getTop(); }

    MaxStack() : data(new Stack), maxData(new Stack) {}
    ~MaxStack() {
        delete data;
        delete maxData;
    }
};

class MaxQueue {
private:
    MaxStack *put;
    MaxStack *take;

public:
    bool isEmpty() { return put->isEmpty() && take->isEmpty(); }

    void PopFront() {
        if (!take->isEmpty()) {
            take->pop();
        } else if (!put->isEmpty()) {
            while (!put->isEmpty()) {
                take->push(put->getTop());
                put->pop();
            }
            take->pop();
        }
    }

    void push(int key) { put->push(key); }

    int max() {
        if (!isEmpty()) {
            return std::max(put->max(), take->max());
        } else {
            return -1;
        }
    }

    int getLen() { return put->getLen() + take->getLen(); }

    MaxQueue() : put(new MaxStack), take(new MaxStack) {}
    ~MaxQueue() {
        delete put;
        delete take;
    }
};

int main(int argc, char *argv[]) {
    MaxQueue q;

    int n = 0;
    int m = 0;

    std::cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::cin >> m;

    int *answer = new int[n - m + 1];

    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (q.getLen() < m) {
            q.push(arr[i]);
        } else {
            answer[j] = q.max();
            j++;
            q.PopFront();
            q.push(arr[i]);
        }
    }
    answer[j] = q.max();

    for (int i = 0; i < n - m + 1; ++i) {
        std::cout << answer[i] << " ";
    }

    return EXIT_SUCCESS;
}