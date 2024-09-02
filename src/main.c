// Project     : dec_to_ieee754_converter
// Autor       : Siarhei Baldzenka (sbaldzenka)
// Date        : 03.08.2017
// Description : Main project file


#include <stdio.h>
#include "../src/read_file.h"
#include "../src/ieee754x32.h"
#include "../src/write_file.h"

int main(int argc, char *argv[])
{
    float data[100];
    int i = 0;
    int k;
    int ieee754_data[31];
    int number_p;

    puts("-------------------------------------------------------------------------------\n");
    puts("                         -- floating_point_ieee754 --\n");
    puts("-------------------------------------------------------------------------------\n");
    puts("Create file \"file_data.txt\" with data and enter number:\n");
    scanf("%d", &number_p);
    puts("Number confirm.\n");

    for (i = 0; i < number_p; i++)
    {
        data[i] = read_data_file(i);
        printf("read data = %f\n", data[i]);

        for (k = 31; k > 0; k--)
        {
            ieee754_data[k] = convert_ieee754(data[i], k);
            write_data_file(ieee754_data[k], 0);
        }

        ieee754_data[0] = convert_ieee754(data[i], 0);
        write_data_file(ieee754_data[0], 1);
    }

    puts("Data was converted.\n");

    system("PAUSE");
    return(0);
}
