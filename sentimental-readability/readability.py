# TODO

def main():
    text = input("Text: ")
    count = count_letters(text)
    c_words = count_words(text)
    c_sentences = count_sentences(text)
    l = count / c_words * 100
    s = c_sentences / c_words * 100
    i = round(0.0588 * l - 0.296 * s - 15.8)
    print(f"{count} || {c_words} = {c_sentences}")
    if (i < 1):
        print("Before Grade 1\n")
    elif (i > 16):
        print("Grade 16+\n")
    else:
        print(f"Grade {i}\n")

def count_letters(letters):
    i = 0
    for letter in letters:
        if (letter.isalpha()):
            i+=1
    return i

def count_words(letters):
    i = 1
    for letter in letters:
        if(letter == " "):
            i+=1
        print(f"{letter}")
    return i

def count_sentences(letters):
    i = 0
    characters = (".", "!", "?")
    for letter in letters:
        if (letter in characters):
            i+=1

    return i
if __name__ == "__main__":
    main()
