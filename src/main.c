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
#include "../src/read_write_file.h"
#include "../src/ieee754x32.h"

int main(int argc, char *argv[])
{
    float data[10000];
    int i = 0;
    int k;
    int ieee754_data[31];
    int number_p;

    puts("-------------------------------------------------------------------------------\n");
    puts("                         -- dec_to_ieee754_converter --\n");
    puts("-------------------------------------------------------------------------------\n");
    puts("Create file \"file_data.txt\" with data and enter number (max = 10000) of values:\n");
    scanf("%d", &number_p);
    puts("Number confirm.\n");

    for (i = 0; i < number_p; i++)
    {
        data[i] = read_data_file(i);
        printf("read data[%d] = %3.f\n", i, data[i]);

        for (k = 31; k > 0; k--)
        {
            ieee754_data[k] = convert_ieee754(data[i], k);
            write_data_file(ieee754_data[k], 0);
        }

        ieee754_data[0] = convert_ieee754(data[i], 0);
        write_data_file(ieee754_data[0], 1);
    }

    puts("\n");
    puts("Data was converted.\n");

    system("read -p 'Press Enter to continue...' var");
    return(0);
}
