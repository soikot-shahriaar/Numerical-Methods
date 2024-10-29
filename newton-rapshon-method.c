/* Newton-Raphson Method:
This code implements the Newton-Raphson method, which is a root-finding technique for solving nonlinear equations.
The method uses an iterative approach to approximate the root of a function. To use this code for a different equation,
We need to update the function and its derivative accordingly.
*/

#include <stdio.h>
#include <math.h>

// Function definition for f(x), which is the equation we want to find the root for
double f(double x)
{
    return ((x * x * x) - (3 * x) - 5); // Example function: x^3 - 3x - 5
}

// Function definition for the derivative of f(x)
double derivative_of_f(double x)
{
    return (3 * x * x - 3); // Derivative of the example function: 3x^2 - 3
}

int main()
{
    // Declare variables for interval [a, b], current approximation (x1) and tolerance
    double a, b, x1, approximate = 0.0001;

    // Get initial values from the user
    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);

    double x0 = a;                   // Initial guess for the root is taken from the lower bound 'a'
    int n = 0, max_iteration = 1000; // Initialize iteration counter 'n' and set maximum number of iterations

    // Ensure that the function has opposite signs at 'a' and 'b'
    if (f(a) * f(b) >= 0)
    {
        printf("The function must have opposite signs at a and b.\n");
        return 1; // Exit if the function does not have opposite signs
    }

    // Iterative loop to find the root using the Newton-Raphson Method
    while (n <= max_iteration)
    {
        n++; // Increment the iteration counter

        // Apply the Newton-Raphson formula to find the next approximation
        x1 = x0 - f(x0) / derivative_of_f(x0);

        // Print the current iteration number and approximation value
        printf("Iteration %d: x%d = %.6lf\n", n, n, x1);

        // Check if the difference between consecutive approximations is within the tolerance level
        if (fabs(x1 - x0) <= approximate)
        {
            break; // Exit the loop if the desired root is found within the tolerance
        }
        x0 = x1; // Update the approximation for the next iteration
    }

    // Print the final result
    printf("The desired root is: %.5lf\n", x1);

    return 0;
}

/* How it works:

1. Function Definition (f(double x)):

f(double x) defines the function for which we want to find the root.
In this example, the function is x^3 - 3x - 5.
We can change this function to any other equation we need to solve.

2. Derivative Function (derivative_of_f(double x)):

derivative_of_f(double x) defines the derivative of the function f(x).
For the example function, the derivative is 3x^2 - 3.
The derivative is required by the Newton-Raphson method to calculate the next approximation.

3. Input:

The program prompts the user to enter two initial values, `a` and `b`.
These values are used as the starting point for the iteration process.

4. Initialization:

The program initializes `x0` with the value of `a`, which is used as the starting guess for the root.
The iteration counter `n` and the maximum number of iterations `max_iteration` are also initialized.

5. Iteration Process:

The Newton-Raphson method starts iterating to find the root. In each iteration:
- The new approximation `x1` is calculated using the formula: x1 = x0 - f(x0) / derivative_of_f(x0)
- The value of the function `f(x0)` and its derivative `derivative_of_f(x0)` are used to update the approximation.
- The iteration number and current approximation are printed for tracking.

6. Stopping Conditions:

The loop continues until the change in the approximation (|x1 - x0|) is less than or equal to the tolerance level
(`approximate = 0.0001`), or until the maximum number of iterations is reached.
If the desired root is found within the tolerance, the loop breaks, and the program prints the result.

7. Output:

After finding the root (or reaching the maximum iterations), the program prints the final approximation of the root.


*** Key Variables:
a and b: Initial values for starting the iteration process.
x0: Initial guess for the root, set to `a`.
x1: The new approximation for the root in each iteration.
fk: The value of the function at x0.
approximate: The tolerance level for the approximation of the root.
n: Iteration counter.
max_iteration: The maximum number of iterations allowed.


*** Example Output:
Enter a: 2
Enter b: 3
Iteration 1: x1 = 2.333333
Iteration 2: x2 = 2.280556
Iteration 3: x3 = 2.279020
Iteration 4: x4 = 2.279019

The desired root is: 2.27902
*/