import os, sys
schrembreedte = 80
schremhoogte = 40
os.chdir("woordenlijst")

def keuze_menu():
    clear()
    header("Menu")
    print_regel(" ")
    print_regel("N - Nieuwe woorden lijst")
    footer()

    return input("Kies een functie ") 


def main():
    keuze_lijst = keuze_menu()
    if keuze_lijst.lower() == "n":
        nieuwe_lijst()

def nieuwe_lijst():
    clear()
    header("Lijst aanmaken")
    footer()

    naam_lijst = input("Nieuwe lijst naam ")
    open(naam_lijst + ".wrd", "w")
    woorden_toevoegen()

def woorden_toevoegen():
    clear()
    invullen = True
    woorden = {}
    header("Woorden toevoegen aan lijst")
    print_regel("")
    for file in os.listdir():
        if file[-4:] == ".wrd":
            print_regel(file[:-4])
    footer()

    naam_lijst = input("Kies een lijst ")
    naam_lijst = naam_lijst + ".wrd"
    
    if naam_lijst in os.listdir() :
        while invullen:
            clear()
            header("Woord: ")
            print_regel("om te stoppen druk q")
            footer()
            woord_1 = input("woord: ")

            if woord_1.lower() == "q":
                stoppen_woorden(woorden, naam_lijst)
                break

            clear()
            header("Woord: ")
            print_regel("om te stoppen druk q")
            footer()

            woord_2 = input("vertalling: ")

            if woord_2.lower() == "q":
                stoppen_woorden(woorden, naam_lijst)
                break

            else:
                woorden[woord_1] = woord_2

def stoppen_woorden(woorden, naam_lijst):
    clear()
    f = open(naam_lijst, "w")
    for key in woorden:
        f.write(key + "=" + woorden[key] + "\n")


def clear():
    # os.system("clear")
    os.system("cls")

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