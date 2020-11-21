
woord = input("geef een woord ") 
def is_palindroom():
    new = "" 
    for i in range(len(woord)):
        rev_i= len(woord) - i - 1
        new += woord[rev_i]

    if woord == new:
        return True
    else:
        return False

resultaat = is_palindroom()
print(resultaat)