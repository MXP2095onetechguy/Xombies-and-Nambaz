# make variables
SHELL=/bin/bash
CXX = g++
CXXFLAGS = -fdiagnostics-color -Wl,-static -fpermissive -static -Wall -g -static-libstdc++ -O2 -LC:./src/headers/PDCurses/wincon -o
# file variables
fin-file = "./bin/Gam.exe"
fin-winfile = "./bin/Win-Gam.exe"
fin-nixfile = "./bin/Gam.elf.o"
srcpp = "./src/Gam.cpp"
ocpp = "./src/Gam.o"
pdcursesobj = "./src/headers/PDCurses/wincon/*.o"
icnsobj = "./src/icon.o"
icnsrc = "./src/resource.rc"





all: setup-posix build


build: build-fin-noicns

build-win: icon.o build-fin

test : test-makevar

# start of test

test-makevar:
	echo $(fin-winfile)
	echo $(fin-file)
	echo $(srcpp)
	echo $(ocpp)
	echo $(icnsobj)
	echo $(icnsrc)

# end of test

# start of build compilation set

# build-unix: g++ $(srcpp) -static -Wall -g -static-libgcc -static-libstdc++ -o $(fin-nixfile)

build-fin:
	$(CXX) $(pdcursesobj) $(CXXFLAGS)  $(fin-winfile) $(srcpp) $(icnsobj) -lpdcurses

build-fin-noicns:
	$(CXX) $(CXXFLAGS) $(fin-file) $(srcpp) $(pdcursesobj) -lpdcurses

build-fin-unix-icns: build-fin

build-compile:
	$(CXX) -c $(srcpp) $(CXXFLAGS) $(srcpp) -o $(ocpp)

build-link:
	$(CXX) -static $(CXXFLAGS) $(fin-file) $(ocpp)

build-icns-win:
	windres -i $(icnsrc) -o $(icnsobj)

# end of build compilation set

# start of document builder

docs: doc

document: doc

documents: doc

doc: 
	doxygen Doxyfile

# end of document builder

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

rm: clean

clean:
	clear
	rm -rf bin
	rm *.o

install: install-usix

install-usix: 
	echo "not ready"