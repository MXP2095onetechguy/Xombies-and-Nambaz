# make variables
SHELL=/bin/bash
CXX = g++
CXXFLAGS = -fdiagnostics-color -static -Wall -g -static-libgcc -static-libstdc++ -O2 -o
# file variables
fin-file = "./bin/Gam.exe"
fin-winfile = "./bin/Win-Gam.exe"
fin-nixfile = "./bin/Gam.elf.o"
srcpp = "Gam.cpp"
ocpp = "Gam.o"
icnsobj = "icon.o"
icnsrc = "resource.rc"





all: setup-posix build


build: icon.o build-fin-noicns

build-win: build-fin

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
	$(CXX) $(srcpp) $(icnsobj) $(CXXFLAGS) $(fin-winfile)

build-fin-noicns:
	$(CXX) $(srcpp) $(CXXFLAGS) $(fin-file)

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