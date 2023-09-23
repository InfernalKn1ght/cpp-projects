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

    int GetSize()
    {
        return len;
    }

    void PushBack(int key)
    {
        if (!isEmpty())
            front->next = new List(key);
        else
            front->key = key;
        len++;
    }

    void PopFront()
    {
        if (len > 1)
        {
            List *temp = front->next;

            delete front;
            front = temp;
            len--;
        }
        else if (len == 1)
        {
            delete front;
            front = new List;
            len--;
        }
    }

    int GetFront()
    {
        if (!isEmpty())
            return front->key;
        else
            return -2;
    }

    Queue(int len = 0) : front(new List), len(len) {}

    ~Queue()
    {
        delete front;
    }
};

int main(int argc, char *argv[])
{
    Queue answer;
    Queue memory;
    int size = 0;
    int n = 0;

    std::cin >> size >> n;

    int prevDuration = 0;

    for (int i = 0; i < n; ++i)
    {
        int arrival = 0;
        int duration = 0;
        std::cin >> arrival >> duration;

        if (memory.GetFront() <= arrival)
        {
            memory.PopFront();
            memory.PushBack(duration);
            answer.PushBack(arrival);
        }
        else if (memory.GetSize() < size)
        {
            memory.PushBack(duration);
            answer.PushBack(prevDuration);
            prevDuration += duration;
        }
        else
        {
            answer.PushBack(-1);
        }
    }

    while (!answer.isEmpty())
    {
        std::cout << answer.GetFront() << "\n";
        answer.PopFront();
    }

    return EXIT_SUCCESS;
}