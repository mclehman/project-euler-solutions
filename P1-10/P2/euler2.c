/* Project Euler Problem 2:

Each new term in the Fibonacci sequence is generated by adding the previous two terms.
By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four
million, find the sum of the even-valued terms.
*/

#include <stdio.h>

// Returns the sum of even-valued fibonacci numbers below limit
long evenFibsBelow(long limit) {
    long result = 0;

    long fib_1 = 1;
    long fib_2 = 2;
    long temp;

    // Steps through the Fibonacci sequence until 4,000,000 is reached
    while(fib_2 < limit) {
        // Even terms are added to the result
        if(fib_2 % 2 == 0) {
            result += fib_2;
        }

        // fib_1 is set to fib_2, fib_2 is set to fib_1 + fib_2
        temp   = fib_1;
        fib_1  = fib_2;
        fib_2 += temp;
    }

    return result;
}

// Prints the sum of even-valued fibonacci numbers below limit
int main() {
    long limit = 4000000;
    printf("The sum of even-valued fibonacci number below %ld is %ld\n",
           limit, evenFibsBelow(limit));
    return 0;
}