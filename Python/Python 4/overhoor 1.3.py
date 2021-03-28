import os, sys
import time
schrembreedte = 80
schremhoogte = 40
os.chdir("woordenlijst")

def keuze_menu():
    clear()
    header("Menu")
    print_regel("N - Nieuwe woordenlijst")
    print_regel("T - Toevoegen woorden aan woordenlijst")
    print_regel("O - Overhoren")
    print_regel("Q - Stoppen")
    footer()

    return input("Kies een functie ") 


def main():
    keuze_lijst = keuze_menu()
    if keuze_lijst.lower() == "n":
        nieuwe_lijst()
    elif keuze_lijst.lower() == "t":
        woorden_toevoegen()
    elif keuze_lijst.lower() == "o":
        overhoren()
    elif keuze_lijst.lower() == "q":
        print()
    else:
        clear()
        header("Geen functie met die naam")
        footer()
        time.sleep(1)
        main()
    

def overhoren():
    clear()
    over = {}
    header("Kies een lijst om te overhoren")
    for file in os.listdir():
        if file[-4:] == ".wrd":
            print_regel(file[:-4])
    print_regel("")
    print_regel("T - keuze menu")
    footer()
    naam_lijst = input("Kies een lijst ") + ".wrd"

    if naam_lijst in os.listdir():
        f = open(naam_lijst, "r")
        with open(naam_lijst) as f:
            for line in f:
                (key, val) = line.strip("\n").split("=")
                over[key] = val

        clear()
        header("Woorden")
        for key in over:
            print_regel(key + " = " + over[key]) 
        footer()
        start = input("Om te starten druk S om terug te gaan druk T ")

        if start.lower() == "s":
            for key in over:
                clear()
                header(key)
                print_regel("T - om terug te gaan")
                footer()
                vraag = input("vertaling ")
                if vraag == over[key]:
                    print("Goed")
                    time.sleep(1)
                elif vraag == "t":
                    overhoren()
                else:
                    print("Fout")
                    print(over[key])
                    time.sleep(2)

        elif start.lower() == "t":
            overhoren()

    elif naam_lijst.lower() == "t.wrd":
        main()

    else:
        clear()
        header("Geen lijst of functie met die naam")
        footer()
        time.sleep(1)
        overhoren()

def nieuwe_lijst():
    clear()
    header("Lijst aanmaken")
    header("Bestaande lijsten")
    for file in os.listdir():
        if file[-4:] == ".wrd":
            print_regel(file[:-4])
    footer()

    naam_lijst = input("Nieuwe lijst naam ")
    open(naam_lijst + ".wrd", "w")
    woorden_toevoegen()

def woorden_toevoegen():
    clear()
    invullen = True
    woorden = {}
    header("Woorden toevoegen aan lijst")
    for file in os.listdir():
        if file[-4:] == ".wrd":
            print_regel(file[:-4])
    print_regel("")
    print_regel("T - keuze menu")
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

    elif naam_lijst.lower() == "t":
        main()

    else:
        clear()
        header("Geen lijst met die naam")
        footer()
        time.sleep(1)
        woorden_toevoegen()


def stoppen_woorden(woorden, naam_lijst):
    clear()
    header("Opslaan")
    print_regel("O - Overwrite (nieuwe lijst)")
    print_regel("A - Append (worden toevoegen)")
    print_regel("")
    print_regel("T - keuze menu")
    footer()
    opslaan_keuze = input("Opslaan: ")
    if opslaan_keuze.lower() == "o":
        o = open(naam_lijst, "w")
        for key in woorden:
            o.write(key + "=" + woorden[key] + "\n")
        o.close()
        main()

    elif opslaan_keuze.lower() == "a":
        a = open(naam_lijst, "a")
        for key in woorden:
            a.write(key + "=" + woorden[key] + "\n")
        a.close()
        main()

    elif naam_lijst.lower() == "t":
        main()

    else:
        clear()
        header("Geen functie die zo heet")
        footer()
        time.sleep(1)
        stoppen_woorden(woorden, naam_lijst)

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
    print_regel("")

main()