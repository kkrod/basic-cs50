#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < = 0 || height > 8);


    char block = '#';
    int i = 0;
    while (i < height)
    {
        for (int k = 0; k < height - (i + 1); k++)
        {
            printf(" ");
        }
        for (int j = 0 ; j <= i ; j++)
        {

            printf("%c", block);
        }
        printf("\n");
        i++;
    }

}