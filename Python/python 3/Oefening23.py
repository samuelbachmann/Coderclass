dic = {1: 1, 2: 4, 3: 9, 4: 16, 5: 25}

def check(dic):
    element = int(input("Geef een element "))
    if element in dic:
        return(True)
    else:
        return(False)

print(check(dic))