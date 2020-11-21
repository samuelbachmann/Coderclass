# Schrijf een functie die van een dictionary de maximum en de minimum value retourneert.
# gebruik hiervoor een functie die een dictionary meekrijgt en van deze dictionary de 
# minimum en maximum value retourneert.

dic = {2: 4, 1: 1, 3: 9, 4: 16, 5: 25}

def max_min(dic):
    for i in range(len(dic)):
        i += 1
        if dic[i] > max:
            max = dic[i]
        elif dic[i] < min:
            min = dic[i]
    return (max, min )

max, min = max_min(dic)
print(max)
print(min)