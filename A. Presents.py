n = int(input())
mapa = dict()
aux = 1
for x in input().split():
    mapa[int(x)] = aux
    aux+=1
for x in range(1, aux):
    print(mapa[x], end = " ")
    