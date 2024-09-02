// Project     : dec_to_ieee754_converter
// Autor       : Siarhei Baldzenka (sbaldzenka)
// Date        : 03.08.2017
// Description : Write file function

#include <stdio.h>
#include "../src/write_file.h"

void write_data_file(int data, int end)
{
    FILE *data_out = fopen("../txt/ieee754_result.txt", "a");

    if (end == 0)
        fprintf(data_out,"%d", data);
    else
        fprintf(data_out,"%d\n", data);

    fclose(data_out);
}
