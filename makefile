CC=g++
CC_FLAGS=-Wall -Wextra -Wpedantic -std=c++17
LIBS=-lSDL2 -lSDL2_image 
OUT=imgviewer
RELEASE=-O3
DEBUG=-O0 -g -fbuiltin

all: clean build install

clean:
	-rm $(OUT)

build:
	$(CC) $(CC_FLAGS) $(RELEASE) $(LIBS) *.cpp -o $(OUT) -lstdc++fs

install: build
	sudo mv $(OUT) /bin/
