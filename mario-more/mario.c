#include <cs50.h>
#include <stdio.h>

int blocks(int i);
int spaces(int height, int i);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);

    int i = 0;
    while (i < height)
    {
        spaces(height,i);
        blocks(i);
        spaces(3,0);
        blocks(i);
        printf("\n");
        i++;
    }
}

int blocks(int i)
{
    for (int j = 0 ; j <= i ; j++)
    {
        printf("#");
    }
    return 0;
}

int spaces(int height, int i)
{
    for (int k = 1; k < height - i; k++)
    {
        printf(" ");
    }
    return 0;
}