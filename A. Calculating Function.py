import math
n = input();
n = int(n)

#1 2 3 4 5
#
impar = math.ceil(n/2)
par   = math.floor(n/2)
print( (par+1)**2 - (par+1) - (impar**2) )