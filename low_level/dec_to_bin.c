#include <stdio.h>
#include <stdlib.h>


char* dec2bin(int dec_input)
{
	int index = 0;
	char* result = (char *) malloc(dec_input * sizeof(char));
	while (dec_input != 0) {
		result[index] = '0' + dec_input % 2;
		dec_input /= 2;
		index++;
	}
	int reverse_index = 0;
	int last_index = index - 1;
	char curr_val = '0';
	
	
	while (reverse_index < last_index) {
		curr_val = result[reverse_index];
		result[reverse_index] = result[last_index];
		result[last_index] = curr_val;
		last_index--;
		reverse_index++;
	}


	return result;
}

int main(int argc, char** argv)
{
	printf("%s\n", dec2bin(atoi(argv[1])));
	return EXIT_SUCCESS;
}
