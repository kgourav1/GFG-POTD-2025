def power(b, exp):
    result = 1.0
    if exp < 0:
        b = 1 / b  # Take reciprocal for negative exponents
        exp = -exp

    while exp > 0:
        if exp % 2 == 1:  # If exponent is odd, multiply the base
            result *= b
        b *= b  # Square the base
        exp //= 2  # Reduce exponent by half (integer division)

    return result
