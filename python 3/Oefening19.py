array = ["hoi", "kees", "LOLs"]

def add_array(array):
    element = input("element:")
    array.insert(1,element)
    return(array)

resultaat = add_array(array)
print(resultaat)