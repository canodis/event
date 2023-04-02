#include <iostream>

using namespace std;


void    put_empty(int level, int q)
{
    int width = 1;
    int step = 4;
    int i = 1;

    while (i <= level)
    {
        width += 2 * (2 + i);
        i++;
        width += step;
        if (i % 2 && i < level)
            step += 2;
    }
    width -= step;
    for (int i = 0; i < (width - q) / 2; i++)
        printf(" ");
}

void    put_line(int width)
{
    for (int y = 0; y < width; y++)
    {
        if (y == 0)
            printf("/");
        else if (y == width - 1)
            printf("\\\n");
        else
            printf("*");
    }
}
//+6 +7 +9 +10 +12 +13 +15
//2 8 15 24 34 46 59 74
void sastantua(int level)
{
    int floor = 1;
    int width = 1;
    int height;

    for (int i = 0; i < level; i++)
    {
        height = 2 + floor;
        for (int j = 0; j < height; j++)
        {
            width += 2;
            put_empty(level, width);
            put_line(width);
        }
        floor++;
        width += 4 + 2 * ((floor - 2) / 2);
    }
}

int main(int ac, char **av)
{
    sastantua(av[1][0] - 48);
}

//3 5 7  
//13 15 17 19
//25
//41

// 1 -> 7    2 -> 19    3 -> 33       4 -> 51      5 -> 71
//         + 12        +14           +18        +20

