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
        cout << " ";
}

void    put_line(int width, int floor, int level, int heigth)
{
    int door = 1 + 2 * ((floor - 1) / 2);

    for (int x = 0; x < width; x++)
    {
        if (x == 0)
            cout << "/";
        else if (x == width - 1)
            cout << "\\\n";
        else
        {
            if (floor == level && x >= (width - door) / 2
					&& x < (width + door) / 2 && 2 + floor - heigth <= door)
				if (door >= 5 && heigth == 2 + floor - door / 2 - 1
						&& x == (width + door) / 2 - 2)
					cout << '$';
				else
					cout << '|';
			else
				cout << '*';
        }
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
            put_line(width, floor, level, j);
        }
        floor++;
        width += 4 + 2 * ((floor - 2) / 2);
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    sastantua(atoi(av[1]));
}

