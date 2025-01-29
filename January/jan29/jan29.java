public class PowerFunction {
    public static double power(double b, int exp) {
        double result = 1.0;
        long e = exp;  // Use long to handle Integer.MIN_VALUE case

        if (e < 0) {
            b = 1 / b;  // Take reciprocal for negative exponents
            e = -e;
        }

        while (e > 0) {
            if (e % 2 == 1) {  // If exponent is odd, multiply the base
                result *= b;
            }
            b *= b;   // Square the base
            e /= 2;   // Reduce the exponent by half
        }

        return result;
    }
}
