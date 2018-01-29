compile:
	g++ -Wall -Wextra -Wpedantic -std=c++17 -O3 -lSDL2 -lSDL2_image  *.cpp -oimgviewer -lstdc++fs
