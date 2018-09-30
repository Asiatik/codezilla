#Using python3
def gcd(a, b):
    if a == 0 or b == 0:
        return a + b
    return gcd(b, a % b)

if __name__=='__main__':
    print (gcd(10,100))
    print (gcd(9,145))
