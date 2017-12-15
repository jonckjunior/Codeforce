a = input()
b = input()
res = ""
for i in range(0, len(a)):
  if a[i] == b[i]:
    res += "0"
  else:
    res += "1"
print(res)