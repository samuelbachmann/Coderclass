schrembreedte = 60

def main():
    print("-" * schrembreedte)
    print(">N Nieuwe woordenlijst.")
    print(">V Verander woordenlijst.")
    print(">T Woorden Toevoegen aan woordenlijst")
    print(">O Woordenlijst overhoren")
    print(">Q Stoppen")
    print("-" * schrembreedte)

    antwoord = input("U keuze. ").lower

    if antwoord == "n":
        nieuw_lijst()


def nieuw_lijst():
    naam = input("Naam nieuw bestand")
    f = open(naam + ".txt", "w+")
    aantal = int(input("Hoeveel woorden wilt u? "))
    for i in range(aantal):
        w_1 = input("Geef woord 1. ")
        w_2 = input("Geef woord 2. ")
        f.write(w_1 + " = " + w_2 + " \n")
    
    


main()