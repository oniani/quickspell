"""
A Python script to normalize the dictionary
and convert all the words to the UTF-8 format.
"""


def main():
	with open('../data/large.words', 'r') as file:
		lines = sorted(set(map(lambda x: x.lower(), file.readlines())))

	with open('../data/normalized.words', 'w') as new_file:
		for line in lines:
			if '\'' not in line:
				line = bytes(line, 'utf-8').decode('utf-8', 'ignore')
				new_file.write(line)


if __name__ == "__main__":
	main()
