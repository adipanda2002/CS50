from cs50 import get_int

# check for valid height input
while True:
    n = get_int("Height: ")
    if n >= 1 and n <= 8:
        break
    
# print appropriate pyramid
for i in range(n):
    print(" " * (n - 1 - i), end='')
    print("#" * (i + 1), end='')
    print(" " * 2, end='')
    print("#" * (i + 1))
