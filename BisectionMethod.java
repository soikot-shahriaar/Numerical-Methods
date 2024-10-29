import java.util.Scanner;

public class BisectionMethod {
    public static double f(double x) { // Function to find the root
        return (x * x) - 5 * x + 2; // Equation would be changed as needed
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a, b, c, fk;
        double approximate = 0.0001; // Desired accuracy
        int k = 1, maxIteration = 1000; // Iteration counter
        System.out.print("Enter a (lower bound): "); // Input lower and upper bounds
        a = sc.nextDouble(); // let a=0
        System.out.print("Enter b (upper bound): ");
        b = sc.nextDouble(); // let b=1
        if (f(a) * f(b) >= 0) { // Check if the function has opposite signs at a and b
            System.out.println("The function must have opposite signs at a and b.");
        }
        while (k <= maxIteration) { // Bisection method iteration
            c = (a + b) / 2;
            fk = f(c);
            System.out.printf("Iteration %d: c = %.6f, f(c) = %.6f\n", k, c, fk);
            // Check if the current value is close enough to the root
            if (Math.abs(fk) < approximate || (b - a) / 2 < approximate) {
                System.out.printf("\nRequired root is approximately: %.6f\n", c);
                return;
            }
            if (f(a) * fk < 0) { // Update a or b based on the sign of f(c)
                b = c;
            } else {
                a = c;
            }
            k++; // Increment iteration counter
            sc.close();
        }
    }
}

/*
 * *** Example Output:
 * 
 * Enter a (lower bound): 0
 * Enter b (upper bound): 1
 * Iteration 1: c = 0.500000, f(c) = -0.250000
 * Iteration 2: c = 0.250000, f(c) = 0.812500
 * Iteration 3: c = 0.375000, f(c) = 0.265625
 * Iteration 4: c = 0.437500, f(c) = 0.003906
 * Iteration 5: c = 0.468750, f(c) = -0.124023
 * Iteration 6: c = 0.453125, f(c) = -0.060303
 * Iteration 7: c = 0.445313, f(c) = -0.028259
 * Iteration 8: c = 0.441406, f(c) = -0.012192
 * Iteration 9: c = 0.439453, f(c) = -0.004147
 * Iteration 10: c = 0.438477, f(c) = -0.000121
 * Iteration 11: c = 0.437988, f(c) = 0.001892
 * Iteration 12: c = 0.438232, f(c) = 0.000886
 * Iteration 13: c = 0.438354, f(c) = 0.000382
 * Iteration 14: c = 0.438416, f(c) = 0.000131
 * 
 * Required root is approximately: 0.438416
 */