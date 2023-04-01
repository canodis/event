#include <iostream>

using namespace std;

void    put_empty(int level, int floor)
{
    static int inc = 0;
    static bool check = false;

    
}

void    put_line(int width)
{
    for (int y = 0; y < width; y++)
    {
    }
}
//+6 +7 +9 +10 +12 +13 +15
//2 8 15 24 34 46 59 74
void sastantua(int level)
{
    int floor = 1;
    int width = 3;

    for (int i = 0; i < level; i++)
    {

        put_line(width);
        width += 2;
    }
    width += 6;
}

int main(int ac, char **av)
{
    sastantua(av[1][0] - 48);
}

//3 5 7  
//13 15 17 19
//25
//41