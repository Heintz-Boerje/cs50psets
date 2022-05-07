from cs50 import get_string
from sys import exit

def main():

    card = get_string("Card number: ")
    number_lengths = [13, 15, 16]

    if len(card) not in number_lengths:
        print("INVALID")
        exit(1)

    if checksum(card):

        if len(card) == 15 and int(card[0]) == 3 and (int(card[1]) == 4 or int(card[1]) == 7):
            print("AMEX")
            exit(0)

        elif (len(card) == 13 or len(card) == 16) and int(card[0]) == 4:
            print("VISA")
            exit(0)

        elif len(card) == 16 and int(card[0]) == 5 and (int(card[1]) >= 1 or int(card[1]) <= 5 ):
            print("MASTERCARD")
            exit(0)

        print("INVALID")
        exit(1)

    print("INVALID")


def checksum(card_num):

    s = 0

    for n in range(2,len(card_num)+1,2):
        s += int(card_num[-n])*2//10 + int(card_num[-n])*2%10

    for n in range(1,len(card_num)+1,2):
        s += int(card_num[-n])


    if (s%10) == 0:
        return True

    return False

main()