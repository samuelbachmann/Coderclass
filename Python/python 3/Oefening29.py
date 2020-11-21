dic = {1:['sam','tw'],2:['uel','an']}

def combi(dic):
    for key, value in dic.items():
        i =+1
        for i in range(len(value)):  
            print(value[i])
combi(dic)