#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

const long long NUMBER = 600851475143;
const int ARRAY_SIZE = 1000; 

int get_dividers(long long number, long long *dividers) {
	int number_of_dividers = 0;
	for (size_t i = 2; i <= sqrt(number); i++) {
		if (number % i == 0) {
			*dividers = i;
			dividers++;
			*dividers = number / i;
			dividers++;
			number_of_dividers++;
		}
	}
	return number_of_dividers;
}

void print_array(long long *dividers, size_t array_size) {
	for (size_t i = 0; i < array_size; i++) {
		if (dividers[i] != 0) {
			printf("%lld\n", dividers[i]);
		}
	}
}

bool is_prime(long long number) {
    for(size_t i = 2; i <= sqrt(number); i++)
    {
        if(number % i == 0)
        {
            return false;
 	}
    }
    return true;
}

int filter_primes(long long *dividers, long long *primes, size_t array_size) {
	for (size_t i = 0; i < array_size; i++) {
		if (is_prime(dividers[i])) {
			primes[i] = dividers[i];
		}
	}
	return 0;
}

int main(void) {
	long long *dividers = malloc(sizeof(long long) * ARRAY_SIZE);
	int number_of_dividers = get_dividers(NUMBER, dividers);
	if (number_of_dividers == -1) {
		printf("Failed to find small dividers!");
		exit(1);
	}
	printf("The dividers of %lld:\n", NUMBER);
	print_array(dividers, ARRAY_SIZE);
	long long *prime_dividers = malloc(sizeof(long long) * number_of_dividers);
	filter_primes(dividers, prime_dividers, number_of_dividers);
	printf("The prime dividers of %lld:\n", NUMBER);
	print_array(prime_dividers, number_of_dividers);
	free(dividers);
	free(prime_dividers);
	return 0;
}
