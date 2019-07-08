"""
A Python script to normalize the dictionary
and convert all the words to the UTF-8 format.
"""


def main():
    """The main function."""
    with open("../data/large.words", "r") as file:
        # I know, this is not "Pythonic," but I do not care (:
        lines = sorted(
            set(
                filter(
                    lambda x: x.strip("\n").isalpha(),
                    map(lambda x: x.lower(), file.readlines()),
                )
            )
        )

    with open("../data/normalized.words", "w") as new_file:
        for line in lines:
            if "'" not in line:
                line = bytes(line, "utf-8").decode("utf-8", "ignore")
                new_file.write(line)


if __name__ == "__main__":
    main()
