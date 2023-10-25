#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    int *data = new int[10000000];

    for (int i = 0; i < 10000000; ++i) {
        data[i] = -1;
    }

    int n = 0;
    std::vector<std::string> answer;
    std::vector<std::string> book;

    std::cin >> n;
    int size = 0;

    for (int i = 0; i < n; ++i) {
        int number = 0;
        std::string command;
        std::string new_name;
        std::cin >> command >> number;

        if (command == "add") {
            std::cin >> new_name;
            data[number] = size;
            book.push_back(new_name);
            ++size;
        }
        else if (command == "find") {
            if (data[number] != -1) {
                answer.push_back(book[data[number]]);
            }
            else {
                answer.push_back("not found");
            }
        }
        else {
            data[number] = -1;
        }
    }

    for (int i = 0; i < answer.size(); ++i) {
        std::cout << answer[i] << '\n';
    }

    return EXIT_SUCCESS;
}