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
#include "../src/ieee754x32.h"

int convert_dec2bin(int data, int n)
{
    int i = 0;
    float calc[31];
    float frac;
    int bin_inv[31];
    int l = 31;
    char flag = 0;
    int k = 0;
    int count = 0;
    int bin[32];

    calc[0] = (float)data;

    for (i = 0; i <= 31; i++)
    {
        calc[i+1] = calc[i] / 2;
        frac = calc[i + 1] - (int)calc[i + 1];

        if (frac == 0.f)
            bin_inv[i] = 0;
        else
            bin_inv[i] = 1;

        calc[i + 1] = (int)calc[i + 1];
    }

    count = 0;

    for(l = 31; l >= 0; l--)
    {
        if (bin_inv[l] == 1)
        {
            flag = 1;
        }

        if (flag == 1)
        {
            bin[k] = bin_inv[l];
            count = count+1;
            bin[32] = count;
            k = k + 1;
        }
    }

    flag = 0;
    k = 0;
    i = 0;
    l = 31;

    return(bin[n]);
}

int convert_frac2bin(float data, int n)
{
    int i;
    float calc[31];
    int k = 0;
    int bin[31];

    calc[0] = data;

    for (i = 0; i <= 31 ;i++)
    {
        calc[i + 1] = calc[i] * 2;

        if (calc[i + 1] > 1)
        {
            bin[k] = 1;
            calc[i + 1] = calc[i + 1] - (int)calc[i + 1];
        }
        else
            bin[k] = 0;

        k = k + 1;
    }

    i = 0;
    k = 0;

    return(bin[n]);
}

int convert_exp2bin(int data, int n)
{
    int i = 0;
    float calc[7];
    float frac;
    int bin_inv[7];
    int l = 7;
    int k = 0;
    int bin[7];

    calc[0] = (float)data;

    for (i = 0; i <= 7; i++)
    {
        calc[i + 1] = calc[i] / 2;
        frac = calc[i + 1] - (int)calc[i + 1];

        if (frac == 0.f)
            bin_inv[i] = 0;
        else
            bin_inv[i] = 1;

        calc[i + 1] = (int)calc[i + 1];

    }

    for(l = 7; l >= 0; l--)
    {
        bin[k] = bin_inv[l];
        k = k + 1;
    }

    k = 0;
    i = 0;
    l = 31;

    return(bin[n]);
}

int convert_ieee754(float data, int n)
{
    int word[31];
    int k = 0;
    int decimal;
    int bin_dec[32];
    int count = 0;
    float fractal;
    int bin_frac[31];
    int mantissa[22];
    int dec_exp;
    int exponent[7];
    int m = 0;

    if (data > 0)
        word[31] = 0;
    else
    {
        word[31] = 1;
        data = data * (-1);
    }

    decimal = (int)data;

    if (decimal > 0)
    {
        count = convert_dec2bin(decimal, 32);

        for (k = 0; k < count; k++)
        {
            bin_dec[k] = convert_dec2bin(decimal, k);
        }
    }

    fractal = data - decimal;

    for (k = 0; k < 31; k++)
    {
        bin_frac[k] = convert_frac2bin(fractal, k);
    }

    if (decimal == 1)
    {
        for (k = 0; k < count - 1; k++)
        {
            mantissa[k] = bin_dec[k + 1];
        }

        for (k = count - 1; k <= 22; k++)
        {
            mantissa[k] = bin_frac[k - count + 1];
        }

        dec_exp = 127;
    }
    else if (decimal > 1)
    {
        for (k = 0; k < count - 1; k++)
        {
            mantissa[k] = bin_dec[k + 1];
        }

        for (k = count - 1; k <= 22; k++)
        {
            mantissa[k] = bin_frac[k - count + 1];
        }

        dec_exp = 127 + count - 1;
    }
    else
    {
        for (k = 0; k <= 22; k++)
        {
            mantissa[k] = bin_frac[k + 3];
        }

        dec_exp = 124;
    }

    for (k = 0; k < 8; k++)
    {
        exponent[k] = convert_exp2bin(dec_exp, k);
    }

    m = 0;

    for (k = 30; k >= 23 ; k--)
    {
        word[k] = exponent[m];
        m = m+1;
    }

    m = 0;

    for (k = 22; k >= 0 ; k--)
    {
        word[k] = mantissa[m];
        m = m + 1;
    }

    return(word[n]);
}
