# Schrijf een functie die, gegeven een dictionary,
# een copy maakt van deze dictionary. Gebruik hiervoor de functie copy,
# die als parameter een dictionary meekrijgt en een copy van deze dictionary retourneert.

dic = {1: 1, 2: 4, 3: 9, 4: 16, 5: 25}

def new_dic(dic):
    dic_new = dic.copy()
    return(dic_new)

resultaat = new_dic(dic)
print(resultaat)