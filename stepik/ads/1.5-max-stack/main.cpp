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

  MaxStack() : data(new Stack), maxData(new Stack) {}
  ~MaxStack() {
    delete data;

    delete maxData;
  }
};

int main(int argc, char *argv[]) {
  MaxStack stack;

  int n = 0;
  std::cin >> n;
  int *answer = new int[n];
  int size = 0;

  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;

    if (s == "push") {
      int v = 0;
      std::cin >> v;
      stack.push(v);
    } else if (s == "pop") {
      stack.pop();
    } else {
      answer[size] = stack.max();
      size++;
    }
  }

  for (int i = 0; i < size; ++i) {
    std::cout << answer[i] << '\n';
  }

  for (int i = 0; i < n; ++i) {
  }

  return EXIT_SUCCESS;
}