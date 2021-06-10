all: setup-posix build

build: build-fin


# start of build compilation set

build-fin:
	g++ Gam.cpp -static -Wall -g -static-libgcc -static-libstdc++ -o ./bin/Gam.exe

build-compile:
	g++ -c -Wall -g Gam.cpp -o Gam.o

build-link:
	g++ -g -o ./bin/Gam.exe Gam.o

# end of build compilation set

setup-posix: 
	rm -rf bin
	clear
	mkdir bin

setup-win:
	rm /S /Q bin
	cls
	mkdir bin

makebin: 
	mkdir bin

install: install-usix

install-usix: 
	echo "not ready"
