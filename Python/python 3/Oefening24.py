dic = {1: 1, 2: 4, 3: 9, 4: 16, 5: 25}

def check(dic):
    new = 0
    for key, value in dic.items():
        new += value 
    return(new)
resultaat = check(dic)
print(resultaat)