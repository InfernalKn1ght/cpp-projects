#include <iostream>

struct List {
  int key;
  List *next;

  List(int key = 0) : key(key), next(nullptr) {}
};

class Queue {
private:
  List *front;
  List *back;
  int len;

public:
  bool isEmpty() { return len == 0; }

  int GetSize() { return len; }

  void PushBack(int key) {
    if (isEmpty())
      front->key = key;
    else {
      back->next = new List(key);
      back = back->next;
    }
    len++;
  }

  void PopFront() {
    if (len > 1) {
      List *temp = front->next;

      delete front;
      front = temp;
      len--;
    } else if (len == 1) {
      delete front;
      front = new List;
      back = front;
      len--;
    }
  }

  int GetFront() {
    if (len > 0)
      return front->key;
    else
      return -2;
  }

  void Print() {
    List *temp = front;
    for (int i = 0; i < len; ++i) {
      std::cout << temp->key << " ";
      temp = temp->next;
    }
    std::cout << '\n';
  }

  Queue(int len = 0) : front(new List), back(front), len(len) {}

  ~Queue() {}
};

int main(int argc, char *argv[]) {
  Queue arrivalQ;
  Queue durationQ;

  int size = 0;
  int n = 0;

  std::cin >> size >> n;

  for (int i = 0; i < n; ++i) {
    int arrival = 0;
    int duration = 0;

    std::cin >> arrival >> duration;

    arrivalQ.PushBack(arrival);
    durationQ.PushBack(duration);
  }

  for (int i = 0; i < n; ++i) {
  }

  durationQ.Print();
  arrivalQ.Print();

  return EXIT_SUCCESS;
}