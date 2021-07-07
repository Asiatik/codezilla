# Using python3
# Newton-Raphson for square root
# Find x such that x**2 - 1337 is within epsilon of 0.0001
epsilon = 0.0001
k = 1337.0


def newton(n, eps):
    guess = n/2.0
    count = 1

    while abs(guess*guess - n) >= eps:
        guess = guess - (((guess**2) - n)/(2*guess))
        print('Guess #', count, ' -> ', guess)
        count += 1  # track no. of guesses

    return guess


if __name__ == '__main__':
    test = 1337
    print('Square root of', test, 'is about', newton(test, 0.0001))
    # should return ~ 36.565 for test = 1337
