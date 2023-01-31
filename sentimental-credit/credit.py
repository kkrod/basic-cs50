# TODO
def main():
    card = get_creditcard()
    len = get_algo(card)
    pref = type_card(len, card)
    imprimir(len, pref)

def get_creditcard():
    card = int(input("Number: "))
    return card

def get_algo(card):

    m1 = 0
    m2 = 0
    i = 0

    while (card > 0):
        m = card % 10
        card = card // 10
        i+=1
        if (i % 2 == 0):
            m = m * 2
            if (m > 9):
                m = (m % 10) + (m // 10)
            m2 = m2 + m
        else:
            m1 = m1 + m
    m = m1 + m2
    if (m % 10 == 0):
        return i
    else:
        return 0

def type_card(l, card):
    pref = card // (10 ** (l - 2))
    return pref

def imprimir(l, pref):
    if ((l == 13 or l == 16) and (pref >= 40 and pref < 50)):
        print("VISA")
    elif ((l == 15) and (pref == 34 or pref == 37)):
        print("AMEX")
    elif ((l == 16) and (pref > 50 and pref <= 55)):
        print("MASTERCARD")
    else:
        print("INVALID")
    print("\n")
    return 0
if __name__ == "__main__":
    main()