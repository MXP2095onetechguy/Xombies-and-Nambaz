fin-file = "./bin/Gam.exe"
fin-winfile = "./bin/Win-Gam.exe"
fin-nixfile = "./bin/Gam.elf.o"
srcpp = "Gam.cpp"
ocpp = "object.o"
icnsobj = "icon.o"
icnsrc = "resource.rc"




all:setup-posix build

build: build-fin-noicns

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
	g++ $(srcpp) $(icnsobj) -static -Wall -g -static-libgcc -static-libstdc++ -o $(fin-winfile)

build-fin-noicns:
	g++ $(srcpp) -static -Wall -g -static-libgcc -static-libstdc++ -o $(fin-file)

build-compile:
	g++ -c -Wall -static -g -static-libgcc -static-libstdc++ $(srcpp) -o $(ocpp)

build-link:
	g++ -static -Wall -g -static-libgcc -static-libstdc++ $(ocpp) -o $(fin-file)

build-icns-win:
	windres -i $(icnsrc) -o $(icnsobj)

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
