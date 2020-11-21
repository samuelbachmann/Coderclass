dic = {}
def gen():
    n = 5
    for i in range(n):
        i += 1
        dic[i] = i*i

gen()
print(dic)