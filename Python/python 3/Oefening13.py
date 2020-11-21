woord = input("geef een woord hoi ") 
def reverse():
    new = "" 
    for i in range(len(woord)):
        rev_i= len(woord) - i - 1
        new += woord[rev_i]
    print(new) 

reverse()