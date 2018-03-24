
from random import randint

N = 100000
D = 10000

print(N, D)
for i in range(N):
    print(randint(1, 100000), ' ', end='')
print("")
for i in range(D):
    print(randint(-10000, 10000), '', end='')
print("")
