/* Bisection Method:
This code implements the Bisection method (also called the Bijection method),
which is a numerical technique used to find the root of an equation where the function has opposite signs at two points (i.e., f(a) and f(b) have opposite signs).
The root is found by repeatedly dividing the interval in half and narrowing it down until the root is approximated.*/

#include <stdio.h>
#include <math.h>

// Function definition for f(x), which is the equation we want to find the root for
double f(double x)
{
    // Example function: f(x) = x^3 - x - 1
    return pow(x, 3) - x - 1;
}

int main()
{
    // Declare variables for interval [a, b], midpoint (xk) and tolerance
    double a, b, xk, fk, approximate = 0.0001;
    int k = 1, max_iteration = 1000; // Iteration counter and maximum iterations

    // Get input values for 'a' (lower bound) and 'b' (upper bound)
    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);

    // Check if the function has opposite signs at a and b (necessary for Bisection method)
    if (f(a) * f(b) >= 0)
    {
        printf("The function must have opposite signs at a and b.\n");
        return 1; // Exit if signs are not opposite
    }

    // Iteration loop for Bisection method
    while (k <= max_iteration)
    {
        // Calculate the midpoint of the interval
        xk = (a + b) / 2;
        // Calculate the function value at the midpoint
        fk = f(xk);

        // Print the current iteration, midpoint, and function value at the midpoint
        printf("Iteration %d: xk = %.6lf, f(xk) = %.6lf\n", k, xk, fk);

        // Check if the function value at xk is close enough to zero (within tolerance)
        // or if the interval has become sufficiently small
        if (fabs(fk) < approximate || (b - a) / 2 < approximate)
        {
            // Root is found; print the result and exit
            printf("\nRequired root is approximately: %.6lf\n", xk);
            return 0;
        }
        // If f(a) and f(xk) have opposite signs, the root is between a and xk
        // Otherwise, the root is between xk and b
        if (f(a) * fk < 0)
        {
            // Update b to the midpoint xk
            b = xk;
        }
        else
        {
            // Update a to the midpoint xk
            a = xk;
        }
        // Increment the iteration counter
        k++;
    }
    // If the root is not found within the maximum number of iterations, exit with error
    return 1;
}

/* How it works:

1. Function Definition (f(double x)):

f(double x) defines the function for which we want to find the root.
In this example, the function is pow(x, 3) - x - 1
We can change this function to whatever equation we want to solve.

2. Input:

The program asks the user to enter two values, a and b. These are the initial interval endpoints.
The function values at these points (f(a) and f(b)) must have opposite signs to guarantee that a root lies between them.

3. Check for Opposite Signs:

The program checks if f(a) and f(b) have opposite signs (f(a) * f(b) < 0).
If they don't, the program informs the user that the function must have opposite signs at a and b to proceed.

4. Iteration Process:

If the signs are opposite, the Bisection method starts.
The program calculates the midpoint (xk) between a and b and evaluates f(xk).
Depending on whether the root lies between a and xk or xk and b, it updates the interval.
If f(a) and f(xk) have opposite signs, b is updated to xk; otherwise, a is updated to xk.

5. Stopping Conditions:

The loop continues until either the function value at the midpoint (f(xk)) is close enough to zero (within a given tolerance, approximate = 0.0001) or the width of the interval becomes small enough ((b - a) / 2 < approximate).
If either condition is met, the program prints the approximate root and exits.

6. Iteration Limit:

The program has a maximum iteration count of 1000 to avoid infinite loops.
If the root is not found within this limit, the loop ends.


*** Key Variables:
a and b: Interval endpoints where the function has opposite signs.
xk: The midpoint of the current interval.
fk: The value of the function at xk.
approximate: The tolerance level for the approximation of the root.
k: Iteration counter.


*** Example Output:
Enter a: 1
Enter b: 2
Iteration 1: xk = 1.500000, f(xk) = 0.875000
Iteration 2: xk = 1.250000, f(xk) = -0.296875
Iteration 3: xk = 1.375000, f(xk) = 0.224609
Iteration 4: xk = 1.312500, f(xk) = -0.051514
Iteration 5: xk = 1.343750, f(xk) = 0.082611
Iteration 6: xk = 1.328125, f(xk) = 0.014576
Iteration 7: xk = 1.320312, f(xk) = -0.018711
Iteration 8: xk = 1.324219, f(xk) = -0.002128
Iteration 9: xk = 1.326172, f(xk) = 0.006209
Iteration 10: xk = 1.325195, f(xk) = 0.002037
Iteration 11: xk = 1.324707, f(xk) = -0.000047

Required root is approximately: 1.324707
*/