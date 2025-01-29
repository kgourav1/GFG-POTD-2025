double power(double b, int exp) {
    double result = 1.0;

    if (exp < 0) {
        b = 1 / b;  // Take reciprocal for negative exponents
        exp = -exp;
    }

    while (exp > 0) {
        if (exp % 2 == 1) {  // If the exponent is odd, multiply the base
            result *= b;
        }
        b *= b;   // Square the base
        exp /= 2; // Reduce the exponent by half
    }

    return result;
}
