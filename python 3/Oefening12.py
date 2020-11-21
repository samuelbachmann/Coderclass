getallenlijn = [10, 50, 100, 500, 1000]
def max_van_drie():
    max = getallenlijn[0]
    for i in range(len(getallenlijn)):
        if getallenlijn[i] > max:
            max = getallenlijn[i]
    return max 

resultaat = max_van_drie()
print(resultaat)
