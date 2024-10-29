/* False Position Method:
The False Position Method (also called the Regula Falsi Method) is a root-finding technique used to solve nonlinear equations.
It is based on the idea that if a continuous function changes sign over an interval,
there must be a root (i.e., where the function equals zero) within that interval. */

#include <stdio.h>
#include <math.h>

// Function definition for f(x), which is the equation we want to find the root for
double f(double x)
{
    // Example equation: f(x) = x^3 + x^2 - 1
    return ((x * x * x) + (x * x) - 1);
}

int main()
{
    // Declare variables for interval [a, b], root approximation (c), fk is f(c) and tolerance
    double a, b, c, fk, approximate = 0.0001;
    int k = 1, max_iteration = 1000; // Iteration counter and maximum iterations

    // Get input values for 'a' (lower bound) and 'b' (upper bound)
    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter  b: ");
    scanf("%lf", &b);

    // Check if f(a) and f(b) have opposite signs, which indicates there is a root between them
    if (f(a) * f(b) >= 0)
    {
        printf("The function must have opposite signs at a and b.\n");
        return 1; // Exit if signs are not opposite
    }

    // Start the iteration loop to refine the approximation of the root
    while (k <= max_iteration)
    {
        // Calculate the new point 'c' using the False Position formula
        c = ((a * f(b)) - (b * f(a))) / (f(b) - f(a));
        // Evaluate f(c) to see how close we are to the root
        fk = f(c);

        // Print the current iteration, the calculated value of 'c', and f(c)
        printf("Iteration %d: value of c = %.6lf,  f(c) = %.6lf\n", k, c, fk);

        // Check if f(c) is close enough to zero (within the tolerance level 'approximate')
        if (fabs(fk) <= approximate)
        {
            // If f(c) is sufficiently close to zero, we consider 'c' as the approximate root
            printf("\nRequired root is approximately: %.6lf\n", c);
            return 0; // Exit the program since the root has been found
        }
        // Update the interval based on the sign of f(c):
        // If f(c) is negative, the root lies between c and b, so update 'a' to 'c'
        if (f(c) < 0)
        {
            a = c;
        }
        // If f(c) is positive, the root lies between a and c, so update 'b' to 'c'
        else if (f(c) > 0)
        {
            b = c;
        }
        k++; // Increment the iteration counter
    }
    // If the loop finishes without finding a root (i.e., max iterations are reached), return with an error
    return 0;
}

/* How it works:

1. Function Definition (f(double x)):

f(double x) defines the function for which we want to find the root.
In this example, the function is (x^3 + x^2 - 1). WE can change this function to whatever equation we need to solve.

2. Input:

The program prompts the user to enter two values, `a` and `b`, which are the initial interval bounds.
The function values at these points (f(a) and f(b)) must have opposite signs to guarantee that a root lies between them.

3. Check for Opposite Signs:

The program checks if f(a) and f(b) have opposite signs (f(a) * f(b) < 0).
If they don't, the program informs the user that the function must have opposite signs at a and b to proceed.

4. Iteration Process:

If the signs are opposite, the False Position method starts.
The program calculates the new point `c` using the False Position formula and evaluates f(c).
Depending on whether the root lies between `a` and `c` or `c` and `b`, it updates the interval.
If f(c) is negative, `a` is updated to `c`; otherwise, `b` is updated to `c`.

5. Stopping Conditions:

The loop continues until either the function value at the new point `c` is close enough to zero (within a given tolerance, `approximate = 0.0001`),
or the maximum number of iterations (`max_iteration = 1000`) is reached.
If either condition is met, the program prints the approximate root and exits.

6. Iteration Limit:

The program has a maximum iteration count of 1000 to avoid infinite loops.
If the root is not found within this limit, the loop ends.


*** Key Variables:
a and b: Interval endpoints where the function has opposite signs.
c: The new point calculated using the False Position formula.
fk: The value of the function at c.
approximate: The tolerance level for the approximation of the root.
k: Iteration counter.

*** Example Output:
Enter a: 0
Enter  b: 1
Iteration 1: value of c = 0.500000,  f(c) = -0.625000
Iteration 2: value of c = 0.692308,  f(c) = -0.188894
Iteration 3: value of c = 0.741194,  f(c) = -0.043441
Iteration 4: value of c = 0.751969,  f(c) = -0.009335
Iteration 5: value of c = 0.754263,  f(c) = -0.001977
Iteration 6: value of c = 0.754748,  f(c) = -0.000417
Iteration 7: value of c = 0.754850,  f(c) = -0.000088

Required root is approximately: 0.754850
*/