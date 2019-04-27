# Default
all:
	cd src && g++ -Wall -Werror -Wextra -std=c++17 -o "autocomplete" spellcheck_main.cpp

# Run the executable
run:
	@read -p "Enter a prefix: " prefix && cd src && ./autocomplete $$prefix

# Remove object files and the executable
clean:
	cd src && rm -f autocomplete

# Don't display instructions while running
.SILENT:
	run
