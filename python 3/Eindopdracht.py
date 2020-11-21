# niew contact
# del contact
# alle contact + aantal
# quit
# contact aanpassen

def main():
    usr_input = menu()
    contacten = {}
    if usr_input == "m" or usr_input == "M":
        menu()
    elif usr_input == "n" or usr_input == "N":
        contacten = new_contact(contacten)
    elif usr_input == "d" or usr_input == "D":
        del_contact(contacten)
    # elif usr_input == "z" or usr_input == "Z":
    #     zoek(contacten)
    # elif usr_input == "a" or usr_input == "A":
    #     aanpassen_contact(contacten)
    elif usr_input == "q" or usr_input == "Q":
        exit()
    else:
        print("U heeft geen geldige input gegeven")
        menu()
    print(contacten)
    
   

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
    input_usr = input("Wat wilt u doen? ")
    return input_usr

def new_contact(contacten):
    naam = input("Naam: ")
    telefoonnummer = input("Telefoonnummer: ")
    email = input("Emailadress: ")
    gegevens = {"Telefoonnummer: ": telefoonnummer, "Emailadress:": email}
    contacten[naam] = gegevens
    main()
    return contacten

def del_contact(contacten):
    del_naam = input("Welk contact zou u wilen verwijderen? ")
    if del_naam in contacten.items():
        print("Er is geen contact met de naam: " + del_naam)
    else:
        check = input("Delete " + del_naam + " [Y/N] ")
        if  check == "Y" or check == "y" or check == "yes":
            del contacten[del_naam]
            print(del_naam + "is verwijderd")
        else: 
            print("Er is geen contact verwijderd")   
    main()

# def zoek(contacten):
#     zoek_contact = input("Wie wilt u zoeken? ")
#     if zoek_contact in contacten:
#         for key, value in contacten.items():
#             print(key, value)    
#     main() 

# def aanpassen_contact(contacten):
#     aanpas_contact = input("Welk contact wilt u aanpassen? ")
#     if aanpas_contact in contacten:
#         pass
#     else:
#         print("Er is geen contact onder de naam " + aanpas_contact)


main()