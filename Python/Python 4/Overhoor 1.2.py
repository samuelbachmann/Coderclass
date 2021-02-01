# Check if i your in the correct folder (Python 4)

import os, sys
schrembreedte = 80
schremhoogte = 40
os.chdir("woordenlijst")

def clear():
    # os.system("clear")
    os.system("cls")

def main():
    resultaat = print_menu()
    print(resultaat)
    if resultaat == "n":
        nieuw_lijst()
    elif resultaat == "v":
        verander_lijst()

def print_menu():
    clear()
    header("-Menu-")
    print_regel("")
    print_regel("N Nieuwe lijst.")
    print_regel("V Verander lijst.")
    # print_regel("T Woorden toevoegen aan lijst.")
    print_regel("O Woordenlijst overhoren")
    print_regel("Q Stop programma")
    footer()
    keuze = input(" Uw keuze. ")
    return keuze.lower()

def nieuw_lijst():
    clear()
    header("Bestand naam kiezen.")
    footer()
    naam_lijst = input("Naam bestand. ")
    f = open(naam_lijst + ".wrd", "w")
    while True:
        clear()
        header("Woorden of begrip toevoegen.")
        print_regel("Om te stoppen toets Q")
        footer()
        woord_1 = input("Geef een woord of begrip. ")
        if woord_1.lower() == "q":
            main()
            f.close()
            break
        clear()
        header("Geef een vertaling of betekenis in")
        print_regel(woord_1)
        print_regel("Om te stoppen toets en oplsaan Q")
        footer()
        woord_2 = input("Geef een vertaling of betekenis. ")    
        if woord_2.lower() == "q":
            f.close()
            main()
            break
        else:
            f.write(woord_1 + "=" + woord_2 + " \n")

def verander_lijst():
    clear()
    bestand = os.listdir()
    d={}
    
    header("Lijst veranderen.")
    print_regel("Kies de lijst die u wilt veranderen.")
    print_regel(" ")
    for file in os.listdir():
        if file[-4:] == ".wrd":
            print_regel(file[:-4])
    footer()

    lijst_selectie = input("Selecteer een lijst: ")
    keuze_lijst=  lijst_selectie + ".wrd"
    
    if keuze_lijst in bestand:
        clear()       
        f = open(keuze_lijst, "r")
        with open(keuze_lijst) as f:
            for line in f:
                
                (key, val) = line.strip("\n").split("=")
                d[key] = val
        header("Inhoud")
        print_regel(lijst_selectie)
        print_regel("")
        
        for i in d:
            print_regel(i + " = " + d[i])

        print_regel("")
        header("Veranderen")
        print_regel("")
        print_regel("T om een woord toetevoegen.")
        print_regel("V om een woord te verwijderen.")
        print_regel("N om het zo te laten.")
        footer()

        keuze_verandering = input("Wat wilt u doen. ")

        if keuze_verandering.lower() == "t":
            t_woord1 = input("Geef het woord of begrip. ")
            t_woord2 = input("Geef de vertaling of betekenis. ")
            b[t_woord1] = t_woord2
            
    else:
        clear()
        print("Er is geen lijst met de naam: " + keuze_lijst)
        main()

def print_regel(text):
    print(("|{:^" + str(schrembreedte - 2) + "}|").format(text))

def footer():
    print_regel("")
    print("+" + "-" * (schrembreedte - 2) + "+")
    
def header(lijst_naam):
    print("+" + "-" * (schrembreedte - 2) + "+")
    print_regel("")
    print(("| {:^" + str(schrembreedte - 4)+ "} |").format(lijst_naam))

main()