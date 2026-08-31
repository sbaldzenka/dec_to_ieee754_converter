/*
---------------------------------------------------------------------------------------

MIT License

Copyright (c) 2026 Siarhei Baldzenka

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

---------------------------------------------------------------------------------------

project     : dec_to_ieee754_converter
version     : 1.1
date        : 03.08.2017
author      : siarhei baldzenka
e-mail      : sbaldzenka@proton.me
description : https://github.com/sbaldzenka/dec_to_ieee754_converter

---------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "../src/read_write_file.h"

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

void write_data_file(int data, int end)
{
    FILE *data_out = fopen("../txt/ieee754_result.txt", "a");

    if (end == 0)
        fprintf(data_out,"%d", data);
    else
        fprintf(data_out,"%d\n", data);

    fclose(data_out);
}