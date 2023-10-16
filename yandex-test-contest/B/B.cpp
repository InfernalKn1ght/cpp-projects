#include <iostream>
#include <string>
#define ll long long

enum class Side {
    None,
    Left,
    Right
};

enum class Position {
    None,
    Window,
    Aisle
};

struct Group {
    int num;
    Side side;
    Position position;

    Group(int num = 0, Side side = Side::None, Position position = Position::None) : num(num), side(side), position(position) {}
};

int main(int argc, char *argv[]) {
    char letters[7] = {'A', 'B', 'C', '_', 'D', 'E', 'F'};

    int n = 0;

    std::cin >> n;

    char **seats = new char *[n];

    for (int i = 0; i < n; ++i) {
        seats[i] = new char[7];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 7; ++j) {
            std::cin >> seats[i][j];
        }
    }

    int m = 0;
    std::cin >> m;
    Group *groups = new Group[m];

    for (int i = 0; i < m; ++i) {
        std::string side = "";
        std::string position = "";

        std::cin >> groups[i].num >> side >> position;

        if (side == "left") {
            groups[i].side = Side::Left;
        } else {
            groups[i].side = Side::Right;
        }

        if (position == "window") {
            groups[i].position = Position::Window;
        } else {
            groups[i].position = Position::Aisle;
        }
    }

    for (int i = 0; i < m; ++i) {
        int rowNum = 0;
        char *seatsLetters = new char[groups[i].num];
        char *bufferRow = new char[7];
        bool isFit = 0;

        for (int j = 0; j < n; ++j) {
            bool goodSeats = 1;
            rowNum = j + 1;

            for (int k = 0; k < 7; ++k) {
                bufferRow[k] = seats[j][k];
            }

            switch (groups[i].side) {
            case Side::Left:

                switch (groups[i].position) {
                case Position::Window: {
                    int seatsCounter = 0;

                    for (int k = 0; k < 3; ++k) {
                        if (seatsCounter < groups[i].num) {
                            if (seats[j][k] == '.') {
                                bufferRow[k] = 'X';
                                seatsLetters[seatsCounter] = letters[k];
                            } else {
                                goodSeats = 0;
                            }
                            ++seatsCounter;
                        } else {
                            break;
                        }
                    }
                    break;
                }
                case Position::Aisle: {
                    int seatsCounter = 0;

                    for (int k = 3 - groups[i].num; k <= 2; ++k) {
                        if (seatsCounter < groups[i].num) {
                            if (seats[j][k] == '.') {
                                bufferRow[k] = 'X';
                                seatsLetters[seatsCounter] = letters[k];
                            } else {
                                goodSeats = 0;
                            }
                            ++seatsCounter;
                        } else {
                            break;
                        }
                    }
                    break;
                }
                default:
                    break;
                }

                break;

            case Side::Right:

                switch (groups[i].position) {
                case Position::Window: {
                    int seatsCounter = 0;

                    for (int k = 7 - groups[i].num; k <= 6; ++k) {
                        if (seatsCounter < groups[i].num) {
                            if (seats[j][k] == '.') {
                                bufferRow[k] = 'X';
                                seatsLetters[seatsCounter] = letters[k];
                            } else {
                                goodSeats = 0;
                            }
                            ++seatsCounter;
                        } else {
                            break;
                        }
                    }
                    break;
                }
                case Position::Aisle: {
                    int seatsCounter = 0;

                    for (int k = 4; k < 7; ++k) {
                        if (seatsCounter < groups[i].num) {
                            if (seats[j][k] == '.') {
                                bufferRow[k] = 'X';
                                seatsLetters[seatsCounter] = letters[k];
                            } else {
                                goodSeats = 0;
                            }
                            ++seatsCounter;
                        } else {
                            break;
                        }
                    }

                    break;
                }
                default:
                    break;
                }

                break;

            default:
                break;
            }

            if (goodSeats) {
                isFit = 1;
                break;
            }
        }

        if (isFit) {
            std::cout << "Passengers can take seats: ";
            for (int j = 0; j < groups[i].num; ++j) {
                std::cout << rowNum << seatsLetters[j];
                if (j != groups[i].num - 1) {
                    std::cout << " ";
                }
            }
            std::cout << "\n";

            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 7; ++k) {
                    if (j == rowNum - 1) {
                        std::cout << bufferRow[k];
                    } else {
                        std::cout << seats[j][k];
                    }
                }
                std::cout << "\n";
            }

            for (int j = 0; j < 7; ++j) {
                if (bufferRow[j] == 'X') {
                    seats[rowNum - 1][j] = '#';
                }
            }
        } else {
            std::cout << "Cannot fulfill passengers requirements\n";
        }

        delete[] seatsLetters;
        delete[] bufferRow;
    }

    for (int i = 0; i < n; ++i) {
        delete seats[i];
    }
    delete[] seats;
    delete[] groups;

    return EXIT_SUCCESS;
}