#include <stdio.h>

void mult(int* a, int* b) {
    int res[] = {0, 0, 0, 0};
    res[0] = a[0]*b[0] + a[1]*b[2];
    res[1] = a[0]*b[1] + a[1]*b[3];
    res[2] = a[2]*b[0] + a[3]*b[2];
    res[3] = a[2]*b[1] + a[3]*b[3];
    for (int i = 0; i < 4; ++i)
        b[i] = res[i];
}

/** Calculates the fibonacci number at k.
 *  Fibonacci is defined as:
 *  Fibonacci(k) = Fibonacci(k - 1) + Fibonacci(k - 2)
 *  where:
 *     Fibonacci(0) = 1
 *     Fibonacci(1) = 1
 * @param k = the kth fibonacci number
 * @return the exact value of the fibonacci number
 *  
 *  Recall: The fibonacci sequence looks like
 *      1, 1, 2, 3, 5, 8, 13, 21, 34
 *  Example:
 *      fibonacci(5); //5
 *      fibonacci(6); //8
 *      fibonacci(8); //21
 */
int fibonacci(int n) {
    int P[] = {1, 1, 1, 0}, p[] = {1, 0, 0, 1};
    while (n) {
        if (n & 1) mult(P, p);
        mult(P, P);
        n >>= 1;
    }
    return p[1];
}

int main(void) {
    int k=5;

    printf("Fibonacci at %d is %d\n", k, fibonacci(k));
    k = 6;
    printf("Fibonacci at %d is %d\n", k, fibonacci(k));
    k = 7;
    printf("Fibonacci at %d is %d\n", k, fibonacci(k));

    return 0;
}
