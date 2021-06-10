fin-file = "./bin/Gam.exe"
fin-winfile = "./bin/Win-Gam.exe"
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

build-fin:
	build-icns-win g++ $(srcpp) $(icnsobj) -o $(fin-winfile)

build-fin-noicns:
	g++ $(srcpp) -static -Wall -g -static-libgcc -static-libstdc++ -o $(fin-file)

build-compile:
	g++ -c -Wall -g $(srcpp) -o $(ocpp)

build-link:
	g++ -g $(ocpp) -o $(fin-file)

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
