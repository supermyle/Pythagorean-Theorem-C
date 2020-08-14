/* Author Supermyle 08/14/2020 */

#include <stdio.h>
#include <math.h>

/*
 * Function: scanvalid 
 * --------------------
 * scanvalid checks to see if user's input is a valid int if not it will prompt the user for valid int
 *
 * The first parameter is an int that takes the return value of scanf() which could be 1, 0, or EOF  
 * 1 means valid input, 0 means invalid input, and EOF means End Of File or (-1) 
 * If the input equals 0 reprompt user to enter a valid input
 *
 * The second parameter is an int* that points to the variable that the user is entering for input 
 * scanvalid then use the int* to set the new int value after it reprompts the user to enter a valid input
 */

void scanvalid(int, int*); //Function to validate input as int
double pythag(int, int); //Function to calculate c value using pythagorean theorem, takes a and b as parameters 

int main(void){
	int a, b;
	double c;

	printf("Pythagorean calculator has launched! Formula is a^2 + b^2 = c^2\n");

	printf("Enter value for a : ");
	scanvalid(scanf("%d", &a), &a);

	printf("Enter value for b : ");
	scanvalid(scanf("%d", &b), &b);

	c = pythag(a, b);
	printf("c = %.2lf\n", c); 

	return 0;
}

double pythag(int a, int b){
	double c;
	a = a * a; /* a^2 */
	b = b * b; /* b^2 */
	c = a + b; /* c = a^2 + b^2 */
	c = sqrt(c);
	
	return c;
}

void scanvalid(int status, int* userIn){ 
	if(status == 0){
		printf("Not a valid int input, try again : ");
		scanvalid(scanf("%*[^\n]%d", userIn), userIn); /* Recursion to test if new user input is valid */
	} else if(status == 1) {
		printf("You have entered %d\n", *userIn); /* Print user's input if valid */
	}
}
