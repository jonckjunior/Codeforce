n = int(input())
mapa = {}
v1 = list(map(int,input().split()))
v1 = v1[1:]
for x in v1:
  mapa[x] = 1
v2 = list(map(int,input().split()))
v2 = v2[1:]
for x in v2:
  mapa[x] = 1
if len(mapa) == n:
  print("I become the guy.")
else:
  print("Oh, my keyboard!")