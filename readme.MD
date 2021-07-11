# Xombies and Nambaz

Game written in c++, Fight the zombies with numbers and get the highest score.

<hr>

## License

<hr>
Licensed with MIT and Apache License, although Apache is more dominant than MIT in this project, this is the reason
that apache license will appear in the github description and also this means that the apache license is more enforced than the mit license

Some of these headers are licensed with other license, see the otherlicense folder for more info, these license are copied to show their license
{hope that i won't get in trouble}

here is the spdx identifier: `SPDX-License-Identifier: Apache-2.0  AND MIT`

<hr>
story
<hr>
This game was originally a mix of two games and then compiled with msvc, but I decided to go with mingw.

<hr>
How to build and make documentation
<hr>
code dependency: [Boost](https://www.boost.org/), Pdcurses or Ncurses {whatever}, boehm garbage collector
build dependency: make, g++, windres(only if you compile for winows with icon), automake, autoconf, autoscan {You need [msys2](https://www.msys2.org/) for these on windows}

document dependency: make and doxygen to build a new documentation

### if you don't have it
install the code dependency and build dependency with your package manager of your choice

Open up your shell(unix) or open up mingw(in windows)
type make
go to bin once its done
excecute Gam.exe or ./Gam to play it.

build steps for windows without autotools
```
make -f=makefile.bak

cd bin

Gam.exe

```
build steps for linux without autotools
```
make -f=makefile.bak

cd bin

./Gam.exe

```


build steps with autotools

```
./configure

make

make install; sudo make install

```

to setup autotools

```
mv configure.scan configure.ac

autoconf

```

<hr>
Build docs, use

```
make doc
```
and make sure that doxygen is used


*warning, code may not be readable due to pdcurses and string