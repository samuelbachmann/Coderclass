dic1={1:10, 2:20}
dic2={3:30, 4:40}
dic3={5:50,6:60}
dic4 = {}

for key, value in dic1.items(), dic2.items(), dic3.items():
    # dic4[key] = value
    print(key, value)

print(dic4)