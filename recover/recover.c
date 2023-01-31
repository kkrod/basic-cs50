#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover images.raw\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }
    int n = 0;
    const int BLOCK_SIZE = 512;
    uint8_t buffer[BLOCK_SIZE];
    FILE *output = NULL;
    char image[10];
    while (fread(buffer, BLOCK_SIZE, 1 , input) == 1)
    {
        if (buffer[0]== 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (output != NULL)
            {
                fclose(output);
                output = NULL;
            }
            sprintf(image, "%03d.jpg", n);

            output = fopen(image, "w");
            if (output == NULL)
            {
                printf("Could not open file.\n");
                return 3;
            }
            fwrite(buffer, BLOCK_SIZE, 1, output);
            n++;
        }
        else
        {
            if (output != NULL)
            {
                fwrite(buffer, BLOCK_SIZE, 1, output);
            }
        }
    }
    fclose(output);
    fclose(input);
    return 0;
}