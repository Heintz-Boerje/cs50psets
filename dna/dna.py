import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) > 3 or len(sys.argv) < 2:
        print("Usage: python dna.py [database] sequence")
        sys.exit(1)
    elif len(sys.argv) == 2:
        dna_base = 'databases/large.csv'
        dna_seq = sys.argv[1]
    else:
        dna_base = sys.argv[1]
        dna_seq = sys.argv[2]

    # TODO: Read database file into a variable
    with open(dna_base, 'r') as database:
        data_read = csv.DictReader(database)

        # TODO: Read DNA sequence file into a variable
        with open(dna_seq, 'r') as sequence:
            seq = sequence.read()


        # TODO: Find longest match of each STR in DNA sequence
        longest_agatc = longest_match(seq, "AGATC")
        longest_aatg = longest_match(seq, "AATG")
        longest_tatc = longest_match(seq, "TATC")


        # TODO: Check database for matching profiles
        for line in data_read:
            if int(line["AGATC"]) == longest_agatc:
                if int(line["AATG"]) == longest_aatg:
                    if int(line["TATC"]) == longest_tatc:
                        print(line["name"])
                        sys.exit(0)

        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
