n,m = map(int, input().split())
inter = n*m
palito = n+m
aux = 1
while inter > 0:
  n-=1
  m-=1
  inter = n*m
  aux+=1
if aux%2 == 1:
  print("Malvika")
else:
  print("Akshat")