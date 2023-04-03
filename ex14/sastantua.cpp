#include <iostream>

using namespace std;

void    put_empty(int level, int q)
{
    int base = 7;
	int inc = 12;

	for (int increments = 1; increments < level; increments++)
	{
		base += inc;
		inc += (increments % 2 == 0 ? 4 : 2);
	}
    for (int i = 0; i < (base - q) / 2; i++)
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

