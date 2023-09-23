#include <iostream>
#include <string>
#define ll long long

struct group
{
    int num;
    std::string side;
    std::string position;

    group(int num = 0, std::string side = "", std::string position = "") : num(num), side(side), position(position) {}
};

int main(int argc, char *argv[])
{
    int m =0; 
    std::cin >> m;
    group *test = new group[m];

    for (int i = 0; i < m; ++i)
    {
        std::cin >> test[i].num >> test[i].side >> test[i].position;
    }

    /*for (int i = 0; i < m; ++i)
    {
        std::cout << test[i].num << " " << test[i].position << " " << test[i].side << "\n";
    }*/
    delete[] test;

    return EXIT_SUCCESS;
}