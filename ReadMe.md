# dec_to_ieee754_converter

The program is designed to convert decimal numbers to IEEE754. Used to create FPGA BRAM initiation files.

Create a file file_data.txt in the txt directory with the numbers that need to be converted to IEEE754 format.
The numbers in the created file should be described in a column, without commas.

Example:

			-14.7 
			
			0.78 
			
			140 

The converted values from the file will be saved in the IEEE754_result.txt file in 32-bit binary form. There is no need to create the IEEE754_result.txt file.
When converting again, delete the old IEEE754_result.txt file, otherwise new values will be added to the file with the old values.