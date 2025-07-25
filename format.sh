# Command used to format code.
# Start by installing astyle, ie on ubuntu "$sudo apt install astyle"
astyle --style=attach --break-blocks=all --pad-oper --pad-comma --pad-header --suffix=none  ./src/*.hpp ./src/*.cpp
