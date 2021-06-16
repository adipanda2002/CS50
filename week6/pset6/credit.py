from cs50 import get_int


def main():
    while True:
        n = get_int("Number: ")
        if n >= 0:  # checks for positive number
            break

    if VALIDATE(n):
        PRINTBRAND(n)  # function to print CC brans
    else:
        print("INVALID")


def VALIDATE(n):
    return CHECKSUM(n)


def CHECKSUM(n):
    sum = 0
    for i in range(len(str(n))):
        if (i % 2 == 0):
            sum += n % 10  # takes the sum of digits not multiplied by 2
        else:
            digit = 2 * (n % 10)  # multiplies every other digit by 2
            sum += digit // 10 + digit % 10  # splits the digits of 2-digit numbers

        n //= 10

    return sum % 10 == 0
    

def PRINTBRAND(n):
    if (n >= 34e13 and n < 35e13) or (n >= 37e13 and n < 38e13):
        print("AMEX")  # for cards starting with 34/37
    elif ((n >= 51e14 and n < 56e14)):
        print("MASTERCARD")  # for cards starting with 51,52,53,54,55
    elif ((n >= 4e12 and n < 5e12) or (n >= 4e15 and n < 5e15)):
        print("VISA")  # for cards starting with 4
    else:
        printf("INVALID")


if __name__ == "__main__":
    main()
