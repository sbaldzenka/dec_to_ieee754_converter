// Project     : dec_to_ieee754_converter
// Autor       : Siarhei Baldzenka (sbaldzenka)
// Date        : 03.08.2017
// Description : Read file function

#include <stdio.h>
#include <stdlib.h>
#include "../src/read_file.h"

float read_data_file(int count)
{
    char buffer[10];
    double data_in;
    int i = -1;
    float buffer_massiv[100];

    FILE *file = fopen("../txt/file_data.txt", "r+");

    while (fgets (buffer, 10, file) != NULL)
    {
        data_in= atof(buffer);
        i = i + 1;
        buffer_massiv[i]= (float)data_in;
    }

    fclose(file);
    i = -1;

    return(buffer_massiv[count]);
}
