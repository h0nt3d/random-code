#include <stdio.h>
#include <stdlib.h>

float* lowestValue(float arrayIn[], int numValues)
{
	float lowestVal = *arrayIn;
	float* lowestValPtr = arrayIn;
	for (int i = 1; i < numValues; i++) {
		if (*(arrayIn + i) < lowestVal) {
			lowestVal = *(arrayIn + i);
			lowestValPtr = arrayIn + i;
		}
		else
			i += 0;	
	}
	return lowestValPtr;
}

float* highestValue(float arrayIn[], int numValues)
{
	float highestVal = *arrayIn;
	float* highestValPtr = arrayIn;
	for (int i = 1; i < numValues; i++) {
		if (*(arrayIn + i) >highestVal) {
			highestVal = *(arrayIn + i);
			highestValPtr = arrayIn + i;
		}
		else
			i += 0;	
	}
	return highestValPtr;
}

int main(int argc, char** argv)
{
	int numValues = 0;
	printf("Type in number of data: ");
	scanf("%d", &numValues);
	if (numValues > 10) {
		printf("Number of Data cannot be more than 10!\n");
		return EXIT_SUCCESS;
	}
	else if (numValues <= 0) {
		printf("Number of Data cannot be zero or negative!\n");
		return EXIT_SUCCESS;
	}
		
	float array_in[numValues];
	int checkInput;
	
	printf("Data %d: ", 1);
	scanf("%f", array_in);

	if(*array_in <= 0) {
		printf("First input cannot be 0 or negative!\n");
		return EXIT_SUCCESS;
	}
	
	int num_non_negative = 1;
	int swap_values = 0;
	
	for (int i = 1 ; i < numValues; i++) {
		printf("Data %d: ", i + 1);
		scanf("%f", array_in + i);
		if (*(array_in + i) < 0) {
			i = numValues;
			swap_values = 1;
		}
		else {
			num_non_negative++;
		}
	}
	
	float* highest_value = highestValue(array_in, num_non_negative);
	float* lowest_value = lowestValue(array_in, num_non_negative);
	
	if (swap_values == 1) {
		float* swap = highest_value;
		highest_value = lowest_value;
		lowest_value = swap;
		printf("Swapped:\n");
		printf("Highest Value: %f\n", *highest_value);
		printf("Lowest Value: %f\n", *lowest_value);
	}
	
	
	printf("Array:\n");
	for (int i = 0; i < num_non_negative; i++) {
		printf("%f\n", *(array_in + i));
	}
	
	printf("Highest Value: %f\n", *highest_value);
	printf("Lowest Value: %f\n", *lowest_value);
	
	return EXIT_SUCCESS;
}
