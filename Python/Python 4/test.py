import os, sys
os.chdir("woordenlijst")

exDict = {111:111, 222:222}
with open('file.txt', 'r') as file:
    file.write(str(exDict))