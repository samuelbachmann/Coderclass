string = "something"
dic = {}
def to_dict(string,dic):
    gebruikte_letters = ""
    for i in string:
        if not i in gebruikte_letters:
            dic[i] = string.count(i)
        gebruikte_letters += i

    print(dic)

to_dict(string, dic)