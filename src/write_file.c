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
