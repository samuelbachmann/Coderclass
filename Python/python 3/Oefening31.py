dic = {1:5, 2:6, 3:7}
def som(dic):
    for key, value in dic.items():
        dic[key] = value + key
        return(dic)

resultaat = som(dic)
print(resultaat)