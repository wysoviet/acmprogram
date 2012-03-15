solve [a, b, 0] = 1
solve [a, b, n] = 1 - solve [ b, a, n - gcd a n]

main = getLine >>= print . solve . map read . words
