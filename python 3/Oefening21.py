array = {"piet": "kees"}
def del_elm(array):
    element = input("geef een element ")
    if element in array:
        del array[element]
    return(array)

resultaat = del_elm(array)
print(resultaat)