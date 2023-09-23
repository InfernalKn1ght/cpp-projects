#include <iostream>

struct List
{
    int key;
    List *next;

    List(int key = 0) : key(key), next(nullptr) {}
};

class Queue
{
private:
    List *front;
    int len;

public:
    bool isEmpty()
    {
        return len == 0;
    }

    void PushBack(int key)
    {
        if (!isEmpty())
            front->next = new List(key);
        else 
            front->key = key;
        len++;
    }

    int PopFront()
    {
        if (!isEmpty())
        {
            int key = front->key;
            front = front->next;
            len--;
            return key;
        }
        else
            return -1;
    }

    Queue(int len = 0) : front(new List), len(len) {}

    ~Queue()
    {
        delete front;
    }
};

int main(int argc, char *argv[])
{
    Queue q;

    q.PushBack(3);
    q.PushBack(5);

    std::cout << q.PopFront() << "\n";

    std::cout << q.PopFront() << "\n";

    std::cout << q.PopFront() << "\n";

    return EXIT_SUCCESS;
}