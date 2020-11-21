cijfer = int(input("geef een getal om te checken of het een priemgetal is "))

def is_priemgetal():
    if cijfer == 1:
        return(True)
    for i in range(cijfer -2):
        i += 2
        getal = cijfer / i
        if round(getal) == getal:
            return(False)
    return(True)
resultaat = is_priemgetal()
print(resultaat)