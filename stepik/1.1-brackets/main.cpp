#include <iostream>

class Stack
{
private:
    int len;
    int top;
    int *array;

    void expand()
    {
        int *temp = new int[len * 2];    
    
        for (int i = 0; i < len; ++i)    
        {    
            temp[i] = array[i];    
        }    
    
        delete[] array;
        array = temp;
        len *= 2;
    }

public:
    int getTop()
    {
        if (!isEmpty())
            return array[top - 1];
        else
            return -1;
    }

    void push(int key)
    {
        top++;
        if (top > len)
            expand();
        array[top - 1] = key;
    }

    bool isEmpty()
    {
        return top == 0;
    }

    void pop()
    {
        if (!isEmpty())
        {
            top -= 1;
        }
    }

    Stack(int len = 100, int top = 0) : len(len), top(top), array(new int[len]) {}

    ~Stack()
    {
        delete[] array;
    }
};

bool checkEntry(int key, int list[], int listLen)
{
    for (int i = 0; i < listLen; ++i)
    {
        if (key == list[i])
            return 1;
    }
    return 0;
}

int solution(std::string s)
{
    int list[] = {'(', ')', '[', ']', '{', '}'};

    Stack symbols;
    Stack symbolsIndex;

    for (int i = 0; i < s.size(); ++i)
    {
        if (checkEntry(s[i], list, 6))
        {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            {
                symbols.push(s[i]);
                symbolsIndex.push(i + 1);
            }
            else if (!symbols.isEmpty())
            {
                if ((s[i] == '}' && symbols.getTop() == '{') || (s[i] == ']' && symbols.getTop() == '[') || (s[i] == ')' && symbols.getTop() == '('))
                {
                    symbols.pop();
                    symbolsIndex.pop();
                }
                else
                    return i + 1;
            }
            else
                return i + 1;
        }
    }

    if (symbols.isEmpty())
        return -1;
    else
        return symbolsIndex.getTop();
}

int main(int argc, char *argv[])
{
    std::string s = "";

    std::cin >> s;

    int result = solution(s);

    if (result == -1)
        std::cout << "Success";
    else
        std::cout << result;

    return EXIT_SUCCESS;
}