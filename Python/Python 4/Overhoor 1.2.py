import os, sys
schrembreedte = 80

def clear():
    os.system("clear")

def main():
    resultaat = print_menu()
    print(resultaat)
    if resultaat == "n":
        nieuw_lijst()

def print_menu():
    clear()
    header("-Menu-")
    print_regel("")
    print_regel("N Nieuwe lijst.")
    print_regel("V Verander lijst.")
    print_regel("T Woorden toevoegen aan lijst.")
    print_regel("O Woordenlijst overhoren")
    print_regel("Q Stop programma")
    footer()
    keuze = input(" Uw keuze. ")
    return keuze.lower()

def nieuw_lijst():
    clear()
    woorden_lijst = {}
    header("Bestand naam kiezen.")
    footer()
    naam_lijst = input("Naam bestand. ")
    f = open(naam_lijst + ".txt", "w+")
    while True:
        clear()
        header("Woorden of begrip toevoegen.")
        print_regel("Om te stoppen toets Q")
        footer()
        woord_1 = input("Geef een woord of begrip. ")
        if woord_1.lower() == "q":
            main()
            break
        clear()
        header("Geef een vertaling of betekenis in")
        print_regel(woord_1)
        print_regel("Om te stoppen toets Q")
        footer()
        woord_2 = input("Geef een vertaling of betekenis. ")    
        if woord_2.lower == "q":
            main()
            for key in woorden_lijst:
                f.write(key + "=" + woorden_lijst[value] + "\n")
            break
        else:
            woorden_lijst[woord_1] = woord_2

        
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