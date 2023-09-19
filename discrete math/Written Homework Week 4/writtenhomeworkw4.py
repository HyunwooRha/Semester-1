import math
def sqrt2approx():
    best_p = 0
    best_q = 1
    best_error = None

    for q in range(2, 100001):
        lower_p = int(1.4 * q)
        upper_p = int(1.5 * q)

        for p in range(lower_p, upper_p + 1):
            current_error = abs(math.sqrt(2) - p/q)

            if best_error is None:
                best_p = p
                best_q = q
                best_error = current_error
            if current_error < best_error:
                best_p = p
                best_q = q
                best_error = current_error

    return best_p, best_q
print(sqrt2approx())