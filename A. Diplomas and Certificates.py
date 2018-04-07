n, k = input().split()
n = int(n)
k = int(k)

esq = 0
dir = 1e12
res = 0

while esq <= dir:
  mid = (esq+dir)//2
  D = mid
  C = mid*k
  if 2*C+2*D <= n:
    esq = mid+1
    res = max(res, D)
  else:
    dir = mid-1
  
print(str(int(res)) + " " + str(int(res*k)) + " "+ str(int(n-res-res*k)) )
