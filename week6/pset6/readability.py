from cs50 import get_string

text = get_string("Text: ").strip()  # obtain text from user
number_of_letters = number_of_words = number_of_sentences = 0

for i in range(len(text)):
    if text[i].isalpha():
        number_of_letters += 1  # find number of letters
    if (i == 0 and text[i] != ' ') or (i != len(text) - 1 and text[i] == ' ' and text[i + 1] != ' '):
        number_of_words += 1  # find number of words
    if text[i] == '.' or text[i] == '?' or text[i] == '!':
        number_of_sentences += 1  # find number of sentences

L = number_of_letters / number_of_words * 100
S = number_of_sentences / number_of_words * 100
index = round(0.0588 * L - 0.296 * S - 15.8)
# Coleman-Liau index

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
