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
 *  @brief  Functions for Gam.cpp
 *  @author MXPSQL
 *  @date   2021-06-19
 ***********************************************/

// c++ functions here

#include <stdio.h>  /* defines FILENAME_MAX */
#include <iostream>
#include <string.h>

#ifdef _WIN32
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif


// operating system
#if defined(_WIN32)
    #define PLATFORM_NAME "windows32" // Windows
#elif defined(_WIN64)
    #define PLATFORM_NAME "windows64" // Windows
#elif defined(__CYGWIN__) && !defined(_WIN32)
    #define PLATFORM_NAME "cygwin" // Windows (Cygwin POSIX under Microsoft Window)
#elif defined(__ANDROID__)
    #define PLATFORM_NAME "android" // Android (implies Linux, so it must come first)
#elif defined(__linux__)
    #define PLATFORM_NAME "linux" // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
#elif defined(__unix__) || !defined(__APPLE__) && defined(__MACH__)
    #include <sys/param.h>
    #if defined(BSD)
        #if defined(__DragonFly__)
            #define PLATFORM_NAME "dragonflybsd"
        #elif defined(__FreeBSD__)
            #define PLATFORM_NAME "freebsd"
        #elif defined(__NetBSD__)
            #define PLATFORM_NAME "netbsd"
        #elif defined(__OpenBSD__)
            #define PLATFORM_NAME "openbsd"
        #else
            #define PLATFORM_NAME "bsd_unknown"
        #endif
    #else
        #define PLATFORM_NAME "unix"
    #endif
#elif defined(__hpux)
    #define PLATFORM_NAME "hp-ux" // HP-UX
#elif defined(_AIX)
    #define PLATFORM_NAME "aix" // IBM AIX
#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR == 1
        #define PLATFORM_NAME "ios" // Apple iOS
    #elif TARGET_OS_IPHONE == 1
        #define PLATFORM_NAME "ios" // Apple iOS
    #elif TARGET_OS_MAC == 1
        #define PLATFORM_NAME "osx" // Apple OSX
    #endif
#elif defined(__sun) && defined(__SVR4)
    #define PLATFORM_NAME "solaris" // Oracle Solaris, Open Indiana
#else
    #define PLATFORM_NAME "UNKNOWN"
#endif

#if !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)))
    #define UNIXPOSIX "POSIX"
#elif !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)))
    #define UNIXPOSIX "UNIX"
#else
    #define UNIXPOSIX "NOT"
#endif

using namespace std;

/// @brief get the operating system name
const string get_platform_name() {
    return PLATFORM_NAME;
}

/// @brief check if the os is posix or unix or neither
const string getposixorunixorneither(){
    return UNIXPOSIX;
}

/// @brief get user desktop
string getdesktop()
{
    string p = "";
    string pd = "";
    if(get_platform_name() == "windows32" || get_platform_name() == "windows64" || get_platform_name() == "cygwin"){
        p = getenv("USERPROFILE");
        pd = p + "\\desktop";
        return pd;
    }
    else if(get_platform_name() == "dragonflybsd" || get_platform_name() == "freebsd" || get_platform_name() == "netbsd" || get_platform_name() == "openbsd"){
        p = getenv("HOME");
        pd = p + "/Desktop/example.txt";
        return pd;
    }
    else{
        return "error, unknown os";
    }

}

/// @brief get current working directory
const string getmycwdir(){
    char buff[FILENAME_MAX];
    GetCurrentDir( buff, FILENAME_MAX );
    string current_working_dir(buff);
    return current_working_dir;
}