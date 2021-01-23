#include <iostream>
#include <array>

using namespace std;

class Cell {
    char check;
public:
    Cell() {}
    Cell(char c);
    virtual int check_cell() {
        return 3;
    }; 
};

class FullCell: public Cell {

public:
    FullCell(char c): Cell(c) {}

    int check_cell() {
        return 1;
    }
};

class EmptyCell: public Cell {

public:
    EmptyCell(char c) : Cell(c) {}

    int check_cell() {
        return 0;
    }

};

template<int WIDTH, int HEIGHT>
class Maze {
public:
    Maze() {}

    void play() {
        
    }

    void setLayout(const char* layout) {
        for (int row = 0; row < HEIGHT; row++) {
            for (int col = 0; col < WIDTH; col++) { 
                cout << layout[row * WIDTH + col] << (col == WIDTH-1 ? "\n" : "");
            }
        }
    }
private:
    std::array<std::array<Cell, HEIGHT>, WIDTH> board;
};

int main() {
    const char* layout =
        "@@@@@@@@@"
        "@       @"
        "@ @@@@@ @"
        "@     @  "
        "@@@ @ @@@"
        "@   @   @"
        "@@@@@@@ @";

    Maze<9, 7> maze;

    maze.setLayout(layout);
    maze.play();
}