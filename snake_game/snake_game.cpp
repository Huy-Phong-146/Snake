#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

void gotoxy(int, int);

struct Point{
    int x;
    int y;

    Point() {}

    Point(const int& x, const int& y): x(x), y(y) {}
};

class Snake {
private:
    vector<Point> body;
    int length;

public:
    Snake(): length(3) {
        body = {Point(10, 10), Point(11, 10), Point(12, 10)};
    }

    void display(){
        for (int i = 0; i < length; i++) {
            gotoxy(body[i].x, body[i].y);
            cout << "X";
        }
    }

    void move(const char& direction){
        for (int i = length - 1; i > 0; --i)
            body[i] = body[i - 1];

        switch (direction) {
            case 'd': body[0].x++; break;
            case 'w': body[0].y--; break;
            case 'a': body[0].x--; break;
            case 's': body[0].y++;
        }
    }
};

int main() {
    Snake arbok;
    char direction = 'd';

    while (true) {
        if (kbhit())
            direction = getch();

        system("cls");
        arbok.display();
        arbok.move(direction);
        Sleep(150);
    }

    return 0;
}

void gotoxy( int column, int line ) {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord);
}
