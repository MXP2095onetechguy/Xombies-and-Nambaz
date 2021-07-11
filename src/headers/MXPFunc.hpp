/*
* Copyright 2021 MXPSQL
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
*     http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

// SPDX-License-Identifier: Apache-2.0

/** 
 *  @file   MXPFunc.hpp
 *  @brief  Functions for Gam.cpp and maybe more
 *  @author MXPSQL
 *  @date   2021-06-19
 ***********************************************/

// c++ functions here

#include <stdio.h>  /* defines FILENAME_MAX */
#include <iostream>
#include <string.h>
#include <ctime> 
#include <chrono>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include <exception>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/generator_iterator.hpp>
#include <boost/random.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>


using namespace std;
using namespace std::chrono;
using namespace boost::multiprecision;
using namespace boost::random;

typedef independent_bits_engine<mt19937, 256, cpp_int> generator_type;
generator_type rngen(time(NULL));

/// @brief check if the header is included more than once (header guard)
#ifndef MXPFunc_hpp
/// @brief mark that the header is included
#define MXPFunc_hpp
// operating system
#if defined(_WIN32)
    /// @brief this os is windows 32 bit wth the content of the macros
    #define PLATFORM_NAME "windows32" // Windows32
    /// @brief mark that this os is windows 32 bit with macros
    #define WINDOWS32bit "WIN32"

    #if defined(__NT__)
        #define THENT "NT"
    #endif
#elif defined(_WIN64)
/// @brief this os is windows 64 bit wth the content of the macros
    #define PLATFORM_NAME "windows64" // Windows54
    /// @brief mark that this os is windows 64 bit with macros
    #define WINDOWS64bit "WIN64"
    #if defined(__NT__)
        #define THENT "NT"
    #endif
#elif defined(__CYGWIN__) && !defined(_WIN32)
    /// @brief this os is windows under cygwin with the content of the macros
    #define PLATFORM_NAME "cygwin" // Windows (Cygwin POSIX under Microsoft Window)
    /// @brief this os is windows under cygwin with macros
    #define CYGWIN "CYGWIN"
#elif defined(__ANDROID__)
    /// @brief this os is android with the content of the macros (linux)
    #define PLATFORM_NAME "android" // Android (implies Linux, so it must come first)
    /// @brief this os is android with macros (linux)
    #define ANDROID "ANDROID"
#elif defined(__linux__)
    /// @brief this os is linux with the content of the macros
    #define PLATFORM_NAME "linux" // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
    /// @brief this os is linux with macros
    #define THELINUX "theLINUX"
#elif defined(__unix__) || !defined(__APPLE__) && defined(__MACH__)
    #include <sys/param.h>
    /// @brief this macros mark that the os is unix(any kind of unix)
    #define THEUNIX "theunix"
    #if defined(BSD)
        #if defined(__DragonFly__)
            /// @brief this os is dragonflybsd unix with the content of the macros
            #define PLATFORM_NAME "dragonflybsd"
            /// @brief this os is dragonflybsd inux with macros
            #define DRAGONFLYBSD "DRAGONFLYBSD"
        #elif defined(__FreeBSD__)
            /// @brief this os is freebsd unix with the content of the macros
            #define PLATFORM_NAME "freebsd"
            /// @brief this os is freebsd linux with macros
            #define FREEBSD "FREEBSD"
        #elif defined(__NetBSD__)
            /// @brief this os is literally netbsd unix with the content of the macros
            #define PLATFORM_NAME "netbsd"
            /// @brief this os is literally netbsd unix with macros
            #define NETBSD "NETBSD"
        #elif defined(__OpenBSD__)
            /// @brief this os is that pufferfish, who is the mascot of openbsd unix with the content of the macros
            #define PLATFORM_NAME "openbsd"
            /// @brief this os is that pufferfish, who is the mascot of openbsd unix with macros
            #define OPENBSD "OPENBSD"
        #else
            /// @brief this os is bsd unix with the content of the macros, just unknown what bsd is this
            #define PLATFORM_NAME "bsd_unknown"
            /// @brief this os is bsd unix with macros, just unknown what bsd is this
            #define UNKNOWNBSD "UNKNOWNBSD"
        #endif
        /// @brief this macro marks that this unix is a bsd
        #define B_SD "BSD"
    #else
        /// @brief this macro marks that this unix, unknown unix
        #define PLATFORM_NAME "otherunix"
        #define OTHERUNIX "OTHERUNIX"
    #endif
#elif defined(__hpux)
    /// @brief this os is hp-ux with the content of the macros
    #define PLATFORM_NAME "hp-ux" // HP-UX
    /// @brief this os is hpux with macros
    #define HPUX "HP-UX"
#elif defined(_AIX)
    /// @brief this os is ibm's aix with the content of the macros
    #define PLATFORM_NAME "aix" // IBM AIX
    /// @brief this os is ibm's aix with macros
    #define AIX "AIX"
#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
    #include <TargetConditionals.h>
    /// @brief this macro marks that this an apple os
    #define APPLEMACH "APPLEMACH"
    #if TARGET_IPHONE_SIMULATOR == 1
        /// @brief this os is ios simulator with the content of the macros
        #define PLATFORM_NAME "iose" // Apple iOS
        /// @brief this os is ios simulator with macros
        #define IOSe "IOSe"
    #elif TARGET_OS_IPHONE == 1
        /// @brief this os is ios not simulator with the content of the macros
        #define PLATFORM_NAME "ios" // Apple iOS
        /// @brief this os is ios with macros
        #define IOS "IOS"
    #elif TARGET_OS_MAC == 1
        /// @brief this os is macos or osx with the content of the macros
        #define PLATFORM_NAME "osx" // Apple OSX
        /// @Brief this os is macos or osx with macros
        #define OSX "OSX"
    #endif
#elif defined(__sun) && defined(__SVR4)
    /// @brief die you dog solaris, this macro's content is not for you (joke)
    #define PLATFORM_NAME "solaris" // Oracle Solaris, Open Indiana
    /// @brief this is not solaris, but open indiana's macro
    #define SOLARIS "SOLARIS"
#else
    /// @brief wow, unknown of this os, the macro's content says it all
    #define PLATFORM_NAME "UNKNOWN"
    /// @brief you are dead in dog water, this is a dead giveaway and a showoff of you, unknown os
    #define UNKNOWN "UNKNOWN"
#endif

#if !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))) || defined(CYGWIN)
    #define UNIXPOSIX "POSIX"
    #define posix "POSIX"
#elif !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)))
    #define UNIXPOSIX "UNIX"
    #define gunix "unix"
#else
    #define UNIXPOSIX "UNIX"
    #define no_unix "NOT"
#endif


#if defined(WINDOWS32bit) || defined(WINDOWS64bit)
#include <windows.h>
#include <direct.h>
#include <errno.h>
#define GetCurrentDir _getcwd
#elif defined(THELINUX)
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <alsa/asoundlib.h>
#define GetCurrentDir getcwd
#elif defined(APPLEMACH)
#include <AudioUnit/AudioUnit.h>
#else
#endif



const string PlayerAbigail = 
"##%%%%%%&@&&&&&%*/*/***,////////////////////,,********/////((#%&%############### \n"
"%%%%%%%%&@&&&&&&&&%((((#/////////////////(((*,*******/////((#%%%################ \n"
"%%%%%%%%%%%%%%%%(((((((((//////////(#####%%#%********/////((#%######%########### \n"
"*********#%%%%%%///////(((///(#(#((((((####%%(*******/////((%#######%#%#%#%#%### \n"
"*****,,,**%%%%%%#**,*((((#####(######(((###%%%*******/////(##/#%&%#(#%&%(/////// \n"
",,,,,,,,,,*(((/*,,/(((((#((##(#(##(#######%%%%%*****/////((#**//*********/%###%# \n"
"/*/****,,,*(%%%/(((((#(((((/#######%####(((((#%*****/////(#%,,,***,******%&(#### \n"
"**,**/,,,,,*##((((#(((((////,####(//////((((((#/****////((##,,,,,,,,,,,*(%#,/### \n"
"***/**,,,,,,*(((((((((((/****,((((////////((((#%*****///((#,,,,,,,,,,,,*#((#*,(# \n"
"******,,,,,*/********//,,,,***(((/(////////((((#******//(#%*****/%%/(#////(##(,/ \n"
",,,,**,,,***,*********,,,,,,,***(((/////(((((((#%*****//(#/***,.,.,,,,,,,,,,,/(* \n"
",,,,,,..,,,*,,*,*,,***,...,,,**,,((////////(((((%*****//(%****,.,**********.,(## \n"
",,**,,. .,,*,,,,*,##*//,..,,,,,,*/((////////((((#****//(#%****,.,///////***.,&@@ \n"
"**********,,,,,,,,((///*,.,,,,,,,,((//////////(((%***/((#%,***,.,//////****.,/## \n"
",,,,,,,,,,,,,,,,,,//////*.,,,,.,,,,(///////////((%****/(#%****,.,////******,,/## \n"
",,,,,,,,,,,,,,,,,,///////.,,,,,,,,,((///(((/(//((#***//##%****,.,*,,,,,,,,,,.*## \n"
",,,,,,,,,,,,,,,,,,/(((((/..........((//((((((((((%**///(##......,//(((/((((*,*#% \n"
",,,,,,,,,,,,,,,,,,(((((((,.*(((###(////((((((((#%***////(#@@&#/.*(((####%%&%*/&% \n"
",,,,,,,,,,,,,,,,,,(#(((((/.*(((##(///(((((((((#%****///((#&@&%(,*&%%@@@%&@@@**&% \n"
",,,,,,,*(,,##(..(##(#####(.,((##//////((((((##&*****///((#@@&#%,/&#&@@@%&@@@/,%# \n"
"%%%%%%###**###*.(########(.,(((///////((((##%##(#######%%%&&#&&,/%#@@@@#&@@@%,%% \n"
"#%%######//##(/.((((((((((,,/(//////(((((##%&#((#(#%#####%&&&&&,(%%%&%%%%%%%%#&& \n"
"#########/*%%#(,(#(#(#((((*,(////(((((((##%(%#######%%%%%%&&&&#,(%&@@@@%&@@@@%%% \n"
"%%%%%%%%%#(%&%&(%%%#######(((//((((((((##%#((%####%%%&%%&&&&@@@@%%&%%%%%%%%%##%% \n"
"(########((###%(%@@&&&&%%%#(((((((((((##%&%##&&(((((((##%%#%%%%##%%%%%%%%%%%###% \n"
"(((((((##(((#(#(#&&&&&%%%%((((((((((((#%&%%%%%%((/((((##&###%%%##%%%%#%%%&@@@@%% \n"
"(###(############%&&&&%&%%((((((((((##%#%%%%%%%(((((((#%&%%&&&&%#%&&&&%%#%%@@&%% \n"
"###################&@&&&&((((((((((##%%%%%%%%%%(((/(((#%&%%%%%%%&@@@@@&#&@@@@@&% \n"
"###################%&&&&&(((((((((##%##&@@@&%##(((((((#%@@@@@&%%@@@@@@&%&@@@@@&% \n"
"####################&&&&(((((((((##%###%&&&&%#&((((((##&@@@@@&#&@@@@@@&%&@@@@@@% \n"
"###################%&@&&((((((((##%%@@@@@@@&%&@((//((#%@@@@@@%%@@@@@@@&%&@@@@@&% \n"
"####################&&&((((((((##%###%%%%%###%&((//((#&&@@@&%#%&@@@@@@&%&@@@@@@& \n"
"####################%&#(((((((##%&@@@@@@&%%@@@@#(/(((%@@@@@@%%@@@@@@@@&%&@@@@@@@ \n"
"####################%&(((((((###@@@@@@@&%%@@@@@((##%&&@@@@@&%&@@@@@@@@%%@@@@@@@@ \n"
"###################&@(((((((((#%@@@@@@&%&@@@@@#(//(#%@@@@@@%%&@@@@@@@@%%%%%%%%%% \n"
"###############%#%@@#(((((((((#@@@@@@&%&@@@@&,(///(#&@@@@@&%%%%%%%%%%%%%%%%%&&&& \n"
"###############%@@@(///(((((((#@@@@@&%&@@@@@%((///(#&&&%%%%%%%%%%%%%%%%&@@@@@@@@ \n"
"##%%%%%#%%%%%%&@@((*/((((((((((@@@@&%&@@@@@@%//*//#%@%%%%%%%&@@@@@@@@&%&@@@@@@@@ \n"
"%%%%%%%%%%%%&@@@/(((((((((((((((&@&%%%%%%%%%#(///(%&@@@@@&%&@@@@@@@@@&%&@@@@@@@@ \n"
"%%%%%%%%%%%&@@@@/(((((#(((((((((((%%%%%%%%%%(((/#%&%&@@@&%&&@@@@@@@@@&%&@@@@@@@@ \n"
"%%%%%%%%%&@@@@@@@((((((##((/((((((((%@@@@%##/*//%&%&%&@@&&&@@@@@@@@@@&%&@@@@@@@@\n"
"%%%%%%%%%%%%%%%%%%%(*%%%/((#&&%(//(///*#*(#((/(#&%@&&@@@&&@@@@@@@@@@@&%&@@@@@@@@\n"
"%%%%%%%%%%%%%%%%%%%#*@@&%%#/(#######(#####/((#((%@@@@@@&%&@@@@@@@@@@&&%&@@@@@@@@\n"
"#%%%%%%%%%%%%%%#####,(###((((,/(((##/((((/,.*(#%%&&@@&%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
"#%%%%%%&%%%%%%%%%%%%##%%%%%%%#%%&&@@@&&%%%%%%&&@@@@@@@&%%%&@@@@@@@@@&%%&&@@@@@@@\n"
"&@@@%##%%%%%%%%%%%%@@@@@@&%%&@@@@@@@@@@&%%&@@@@@@@@@@@&%&@@@@@@@@@@@&%&&@@@@@@@@\n"
"##########%%%%%@@@@@@@@@&%%&@@@@@@@@@@&%%&@@@@@@@@@@@&%%&@@@@@@@@@@@&%%&@@@@@@@@\n";

using namespace std;

/**
 * 
 * @brief get operating system/os name
 * 
 * @details get operating system/os name with preprocessor directives and macros
 * 
 * @return the name of the operating system/os
 * 
*/ 
const string get_platform_name() {
    return PLATFORM_NAME;
}

/**
 * 
 * @brief check if the os is posix, unix, or neither
 * 
 * @details check if the os is posix, unix, or neither with preprocessor directives and macros
 * 
 * @return is it posix, unix, or neither
 * 
*/ 
const string getposixorunixorneither(){
    return UNIXPOSIX;
}

/**
 * 
 * @brief get the user's desktop directory
 * 
 * @details get the user's home directory with enviorment variables and then add desktop to it
 * 
 * @return user's home directory
 * 
*/ 
string getdesktop()
{
    string p = "";
    string pd = "";
    if(get_platform_name() == "windows32" || get_platform_name() == "windows64" || get_platform_name() == "cygwin"){
        p = getenv("USERPROFILE");
        pd = p + "\\desktop";
        return pd;
    }
    else if(get_platform_name() == "dragonflybsd" || get_platform_name() == "freebsd" || get_platform_name() == "netbsd" || get_platform_name() == "openbsd" || get_platform_name() == "bsd_unknown" || get_platform_name() == "otherunix" || get_platform_name() == "linux"){
        p = getenv("HOME");
        pd = p + "/Desktop/example.txt";
        return pd;
    }
    else{
        return "error, unknown os";
    }

}

/**
 * 
 * @brief give the user's working directory
 * 
 * @details give the user's working directory
 * 
 * @return user's working directory
 * 
*/ 
const string getmycwdir(){
    char buff[FILENAME_MAX];
    GetCurrentDir( buff, FILENAME_MAX );
    string current_working_dir(buff);
    return current_working_dir;
}

void cd_dir(string dir)
{
    const char* dirr = dir.c_str();
    #if defined(WINDOWS32bit)
        _chdir(dirr);
    #elif defined(LINUX) || defined(THEUNIX) || defined(POSIX) || defined(gunix)
        chdir(dirr)
    #endif
}

/**
 * 
 * @brief get the user's home directory
 * 
 * @details get the user's home directory with enviorment variables
 * 
 * @return user's home directory
 * 
*/ 
string gethome()
{
    if(get_platform_name() == "windows32" || get_platform_name() == "windows64")
    {
        return getenv("USERPROFILE");
    }
    else if(get_platform_name() == "dragonflybsd" || get_platform_name() == "freebsd" || get_platform_name() == "netbsd" || get_platform_name() == "openbsd" || get_platform_name() == "bsd_unknown" || get_platform_name() == "otherunix" || get_platform_name() == "linux")
    {
        return getenv("HOME");
    }
    else{
        return "nohome";
    }
}

/**
 * 
 * @brief check if path exist
 * 
 * @details check if the path exist with istream, something is wrong or it is a file, false
 * 
 * @param filename name of directory or path be checked
 * 
 * @return do directory or path exist
 * 
*/ 
bool DirectoryExists(string pzPath)
{
    #if defined(THEUNIX) || defined(THELINUX) || defined(CYGWIN)
        struct stat st;
        const char* pathz = pzPath.c_str();
        if(stat(pathz,&st) == 0)
        {
            if(st.st_mode & S_IFDIR != 0){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    #elif defined(WINDOWS64bit) || defined(WINDOWS32bit)
        DWORD ftyp = GetFileAttributesA(pzPath.c_str());
        if (ftyp == INVALID_FILE_ATTRIBUTES){
            return false;  //something is wrong with your path!
        }
        else if (ftyp & FILE_ATTRIBUTE_DIRECTORY){
            return true;   // this is a directory!
        }
        else{
            return false;    // this is not a directory!
        }
    #endif

}

/**
 * 
 * @brief check if file exist
 * 
 * @details check if the file exist with istream, something is wrong, false
 * 
 * @param filename name of file to be checked
 * 
 * @return do file exist
 * 
*/ 
bool fileexist(string filename)
{
    std::ifstream ifile(filename);

    if(ifile)
    {
        return true;
    }
    else{
        return false;
    }
}


/**
 * 
 * @brief convert multicharacter char to string
 * 
 * @details convert multicharacter char to string, only works with char*
 * 
 * @param charterisk char to be converted
 * 
 * @return string after conversion
 * 
*/ 
string charterisktostring(char* charterisk){
    std::string stringy(charterisk);
    return stringy;
}

/**
 * @brief change integer to char
 * 
 * @details convert integer to string and then to char
 * 
 * @return constant char
 * 
 * @param intty int to be converted to char
 */
const char* inttochar(int intty)
{
    std::string strinky = to_string(intty);
    const char* charrr = strinky.c_str();
    return charrr;
}



/**
 * 
 * @brief convert single character char to string
 * 
 * @details char that have single characters get converted to string
 * 
 * @param c character to be converted
 * 
 * @return result of character to string
 * 
*/ 
string chartostring(char c){
    std::string strin_gy;
    strin_gy += c;
    return strin_gy;
}


/**
 *  @brief generate random numbers
 * 
 *  @details generate random numbers with boost.random
 * 
 *  @param min minimum number for randint
 *  
 *  @param max maximum number for randint
 * 
 *  @return result of boost.random
 */
int randint(int min, int max) { // new randomizer
    boost::random::uniform_int_distribution<> dist(min, max);
    int res = dist(rngen);
    return res;
}

/**
 * @brief clear screen
 * 
 * @details clear screen with system() and very cross platform
 * 
 * @warning the hacky method that uses system() if compromissed may be dangerous
 */ 
void clearcli()
{
    if(get_platform_name() == "windows32" || get_platform_name() == "windows64")
    {
        system("cls");
    }
    else if(get_platform_name() == "dragonflybsd" || get_platform_name() == "freebsd" || get_platform_name() == "netbsd" || get_platform_name() == "openbsd" || get_platform_name() == "bsd_unknown" || get_platform_name() == "linux" || get_platform_name() == "ios" || get_platform_name() == "IOS" || get_platform_name() == "osx")
    {
        system("clear");
    }
    else{

    }
}

/**
 * 
 * @brief pause cli
 * 
 * @details pause cli with system() and also very cross platform
 * 
 * @warning the hacky method that uses system() if compromissed may be dangerous and the foolproof method that this function uses may cause data loss due to going to shell and exit
 */ 
void pausecli()
{
    if(get_platform_name() == "windows32" || get_platform_name() == "windows64")
    {
        system("pause");
    }
    else if(get_platform_name() == "dragonflybsd" || get_platform_name() == "freebsd" || get_platform_name() == "netbsd" || get_platform_name() == "openbsd" || get_platform_name() == "bsd_unknown" || get_platform_name() == "linux" || get_platform_name() == "ios" || get_platform_name() == "IOS" || get_platform_name() == "osx")
    {
        system("$SHELL");
        string shell = getenv("0");
        if(shell == "zsh")
        {
            system("read '?Press any key to continue . . . '");
        }
        else if(shell == "bash")
        {
            system("read -p 'Press any key to continue . . . '");
        }
        else{

        }
        system("exit");
    }
    else{

    }
}

/**
 * @brief convert note to frequency
 * 
 * @details convert note to frequency with pow and bunch of maths
 * 
 * @param note note index
 * 
 * @return frequency of the note
 */ 
int notetofrequency(int note)
{
    int res = (440 * std::pow(2, ((note - 49) / 12)));
    return res;
}


/**
 * @brief check if command processor exist
 * 
 * @details check if command processor exist with system(NULL) if return not 0, good(true) else bad(false)
 * 
 * @result
 */ 
bool commandprocessorstatus()
{
    if(system(NULL))
    {
        return true;
    }
    else{
        return false;
    }
    return false;
}

/**
 * @brief change color code
 * 
 * @details change color code with system and returns code status
 * 
 * @param code code of the color
 * 
 * @return if the color changed or not
 * 
 * @warning the hacky method that uses system() if compromissed may be dangerous
*/ 
int setcolor(string code)
{
    const char* ccode = code.c_str();
    const char* command = "color ";
    std::string tmpp(command);
    tmpp.append(ccode);
    #if defined(WINDOWS32bit) || defined(WINDOWS64bit)
        system(tmpp.c_str());
        return 0;
    #else
        return 1;
    #endif
    return 1;
}

/**
 * @brief check is it divisible by 7
 * 
 * @brief check is it divisible by 7 using % and if the remainder is not zero no
 * 
 * @param dividend the number to be divided
 * 
 * @return is it divisible by 7
 */ 
bool mod7(int dividend)
{
    int remainder = (dividend % 7);
    if(remainder == 0)
    {
        return true;
    }
    else{
        return false;
    }

    return false;
}

#ifdef MXPDOOT
//Serge Zaitsev's code, visit https://github.com/zserge/beepto get your own copy
#if defined(WINDOWS32bit) || defined(THENT)
/// @brief beep with windows
int beep(int freq, int ms) { return Beep(freq, ms); }
#elif defined(THELINUX)
/* On Linux use alsa in synchronous mode, open "default" device in signed 8-bit
 * mode at 8kHz, mono, request for 20ms latency. Device is opened on first call
 * and never closed. */
#define ALSA_PCM_NEW_HW_PARAMS_API
/// @brief beep with ALSA
int beep(int freq, int ms) {
  static void *pcm = NULL;
  if (pcm == NULL) {
    if (snd_pcm_open(&pcm, "default", 0, 0)) {
      return -1;
    }
    snd_pcm_set_params(pcm, 1, 3, 1, 8000, 1, 20000);
  }
  unsigned char buf[2400];
  long frames;
  long phase;
  for (int i = 0; i < ms / 50; i++) {
    snd_pcm_prepare(pcm);
    for (int j = 0; j < sizeof(buf); j++) {
      buf[j] = freq > 0 ? (255 * j * freq / 8000) : 0;
    }
    int r = snd_pcm_writei(pcm, buf, sizeof(buf));
    if (r < 0) {
      snd_pcm_recover(pcm, r, 0);
    }
  }
  return 0;
}
#elif defined(APPLEMACH)

static dispatch_semaphore_t stopped, playing, done;

static int beep_freq;
static int beep_samples;
static int counter = 0;

static int initialized = 0;
static unsigned char theta = 0;

static OSStatus tone_cb(void *inRefCon,
                        AudioUnitRenderActionFlags *ioActionFlags,
                        const AudioTimeStamp *inTimeStamp, UInt32 inBusNumber,
                        UInt32 inNumberFrames, AudioBufferList *ioData) {
  unsigned int frame;
  unsigned char *buf = ioData->mBuffers[0].mData;
  unsigned long i = 0;

  for (i = 0; i < inNumberFrames; i++) {
    while (counter == 0) {
      dispatch_semaphore_wait(playing, DISPATCH_TIME_FOREVER);
      counter = beep_samples;
    }
    buf[i] = beep_freq > 0 ? (255 * theta * beep_freq / 8000) : 0;
    theta++;
    counter--;
    if (counter == 0) {
      dispatch_semaphore_signal(done);
      dispatch_semaphore_signal(stopped);
    }
  }
  return 0;
}
/// @brief beep with audiounit
int beep(int freq, int ms) {
  if (!initialized) {
    AudioComponent output;
    AudioUnit unit;
    AudioComponentDescription descr;
    AURenderCallbackStruct cb;
    AudioStreamBasicDescription stream;

    initialized = 1;

    stopped = dispatch_semaphore_create(1);
    playing = dispatch_semaphore_create(0);
    done = dispatch_semaphore_create(0);

    descr.componentType = kAudioUnitType_Output,
    descr.componentSubType = kAudioUnitSubType_DefaultOutput,
    descr.componentManufacturer = kAudioUnitManufacturer_Apple,

    cb.inputProc = tone_cb;

    stream.mFormatID = kAudioFormatLinearPCM;
    stream.mFormatFlags = 0;
    stream.mSampleRate = 8000;
    stream.mBitsPerChannel = 8;
    stream.mChannelsPerFrame = 1;
    stream.mFramesPerPacket = 1;
    stream.mBytesPerFrame = 1;
    stream.mBytesPerPacket = 1;

    output = AudioComponentFindNext(NULL, &descr);
    AudioComponentInstanceNew(output, &unit);
    AudioUnitSetProperty(unit, kAudioUnitProperty_SetRenderCallback,
                         kAudioUnitScope_Input, 0, &cb, sizeof(cb));
    AudioUnitSetProperty(unit, kAudioUnitProperty_StreamFormat,
                         kAudioUnitScope_Input, 0, &stream, sizeof(stream));
    AudioUnitInitialize(unit);
    AudioOutputUnitStart(unit);
  }

  dispatch_semaphore_wait(stopped, DISPATCH_TIME_FOREVER);
  beep_freq = freq;
  beep_samples = ms * 8;
  dispatch_semaphore_signal(playing);
  dispatch_semaphore_wait(done, DISPATCH_TIME_FOREVER);
  return 0;
}
#else
#error "unknown platform"
#endif
#endif

#endif