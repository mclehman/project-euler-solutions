/*  Project Euler Problem 12:
	The sequence of triangle numbers is generated by adding the natural numbers.
	So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28.
	The first ten terms would be:

	1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

	Let us list the factors of the first seven triangle numbers:

		 1: 1
		 3: 1,3
		 6: 1,2,3,6
		10: 1,2,5,10
		15: 1,3,5,15
		21: 1,3,7,21
		28: 1,2,4,7,14,28

	We can see that 28 is the first triangle number to have over five divisors.

	What is the value of the first triangle number to have over five hundred divisors?
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Returns the number of divisors of parameter
int numDivisors (int n) {
	int result = 1; // include 1 by default

	if (n != 1) {
		result++;   // include n by default if n != 1
	}

	// Check for divisibility by natural numbers up to but not including n
	for (int div = 2; div < n; div++) {
		if (n % div == 0) {
			result++;
		}
	}

	return result;
}

// Returns the first triangle number to have over a target number of divisors
int firstToNDivisors(int targetDivisors) {
	int  index = 1;
	int  candidate = 0;
	bool searching = true;
	int divisors;

	while(searching) {
		/* The n-th triangle number is (n(n+1))/2. Importantly, n and n+1 are coprime,
		and only one is even */
		candidate = index*(index + 1)/2;

		// Associate 1/2 term with whichever of n and n+1 is even. Multiply to get total factors
		if (index % 2 == 0) {
			divisors = numDivisors(index/2) * numDivisors(index + 1);
		} else {
			divisors = numDivisors(index) * numDivisors((index + 1)/2);
		}

		if (divisors > targetDivisors) {
			searching = false;
		}

		index++;
	}

	return candidate;
}

// Prints the first triangle number to have over a target number of divisors
int main() {
	int targetDivisors = 500;

	printf("The first triangle number to have over %d divisors is %d\n",
	       targetDivisors, firstToNDivisors(targetDivisors));

	return 0;
}
