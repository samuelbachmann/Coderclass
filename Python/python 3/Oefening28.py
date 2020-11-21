# Schrijf een functie die controleert of een dictionary leeg is.
# Gebruik hiervoor een functie genaamd is_empty die als parameter een dictionary meekrijgt en
# een retourneert of deze leeg is of niet. Gebruik voor dat laatste een boolean.
dic = {1:1}

def is_empty(dic):
    if len(dic) == 0:
        return(True)
    else:
        return(False)

resultaat = is_empty(dic)
print(resultaat)