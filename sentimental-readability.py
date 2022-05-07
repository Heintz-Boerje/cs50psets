from cs50 import get_string


text = get_string("Text: ")

letters = 0
sentences = 0
words = 0

alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
            'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
            'u', 'v', 'w', 'x', 'y', 'z']

punctuation = ['!', '.', '?']

for n in text:

    if n.isalpha():
        letters += 1

    elif n == ' ':
        words += 1

    elif n in punctuation:
        sentences += 1

words += 1

L = letters / words * 100
S = sentences / words * 100

index = (0.0588 * L) - (0.296 * S) - 15.8

if index < 1:
    print("Before Grade 1")
elif index < 12:
    print(f"Grade {int(index)}")
else:
    print("16+")