/*
 * Source: http://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
 * Ref: http://www.ics.uci.edu/~eppstein/161/960109.html
 *
 * Method used is "recursive powering"
 */
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

void multiply(mpz_t F[2][2], mpz_t M[2][2]);
 
void power(mpz_t F[2][2], int n);
 
/* function that returns nth Fibonacci number */
void fib(int n, mpz_t result)
{
	mpz_t F[2][2];
	mpz_init(F[0][0]);
	mpz_init(F[0][1]);
	mpz_init(F[1][0]);
	mpz_init(F[1][1]);

	mpz_set_ui(F[0][0], 1);
	mpz_set_ui(F[0][1], 1);
	mpz_set_ui(F[1][0], 1);
	mpz_set_ui(F[1][1], 0);

	if (n == 0)
		return;
	power(F, n-1);
	mpz_set(result, F[0][0]);
}
 
/* Optimized version of power() in method 4 */
void power(mpz_t F[2][2], int n)
{
	if( n == 0 || n == 1)
		return;
	
	mpz_t M[2][2];
	mpz_init(M[0][0]);
	mpz_init(M[0][1]);
	mpz_init(M[1][0]);
	mpz_init(M[1][1]);

	mpz_set_ui(M[0][0], 1);
	mpz_set_ui(M[0][1], 1);
	mpz_set_ui(M[1][0], 1);
	mpz_set_ui(M[1][1], 0); 
	
	power(F, n/2);
	multiply(F, F);
 
	if (n%2 != 0)
		 multiply(F, M);

	mpz_clear(M[0][0]);
	mpz_clear(M[0][1]);
	mpz_clear(M[1][0]);
	mpz_clear(M[1][1]);
}
 
void multiply(mpz_t F[2][2], mpz_t M[2][2])
{
	mpz_t x,y,z,w;
	mpz_inits(x,y,z,w,NULL);
	mpz_mul(x, F[0][0], M[0][0]);
	mpz_addmul(x, F[0][1], M[1][0]);
	mpz_mul(y, F[0][0], M[0][1]);
	mpz_addmul(y, F[0][1], M[1][1]);
	mpz_mul(z, F[1][0], M[0][0]);
	mpz_addmul(z, F[1][1], M[1][0]);
	mpz_mul(w, F[1][0], M[0][1]);
	mpz_addmul(w, F[1][1], M[1][1]);
 
	mpz_set(F[0][0], x);
	mpz_set(F[0][1], y);
	mpz_set(F[1][0], z);
	mpz_set(F[1][1], w);

	mpz_clears(x,y,z,w,NULL);
}
 
/* Driver program to test above function */
int main(int argc, char* argv[])
{
	int n;
	mpz_t result;
	mpz_init(result);
	if (argc == 2) {
		n = atoi(argv[1]); 
		fib(n, result);
		gmp_printf("%dth Fibonacci number: %Zd\n", n, result);
		mpz_clear(result);
		return 0;
	}
	mpz_clear(result);	
	printf("Specify which Fibonacci number has to be found.\n");
	return 1;
}
