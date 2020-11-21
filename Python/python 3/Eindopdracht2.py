def main():
    contacten = {}
    loop = True   
    while loop:
        usr_input = menu()
        if usr_input == "m":
            menu()
        elif usr_input == "n":
            new_contact(contacten)
        elif usr_input == "d":
            del_contact(contacten)
        elif usr_input == "a":
            aanpassen_contact(contacten)
            print(contacten)
        elif usr_input == "z":
            zoek(contacten)
        elif usr_input == "q":
            exit()
        else:
            print("U heeft geen geldige input gegeven")
            menu()       

def menu():
    print(''' -------------------------
|      Keuze Menu         |
| [M] Keuze menu          |
| [N] Nieuw contact       |
| [D] Verwijder contact   |
| [A] Contact aanpassen   |
| [Z] Zoeken              |
| [Q] Quit                |
 -------------------------
    ''')
    return input("Wat wilt u doen? ").lower()

def new_contact(contacten):
    naam = input("Naam: ")
    if naam in contacten:x
        print("Er is al een contact met de naam " + naam)
    else:
        telefoonnummer = input("Telefoonnummer: ")
        email = input("Emailadress: ")
        gegevens = {"Telefoonnummer: ": telefoonnummer, "Emailadress:": email}
        contacten[naam] = gegevens
    
def del_contact(contacten):
    del_naam = input("Welk contact zou u wilen verwijderen? ")
    if del_naam in contacten:
        del contacten[del_naam]
    else:
        print("Er is geen contact met de naam " + del_naam)
    
def aanpassen_contact(contacten):
    aanpas_contact = input("Welk contact wilt u aanpassen? ")
    if aanpas_contact in contacten:
        telefoonnummer = input("Telefoonnummer: ")
        email = input("Emailadress: ")
        gegevens = {"Telefoonnummer: ": telefoonnummer, "Emailadress:": email}
        contacten[aanpas_contact] = gegevens
    else:
        print("Er is geen contact onder de naam " + aanpas_contact)

def zoek(contacten):
    zoek_contact = input("Wie wilt u zoeken? ")
    gegevens = contacten[zoek_contact]
    if zoek_contact in contacten:
        for key, value in gegevens.items():
            print(key, value) 

if __name__ == "__main__":
    main()