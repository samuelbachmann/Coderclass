dic = {1: 1, 2: 4, 3: 9, 4: 16, 5: 25}

def del_elm(dic):
    element = int(input("geef een element "))
    if element in dic:
        del dic[element]
    return(dic)

resultaat = del_elm(dic)
print(resultaat)