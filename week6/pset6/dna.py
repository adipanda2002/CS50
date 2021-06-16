from sys import argv, exit
import csv

# function to determine how many times a substring repeats


def max_number_of_substrings(s, sub):
    
    ans = [0] * len(s)
    for i in range(len(s) - len(sub), -1, -1):
        if s[i: i + len(sub)] == sub:
            if i + len(sub) > len(s) - 1:
                ans[i] = 1
            else:
                ans[i] = 1 + ans[i + len(sub)]
    return max(ans)
    
# compares input to DNA database


def match_printer(reader, actual):
    for line in reader:
        person = line[0]
        values = [int(val) for val in line[1:]]
        if values == actual:
            print(person)
            return
    print("No match")
    

def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)  # checks for correct command line argument

    filename = argv[1]  # opens 'databases' files
    with open(filename) as csv_file:
        reader = csv.reader(csv_file)
        # for row in reader:
        #     print(row)
        all_sequences = next(reader)[1:]
        
        textname = argv[2]  # opens files in 'sequences' in order to make relevant comparisons
        with open(textname) as txt_file:
            s = txt_file.read()
            actual = [max_number_of_substrings(s, seq) for seq in all_sequences]
            
        match_printer(reader, actual)


if __name__ == "__main__":
    main()
