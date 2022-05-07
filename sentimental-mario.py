from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height <= 8:
        break

for n in range(height):
    print((height-n)*" " + (n+1)*"#" + "  " + (n+1)*"#")