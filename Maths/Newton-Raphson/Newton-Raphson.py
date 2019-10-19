# Newton-Raphson for square root
# Find x such that x**2 - 1337 is within epsilon of 0.0001
epsilon = 0.0001
k = 1337.0
guess = k/2.0
counter = 1
while abs(guess*guess - k) >= epsilon:
    guess = guess - (((guess**2) - k)/(2*guess))
    print('#', counter, ' -> ', guess)
    counter += 1  # track guesses

print('Square root of', k, 'is about', guess)  # should return ~ 36.565
