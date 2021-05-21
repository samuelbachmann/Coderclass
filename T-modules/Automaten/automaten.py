toestanden = {"begin":0, "slagboom dicht":1, "licht aan":2, "doe bomen dicht":3, "bomen dicht":4, "doe bomen open":5, "bomen open":6, "lichten uit":7, "eind":8}
huidige_toestand = toestanden["begin"]

while True:
    if huidige_toestand == toestanden["begin"]:
        if trein_nadert:
            huidige_toestand = toestanden["slagboom dicht"]

    elif huidige_toestand == toestanden["slagboom dicht"]:
        if nee:
            toestanden = ["licht aan"]
        elif ja:
            toestanden = ["bomen dicht"]
    
    elif huidige_toestand == toestanden["licht aan"]:
        if 10 sec:
            toestanden = ["doe bomen dicht"]

    elif huidige_toestand == toestanden["doe bomen dicht"]:
        if schakelaar dicht:
            toestanden = ["bomen dicht"]
    
    elif huidige_toestand == toestanden["bomen dicht"]:
        if trein verwijdert:
            toestanden = ["doe bomen open"]

    elif huidige_toestand == toestanden["doe bomen open"]:
        if schakelaar open:
            toestanden = ["bomen open"]
    
    elif huidige_toestand == toestanden["bomen open"]:
        if 10 sec:
            toestanden = ["lichten uit"]
    
    elif huidige_toestand == toestanden["lichten uit"]:
        toestanden = ["eind"]
    
    elif huidige_toestand == toestanden["lichten uit"]:
        toestanden = ["begin"]