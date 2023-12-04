// N! = 1*2*3*...*N, N >= 0
// 0! = 1
// 4! = 1*2*3*4

#include <stdio.h>

int main() {
    int n;
    long long factorial = 1; // long long to handle larger numbers
    
    for(;;) { // An infinite for loop
        printf("Enter a non-negative integer to calculate its factorial: ");
        scanf("%d", &n);

        if(n < 0) {
            printf("Factorial is not defined for negative numbers.\n");
        } else {
            break; // Exit the loop if a valid number is entered
        }
    }

    // Use a for loop to calculate the factorial
    int i = 1;
    while(i <= n) {
        factorial *= i; // factorial = factorial * i
        i++;
    }

    // Use an if statement to check for the special case of 0! which is 1
    if(n == 0) {
        factorial = 1;
    }
    printf("Factorial of %d is %lld\n", n, factorial);
    
	// Print some facts some numbers
	printf( "Some interesting fact about number %d:\n\t", n );
    
    if(n == 0) {
        printf("In many cultures, the concept of zero was not recognized until much later in history. For example, the ancient Greeks debated whether zero could be considered a number at all.\n");
    } else if(n == 2) {
        printf("In many cultures, the number two is often associated with balance, duality, and relationships, such as yin and yang in Chinese philosophy.\n");
    } else if(n == 7) {
        printf("In many mythologies and religions, the number seven holds special significance, such as the seven chakras in Hinduism and the seven deadly sins in Christianity.\n");
    } else {
        printf("Ooops! I know nothing interesting about number %d\n", n);
    }



    return 0;
}
