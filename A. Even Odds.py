from math import ceil
n, k = map(int, input().split())
impar = ceil(n/2)
par = n//2
if k <= impar:
  print(2*k-1)
else:
  print(2*(k-impar))

  
#1 3 5 7 2 4 6