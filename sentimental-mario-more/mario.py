# TODO

def main():
    height = 0
    while (height <= 0 or height > 8):
        height = input("Height: ")

        try:
            height = int(height)
        except:
            height = 0
            print("Please, write a correct number betweeen 0 and 8")

    i = 1
    while (i <= height ):
        block = "#" * i
        space = " " * (height - i)
        print(f"{space}{block}  {block}")
        i+=1
if __name__ == "__main__":
    main()