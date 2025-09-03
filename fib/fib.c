#include <stdio.h>

int recursive_fib(int num) 
{
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;
	else {
		return recursive_fib(num - 2) + recursive_fib(num - 1);
	}
}

int iterative_fib(int num) 
{
	int val = 0;
	int first_val = 0;
	int second_val = 1;
	if (num == 0)
		return 0;
	if (num == 1)
		return 1;
	else {
		for(int i = 2; i <= num; i++) {
			val = first_val + second_val;
			first_val = second_val;
			second_val = val;
		}
		return val;
	}
}

void print_results() {
	printf("Recursive Fibonacci: %d\n", recursive_fib(20));
	printf("Iterative Fibonacci: %d\n", iterative_fib(20));

}

int main()
{	print_results();
	return 0;	
}
