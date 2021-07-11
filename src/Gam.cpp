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
*
* Copyright (c) <year> <copyright holders>
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

// SPDX-License-Identifier: Apache-2.0  AND MIT


/* install boost by dropping the boost library onto the include folder in the c++ include folder of g++ */
/* install plog by gitcloning the repository here https://github.com/SergiusTheBest/plog and getting all the files at include and dropping it to the c++ include folder of g++ */

// some of these code is original, while some are transplanted from my msvc code, and maybe the transplanted code is modified

/* JSUlJSUlJSUlJUBAJiYmJiYmJSMvLy8vLyoqKiwqLy8vLy8vLy8vLy8vLy8vLy8vLy8vLygvKiwsKioqKioqKioqLy8vLy8vLygoIyUlJiUlIyMjIyMjIyMjIyMjIyMjIyMjIwolJSUlJSUlJSUlJkAmJiYmJiYmJiYmJSgoKCgoIyMoLy8vLy8vLy8vLy8vLy8vLy8vLy8oKCgvKiwqKioqKioqKiovLy8vLy8oKCgjJSUlJSMjIyMjIyMjIyMjIyMjIyMjIyMjCiUlJSUlJSUlJSUlJSUlJSUlJSUlIygoKCgoKCgoKC8vLy8vLy8vLy8vLy8vLy8oIyMjIyUlJSUlKiwqKioqKioqKi8vLy8vLygoKCMlJSMjIyMjIyMjIyMjIyMjIyMjIyMjIyMKJSMoKC8vKioqLyMlJSUlJSUlJSMoLygoKCgoKCgoKC8vLy8vLy8vKCMjIyMjKCMjIyMjJSUjJSUvKioqKioqKioqKi8vLy8vKCgjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIwoqKioqKioqKioqKiglJSUlJSUlIy8vKi8vLy8vKCgoKC8vKCMjIyMoKCgjIyMjKCgjIyMjIyMlJSMqKioqKioqKiovLy8vLy8oKCMjIyMjIyMjIyMjIyUjIyMjIyMjIyMjIyMjCioqKiosLCwsKioqKiMlJSUlJSUlKCoqLCovKCgoKCgjIyMjIyMoKCMjIygjIyMoKCgoIyMjIyUlJS8qKioqKioqKi8vLy8vKCgoIygvIyUmJiUoLy8jJSYlIy8qLy8vKCgoKCgKLCwsLCwsLCwsLCwqKi8oLy8vKi4gICooKCgoKCgoKCwgLiMjIygoKCgoIyMjIyggLigjIyUlJSUlIyoqKioqKioqLy8vLy8oKCMjLyovLy8vLCAgLCoqKi4gLi8jIyMjIyMjIwosLCoqKioqKiwsLCwqKCUlJSUsICAgIC8oKCgoKCgoLCAuKCMjKCMjIyMjIyMjIyMlIyMjIyMjIyMjLyoqKioqKi8vLy8vLygoIyMqLCwsKiosLCoqKiosLiAsIyUlIyMjIyMjCioqKioqKiosLCwsLCoqIyUlLyAuKC8gIC8oKCgoKCgsICAvLy8qKi8oIyMoKCgvKiovKCgoKCgoLy8qLCwqLCwqLy8vLy8vKiovLCwsLCwsLCwuLiwsKiouIColJS8vIyMjIyMKKiosLCoqKiwsLCwsLCwqKCogICgoKC8gIC8oKCgoKCwgICAuLygvKiAgLi8vLy8gICovKCgqICAqKCgqLiAgICwvLy8vICwvKCMsICAuLCwsLCAgLiwsLC4gKiMjLywqKCMjIwoqKioqKioqLCwsLCwsLCwsICAoKCgoKCogLi8oKC8vLiAgKiosLygoKC4gLC8vLyAgKi8vKiAuKCgjIygqKi4gLCovLy8vKCgoKi4uICAsLCwsICAuLCwsLiAqKCgjKCosLyMjCioqKioqKiosLCwsLCwsLCAgLi4uLi4uLiAgLi8qLCwuICAqKiovKCgoLiAsLy8vICAqLy8sICwoKCgjIyoqLiAsKi8vLiAuKigsLCwgICoqKCMgICooKC8uICwvKCgjIy8qKigKLCwsKioqKiwsLCwqKiogICwqKioqKioqKi4gICwsLC4gIC4sKioqLywgLi8vLy8gICovLyogICwoKCMjLy4gIC4qKiwgIC8jKCosLiAgLCoqKiAgLC8vLy4gLCoqKiovKC8qKgosLCwsLCwsLC4sLCwsICAuLCoqKiosLCwqKi4gIC4uICAgLC4gICAgLC8vLy8vLyAgKi8vLy8qLiAgIC4qLC4gLioqLyosICAgIC4sICAuLiwuICAuLi4uICAgLi4uLiwoIygvCiosKiosLCwuLi4sLCwqKiwsLCwsLCwqKioqLCwsLi4uLCwsLCoqLCwqKCgvLy8vLy8vLy8vLygoKCgoIyMqICAqKiovLygjJS8qKioqLC4uKi8vLy8vLyoqKioqKiwuLCgjIyUKLCwsLCwsLC4uIC4uLCwqLCwsLCwsKigjLyovLyosLi4sLCwsLCwsLCovKCgvLy8vLy8vLy8uICAuLi4gICAuKioqLy8oKCMlLyoqKiosLiwqLy8vLy8vLy8qKioqLC4sIyYlJQoqKioqKioqKiwsLCwsLCwsLCwsLCwqKCgvKi8vKiwuLiwsLCwsLCwsLCwvKC8vLy8vLy8vLy8vLy8oKCgjKCoqKiovKCgoIyUvKioqKiwuLCovLy8vLy8vLyoqKiosLiwvIyMjCiwsLCwsLCwsLCwsLCwsLCwsLCwsLCovLy8vLy8vKiwuLCwsLCwsLCwsLCooKC8vLy8vLy8vLy8vLy8oKCgjKioqKi8vKCgjIyoqKioqLC4sKi8vLy8vLyoqKioqKiwuLC8jIygKLCwsLCwsLCwsLCwsLCwsLCwsLCwsLCovLy8vLy8qLC4sLCwsLCwsLCwsLC8oLy8vLy8vLy8vLy8vLygoKCMvKioqKi8oIyMjKioqKiosLiwqKioqKioqKioqKioqLC4sLyMjKAosLCwsLCwsLCwsLCwsLCwsLCwsLCwqLy8oKCgvLy8qLiwsLCwsLCwsLCwqLygoLy8vKCgoKCgoKC8vKCgoIygqKiovLygjIyMvKioqKiwuLCwsLCwsLCwsLCwsLCwsLiwqKCMjCiwsLCwsLCwsLCwsLCwsLCwsLCwsLCovKCgoKCgoKC8uLi4uLi4uLi4uLi4oKC8vLygoKCgoKCgoKCgoKCMjLyoqLy8vKCgjIywuLi4uLiwsKi8oKCgjIygoIyMjIygqLCojIyUKLCwsLCwsLCwsLCwsLCwsLCwsLCwsKigoKCgoKCgoLywuLC8oKCgoIyMjKCgvLy8vKCgoKCgoKCgoKCgjIyoqKiovLy8vKCgjJiYmJSMvLCwqKCgoIyMjIyUlJiUlJSgqLyYlJQosLCwsLCwsLCwsLCwsLCwsLCwsLCwqKCgoKCgoKCgoKi4sLygoKCMjIygvLy8vLygoKCgoKCgoKCgoIygqKioqLy8vLy8oKCMjIyMjIygsLC8lJSMlJkBAJSMlJkAmIyovJSUlCiwsLCwsLCwsLCwsLCwsLCwsLCwsKi8oIygoKCgoKCgvLiwvKCgoIyMoLy8vLy8oKCgoKCgoKCgoIyMoKioqKioqLy8vLygoIyZAJiYjIywsKCYlJSZAQEAmJSZAQEAlKiolJSMKLCwsKiovKCgjIygsLCgjIygsLiooIyMjIyMjIyMjIyguLC8oKCgoKC8vLy8vLy8oKCgoKCgoIyMlJS8qKioqKi8vLy8oKCgjJkAmJSMlKiwoJSMlJkBAJiUjJSYmJiUqLCMlIwolJSUlJSUlIyMjIyoqKCMjIy8uLCgjIyMjIyMjIyMjKCwsKigoKC8vLy8vLy8vLygoKCgoIyMlJSUjKCgjIygoIyMjIyMlJSUmJiYlJkAvLCglIyZAQEBAJiUmQEBAJigvIyUjCiUlJSMlIyMjIyMoLyooIygoLywsKCgoKCgoKCgoKCgoKi4qLygvLy8vLy8vKCgoKCgoKCMjJSUlJSMoKCgoKCMjIyMjIyMlJSUmJiYmJiMqKCUlJSYmJiUlJSUlJSUlIyMlJSUKIyMjIyMjIyMjIygvKiglIyMoLCooKCgoKCgoKCgoKCgqLiovLy8vLy8vKCgoKCgoKCgoIyUjIyUjIyMjKCMjIygjIyMjJSUlJiYmJiYlKiooJSUmJiYmJiYlJkBAQEBAJSUlJQojIyMjIyMjIyMjIygvIyUlJSUoKCMjIyMjIyMjIyMjIygoKCgvLygvKCgoKCgoKCgoKCMlIygoJSYlJSUjIyMlJSUlJSUlJSYmJiYmQEBAJiYmJkBAQEAmJiUlJSUlJSMjIyUlCiUlJSUlJSUlJSUlIygjJiYlJSMoIyUlIyMjIyMjIyMjIygoLy8oKCgoKCgoKCgoKCMjJSUjKCgjIyMoKCgjIyMjJSUlJSYlJiYmJiYmJiUjJSUlJSUlJSUlJSUlJSUjIyMjJSUKKCgoIyMjIyMjIyMoKCgjIyMjIyMlJiYmJiYlJSUlJSUjKCgvKCgoKCgoKCgoKCgjIyUmJiYlIyUmJiMoKCgoKCgoKCMjJSUlIyMlJSUlIyMjJSUlJSUlJSUlJSUlJSMjIyMlJQooKCgoKCgoKCMoKCgoKCgoIyMoIyUmJiYmJiYlJSUlJSMoLygoKCgoKCgoKCgoKCMlJiYlJSMlJSUjIygvLy8oKCgoKCMlJSUjIyUlJSUjIyMjJSUlJSUlJSUlJSYmQEAmJSUlCiMjIyMjIyMjIyMjIyMjIyMjIyMjIyUmJiYmJiYmJiUlKCgoKCgoKCgoKCgoKCMjJSUlIyUlJSUlJSUjKCgvKCgoKCgjIyUlJSUlJSUlJSUjIyUmQEBAQCYlJSMlJSUlJSUlJSYKIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMmQCYmJiYmJiMoKCgoKCgoKCgoKCgjIyUlJSUlJSUlJSUlJSMoKC8oKCgoKCMjJSYmQEBAJiYmJSMjJSUmJiYmJSUlJkBAQEBAQCYlJgojIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyUmJiYmJiYmKCgoKCgoKCgoKCgoIyMlJSMlJSUlJSYmJiYlIygoLygoKCgoIyUmJiYmJiYmJiUlJkBAQEBAQEAmJSUmQEBAQEBAJiYmCiMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyUmJiYmJiMoKCgoKCgoKCgoKCMjJSUjIyUlJiYmJSUlIyMjKCgoKCgoKCgjJSZAQEBAQEAmJSUmQEBAQEBAQCYlJUBAQEBAQEAmJiUKIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjJSYmJiYlKCgoKCgoKCgoKCgjIyUlIyMjJSUmJiYmJSMlJiUoKCgoKCgoIyMmQEBAQEBAQCYjJSZAQEBAQEBAJiUlQEBAQEBAQEAmJQojIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMlJiYmJiMoKCgoKCgoKCgoIyMlJSUmQEBAQEBAQCYlJSZAJSgoLy8oKCgjJSZAQEBAQEAmJSUmQEBAQEBAQEAmJSZAQEBAQEBAQCYlCiMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyUmJiYlKCgoKCgoKCgoIyMjJSUlJiZAQEAmJiYlJSMlJSYjKCgvLygoKCMlJSUlJSUlIyMjIyMlJSUlJSUlJSUjIyMlJSUlJSUlJSUKIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjJSYmJigoKCgoKCgoKCgjIyUlJSZAQEBAQEAmJiUlJkBAJiMoKC8vKCgoIyZAQEBAQEAmJSUmQEBAQEBAQEBAJiUlJkBAQEBAQEBAJgojIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMlJSYlKCgoKCgoKCgoIyMjJkBAQEBAQEBAQCYlJSZAQEBAJSMoKCgoKCMlJkBAQEBAQCYlJSZAQEBAQEBAQEAmJSZAQEBAQEBAQEAmCiMjIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMlJSgoKCgoKCgoKCMjIyVAQEBAQEBAQEAmJSUmQEBAQEAjKCMjIyMlJSZAQEBAQEBAJSUmQEBAQEBAQEBAQCYlJkBAQEBAQEBAQCYKIyMjIyMjIyMjIyMjIyMjIyMjIyMjIyMlJiYjKCgoKCgoKCgoKCMjJkBAQEBAQEBAJiUmQEBAQEBAJSgvLy8oKCMlJkBAQEBAQCYlJSZAQEBAQEBAQEAmJiUlJSUlJSUlJSUlJQojIyMjIyMjIyMjIyMjIyMjIyMjIyMjJSZAJSgoKCgoKCgoKCgoIyVAQEBAQEBAQCYlJkBAQEBAJigvKC8vLy8oIyVAQEBAQEBAJSUlQEBAQEBAQCYmJSUjJSUlJSUlJSUlJSUlCiMjIyMjIyMjIyMjIyMjIyMjIyUlJSZAQCYoLy8vKCgoKCgoKCMjJkBAQEBAQEAmJSZAQEBAQEAjLygvLy8vLyglJkBAQEBAQCYlJSUlJSUlJSUlJSUlJSUlJSYmQEBAQEBAQEAKIyMjIyMjIyMjIyMjIyMjIyMjJSZAQEAjKC8vLygoKCgoKCgoKCMmQEBAQEAmJiUmQEBAQEBAQC8vKC8vLy8oIyUmJiUlJSUlJSUlJSUlJSUlJSUlJiUlJSUmQEBAQEBAQEBAQAojIyMjJSUlJSUlJSUlJSUlJSZAQCYjKC8vLygoKCgoKCgoKCgoKCVAQEBAJiYlJkBAQEBAQEBALyovLyovKCMlJiYlJSUlJSUlJSYmQEBAQEBAQEBAQCYlJSZAQEBAQEBAQEBACiUlJSUlJSUlJSUlIyMlJSUmQEAmKCgoKCgoKCgoKCgoKCgoKCgoKCVAQCYmJSUlJSUlJSUlJSUqLy8qLy8oIyUmQCYmJiYmJiUmJkBAQEBAQEBAQEBAJiUmJkBAQEBAQEBAQEAKJSUlJSUlIyMjJSUjJSUmQEBAQCgoKCMoKCgoKCgoKCgoKCgoKCgoKCglJSUlJSUlJSUlJSUlJS8vLy8vIyMlJkBAQEBAQCYmJSZAQEBAQEBAQEBAQEAmJSZAQEBAQEBAQEBAQAolJSUlJSUlJSUlJSUmQEBAQEBAIygoIyMoKCMoKCgoKCgoKCgoKCgoKCgoIyUlJiYmJiYmJiUoKCgoLyglJSZAJiZAQEBAJiUmJkBAQEBAQEBAQEBAQCYlJkBAQEBAQEBAQEBACiUlJSUlJSUlJSUmQEBAQEBAQEBAJigoKCgoKCgoKCgoKCMoKCgoKCgoKCgoKCVAQEAmJSMjIygvLy8oIyYmJSYmJiZAQEAmJiZAQEBAQEBAQEBAQEAmJiUmQEBAQEBAQEBAQEAKJSUlJSUlJSUlJSUlJSUlJSUlJSUlJSMoLy8jJSMoLygoIyUmJiUjKCgvLygvLy8vKCgoIyMoLy8vKCMlJiYmJiUlJkBAQCYmQEBAQEBAQEBAQEBAQCYmJSZAQEBAQEBAQEBAQAolJSUlJSUlJSUlJSUlJSUlJSUlJSUlJSUoKCZAQEBAJS8vKCMlJSMjIyMjIygjIyMoKCMoKCgoKCgvKi8vKCUmQEBAQCYmJSYmQEBAQEBAQEBAQEBAJiYlJkBAQEBAQEBAQEBACiUlJSUlJSUlJSUlJSUlJSUlJSUlJSUlJSgvKCMjIyMjIyMvLygoIyMjJSUlJSMjIyMoIyMjKC8vKCVAQEBAQEBAQCYmJSUlJSYmJiYmQCYmJiYmJiUlJSUlJSYmJiYmJiYmJSUKIyMlJSUlJSUlJSUlJSUlJSUjIyMjIyMjKCgjIyMjIyMjKCgoLyoqKioqKioqKioqKioqKi8vKCgjIyUlJSUmJiYmJiUlJSUlJSUlJSUlJSUlJSUlJSUlJSUlJSUlJSUlJSUlJQojJSUlJSYmJiYmJSUlJSUlJSUlJSUlJSUjIyMlJSUmJiUlJSMlJSYmJkBAQEBAQCYmJSUlJSUlJiZAQEBAQEBAQEBAJiUlJSYmQEBAQEBAQEBAQEAmJiUlJiZAQEBAQEBAQEBACiZAQEAmJSUlJSUlJSUlJSUlJSUlJSUlJiZAQEBAQEAmJSUlJkBAQEBAQEBAQEBAQCYlJSUmJkBAQEBAQEBAQEBAQEAmJSUmQEBAQEBAQEBAQEBAQEAmJSUmQEBAQEBAQEBAQEAKIyMjIyMjIyMjIyMlJSUlJSUlJSZAQEBAQEBAQEAmJiUlJSZAQEBAQEBAQEBAQEAmJiUlJSZAQEBAQEBAQEBAQEBAJiYlJSZAQEBAQEBAQEBAQEBAJiYlJSZAQEBAQEBAQEBAQAo= */

/** 
 *  @file   Gam.cpp
 *  @brief  Game with numbers and zombies
 *  @author MXPSQL
 *  @date   2021-06-15
 ***********************************************/

/// @brief for msvc
#define _CRT_SECURE_NO_WARNINGS

/* Esentiall, this is console IO, must have in c++ or c programs. */
#include <iostream>
#include <stdio.h>
/* End of console IO. */

#include <string.h>
#include <exception>
#include <thread>
#include <fstream>
#include <chrono>
#include <future>
#include <vector>
#include <csignal>
#include <filesystem>
#include <ctime> 
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>
#include "headers/PDCurses/curses.h"

#include "headers/doot.h"
#include "headers/term.hpp"
#include "headers/MXPFunc.hpp"

/// @brief green text
#define GRN "\e[0;32m"
/// @brief red text
#define RED "\e[0;31m"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
using namespace boost::multiprecision;
using namespace boost::random;
using namespace plog;




string* blank = new string("");
string buffer = "";
string title = "Xombies-and-Nambaz";
bool showstat = true;
string compname = "Abigail";
string defname = compname;
string name = defname;
int maxtries = 8;
int zeconds = 0;
string desktop = getdesktop();
string filename = (title + "_Game-Final-Stats.txt");
string logname = (title + "_Game-Log.log");
bool cheatmode = false;
bool hushmusic = false;
bool nolog = false;
const string thisisyouimg = "##%%%%%%&@&&&&&%*/*/***,////////////////////,,********/////((#%&%############### \n"
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

promise<void> signal_exit_musix_thread; //create promise object
std::future<void> futura = signal_exit_musix_thread.get_future(); // create future objects


promise<void> signal_exit_time_thread; //create promise object
std::future<void> futura2 = signal_exit_time_thread.get_future(); // create future objects

class AbigailSaphiroRuntimeThiccBreastException : public exception {
	public:
		const char* what() const throw()
		{
			return "What, EXCEPTION Exception because Abigail Saphiro's breast are to fat and your female t-strap high heel shoes for female's bow tie is falling off, also your t-strap is torn on your t-strap high heel shoe"
"and also the fact that you are sexy and better destory those flats and high heel"
"and tear the straps on the flats and the high heel and now your bow tie on your t-strap high heel shoes bow tie has fallen off, and they smell horrible as Abigail Saphiro's breast scent and her feet scent combined, P-U, hope that your already broken t-strap high heel's heel breaks off and you use a plier to pull the sole out and use anther heel to break the t-strap heel, what a jerk of that t-strap shoe and she deserved to be destroyed, however Abigail Saphiro's feet should be licked by a goat to scrape her skin off and you better make her breast thicc!";
		}
};



AbigailSaphiroRuntimeThiccBreastException ASRTBE;


// functions


void keyboardinterruptsignal(int signum) {
    endwin();
    cerr << endl << RED "Keyboard interrupt dectected, exiting with code " << signum << ".";

    // cleanup and close up stuff here  
    // terminate program  

    exit(signum);
}

void programtermsignal(int signum) {
    endwin();
    cerr << endl << RED "Program either did an illegal instruction or Another program sent a termination request to this program, exiting with code " << signum << ".";

    exit(signum);
}

void termexitsignal(int signum)
{
    endwin();
    cerr << endl << RED "Either the program hung up or the controlling terminal got terminated";
    exit(signum);
}

static void show_usage(string name)
{
    std::cout << "Usage: " << name << " <option(s)> SOURCES\n"
        << "Options:\n"
        << "\t-h,--help, /H, /HLP\t\tShow this help message\n"
        << "\t-ns, --NOSTAT, /NS\t\tNo stat writting prompt\n"
        << "\t-nl, --NOLOG, --NOLOGGING, /NL\t\tNo logs written\n"
        << "\t-fn, --FILENAME, /FN\t\tThe name of the file, special usage: -(fn/--FILENAME) <name of the file>\n"
        << "\t-ln, --LOGNAME, /LN\t\tThe name of log file, special usage: like -fn but replace (-fn/--FILENAME) with (-ln/--LOGNAME)\n"
        << "\t-nm, --NOMUSIX, --NOMUSIC, /NM\t\tDisable music\n"
        << "\t-cs, --CLEARSCREEN, --CLS, --CLEAR, /CLS, /CS, /CLEAR\t\tClear the screen as the game start\n"
        << "\tVisit https://github.com/MXP2095onetechguy/Xombies-and-Nambaz for the code\n"
        << "\tVisit https://github.com/MXP2095onetechguy/Xombies-and-Nambaz/wiki wiki for the documentation\n"
        << endl;
}

string whatisthetimeanddate()
{

    auto givemetime = system_clock::to_time_t(system_clock::now());


    string time = ctime(&givemetime);

    return time;
}


/**
 * @brief make square beeps 
*/
void BEL()
{
    beep(1000, 100);
}

/**
 * @brief make noise beeps
*/
void DET()
{
    beep(500, 55);
}

/**
 *  @brief play music.
 * 
 *  @details this is transplanted and plays music on a separate thread.
 * 
 *  @param future stop upon promise is set into value
 * 
 *  @warning this must be joined when exiting if compiled with msvc or else a popup will appear that this thread has called abort
*/ 
int music(std::future<void> future)
{
    // not the best way to generate music, but it works although it is hacky and tacky
    // this is blocking, multithreading works as non blocking
    while (/*musix == true*/ future.wait_for(chrono::milliseconds(1)) == future_status::timeout)
    {
        beep(500, 500);
        beep(575, 250);
        beep(525, 250);
        /*
        if (musix == false)
        {
            return 0;
        }
        */
        beep(500, 750);
        beep(400, 750);
        beep(500, 500);
        sleep_for(milliseconds(1000));
        printw('\a');
        /*
        if (musix == false)
        {
            return 0;
        }
        */
        sleep_for(milliseconds(1500));
        /*
        if (musix == false)
        {
            return 0;
        }
        */
    }
    return 0;
}

/**
 * @brief stopwatch thread
 * 
 * @details stopwatch thread for the game to check how much has it ben played, run with thread for non blocking
 * 
 * @param future stop upon promise is set into value
 * 
 * @warning this must be joined when exiting if compiled with msvc or else a popup will appear that this thread has called abort
 */ 
int durationtimer(std::future<void> future)
{
    while(future.wait_for(chrono::milliseconds(1)) == future_status::timeout)
    {
        zeconds += 1;
        sleep_for(seconds(1));
    }
    return 0;
}


string getstring()
{
    std::string input;

    // let the terminal do the line editing
    nocbreak();
    echo();

    // this reads from buffer after <ENTER>, not "raw" 
    // so any backspacing etc. has already been taken care of
    int ch = getch();

    while ( ch != '\n' )
    {
        input.push_back( ch );
        ch = getch();
    }

    // restore your cbreak / echo settings here

    return input;
}



/** 
 * @brief main boi
 * 
 * @details this is the main entry point for the program as specified in the source as the main boi 
 * 
 */
int main(int argc, char* argv[]){



    // check if command preprocessor exist
    if(commandprocessorstatus())
    {

    }
    else{
        cout << RED "NO COMMAND PROCESSSOR??? BAD BOY. NO EXIST";
        return EXIT_FAILURE;
    }


    /* initialize the (pd/n)curses */ initscr(); echo();

    // check if color exist
    if(has_colors() == true)
    {
        start_color();
    }
    else{
        printw("YOU TERMINaL, NO COLOR == BAD");
        endwin();
        return EXIT_FAILURE;
    }

    int zombiecount = 0;
    int tries = maxtries;
    int pskill = 68;
    int zskill = randint(68, 70);
    int mynumber;
    int max = 20;
    int min = 0;
    int DED = 0;
    int myguess = 0;
    int zombiekilled = 0;
    int score = 0;
    string attack[6] = { "SWOSH", "POW", "PEW", "CLANG", "CLASH", "BANG" };
    int attacklen = sizeof(attack) / sizeof(attack[0]);
    string choice = "";
    bool quit = false;


    BEL();

    signal(SIGABRT, keyboardinterruptsignal);
    signal(SIGINT, keyboardinterruptsignal);
    signal(SIGILL, programtermsignal);
    signal(SIGTERM, programtermsignal);


    if (argc < 2)
    {

    }
    else {
        std::vector <std::string> sources;
        std::string destination;
        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];
            int nexti = (i + 1);
            if ((arg == "-h") || (arg == "--help") || (arg == "/H") || (arg == "/HLP")) {
                endwin();
                show_usage(argv[0]);
                return EXIT_SUCCESS;
            }
            else if ((arg == "-ns") || (arg == "--NOSTAT") || (arg == "/NS"))
            {
                showstat = false;
            }
            else if((arg == "-fn") || (arg == "--FILENAME") || (arg == "/FN"))
            {
                string clifilename = argv[nexti];
                if(clifilename.empty())
                {
                    endwin();
                    cout << RED "Filename expected after -fn, --FILENAME or /FN";
                    return EXIT_FAILURE;
                }
                else{
                    filename = clifilename;
                }
            }
            else if((arg == "-nm") || (arg == "--NOMUSIX") || (arg == "--NOMUSIC") || (arg == "/NM"))
            {
                hushmusic = true;
            }
            else if((arg == "-nl") || (arg == "--NOLOG") || (arg == "--NOLOGGING") || (arg == "/NL"))
            {
                nolog = true;
            }
            else if((arg == "-ln") || (arg == "--LOGNAME") || (arg == "/LN"))
            {
                string clilogname = argv[nexti];
                if(clilogname.empty())
                {
                    endwin();
                    cout << RED "Filename expected after -ln, --LOGNAME /LN";
                    return EXIT_FAILURE;
                }
                else{
                    logname = clilogname;
                }
            }
            else if((arg == "-cs") || (arg == "--CLEARSCREEN") || (arg == "--CLS") || (arg == "--CLEAR") || (arg == "/CS") || (arg == "/CLS") || (arg == "/CLEAR"))
            {
                wclear(stdscr);
            }
            else if((arg == "-ld") || (arg == "--DESKTOPLOG") || (arg == "/DL"))
            {

            }
            else if((arg == "-fd") || (arg == "--DESKTOPFILE") || (arg == "/DF"))
            {

            }
            else {
                sources.push_back(argv[i]);
            }
        }
    }

    const char* constlogname = logname.c_str();

    thread musixThread(music, std::move(futura));
    thread timeThread(durationtimer, std::move(futura2));

    /* init color */ start_color();
    /* bad color */ init_pair(1, COLOR_RED, COLOR_BLACK);
    /* good color */ init_pair(2, COLOR_GREEN, COLOR_BLACK);
    /* boring color */ init_pair(3, COLOR_WHITE, COLOR_BLACK);

    if(nolog == false)
    {
        plog::init(plog::verbose, constlogname);
    }

    if(hushmusic == true)
    {
        signal_exit_musix_thread.set_value(); //set value into promise
        musixThread.join();
    }

    printw('\033]2;' + title.c_str() + '\007');
    printw('Welcome to ' + title.c_str() + '\n' + 'Press enter to get started. Type [EXIT or exit] to exit,' + '\n' + 'maybe do a keyboard interrupt anytime you want to also exit' + '\n');
    wrefresh(stdscr);
    // setcolor("0A");
    string shouldiexit = "";
    shouldiexit = getstring();
    if(shouldiexit == "exit" || shouldiexit == "EXIT"){
        return EXIT_SUCCESS;
    }

    printw("What is your name?\n");
    wrefresh(stdscr);
    name = getstring();
    if(name.empty())
    {
        name = defname;
        if(nolog == false)
        {
            PLOG_WARNING << "No name entered.";
        }
    }
    else if(name == compname)
    {
        name = defname;
        printw(("This is you\n\n" + thisisyouimg + "\n").c_str());
    }

    if(name == "Andry Lie" || name == "andry lie" || name == "Andry lie" || name == "andry Lie")
    {
        cheatmode = true;
        printw("Cheat mode activated\n");
        PLOG_INFO << "cheater";
    }

    printw(( "Ok " + name + ", How many zombies do you want to fight?\n" ).c_str());

    while(true){
        buffer = getstring();
        try{
            if (buffer == compname) {
                throw ASRTBE;
            }
            zombiecount = stoi(buffer);
            if(cheatmode == true)
            {
                zombiecount += 100;
                pskill += 1000;
            }
            BEL();
            pskill *= zombiecount + randint(1, 10);
            zskill *= zombiecount + randint(1, 5);
            break;
        }
        catch(invalid_argument eia){
            printw("Give me only numbers\n");
            BEL();
        }
        catch(AbigailSaphiroRuntimeThiccBreastException artbe){
            BEL();
            printw(artbe.what());
            if(nolog == false)
            {
                PLOG_FATAL << "Trololololo, you should never put that.";
            }
            throw ASRTBE;
            return EXIT_FAILURE;
        }
        catch(...){

        }
    }
    printw("You fight by guessing numbers to train yourself and increase your skill!\nIf you guess corectly and you killed the zombie, you win and get to live another day and fight again with another zombie!\nYou lose and you are DED, no more fighting.\nYou lose by running out of tries in the guessing game or losing to a zombie with a higher skill level.\nYou win by killinng the zombie and you can increase the change if winning by guessing correctly with as little mistake as possible.\nYour score and skill is multiplied depending on how much zombies you want to fight\n");
    *blank = getstring();
    BEL();

    printw(strcat(strcat(string("Fight Fight Fight ").c_str(), name.c_str()), "!\n\n"));
    sleep_for(seconds(2));
    BEL();

    while(DED == 0)
    {
        mynumber = randint(min, max);
        printw(strcat(strcat(strcat(strcat(string("My number is between ").c_str(), inttochar(min)), " and "),  inttochar(max)), "\n"));
        while(true)
        {
            printw(strcat(string("You have ").c_str(),  strcat(inttochar(tries), " tries\n")));
            if (tries < 1)
            {
                DED = 1;
                break;
            }
            if (tries == 1) {
                printw("This is your last chance!\n");
            }
            buffer = getstring();
            try {
                myguess = stoi(buffer);
                if (tries < 1)
                {
                    DED = 1;
                    break;
                }
                if (tries < 1)
                {
                    DED = 1;
                    break;
                }
                else {
                    if(tries < 1)
                    {
                        DED = 1;
                        break;
                    }
                    if (myguess < mynumber)
                    {
                        printw("Too low.\n");
                        BEL();
                        zskill += 1;
                        pskill -= 2;
                        if (tries < 1)
                        {
                            DED = 1;
                            break;
                        }
                    }
                    else if (myguess > mynumber)
                    {
                        printw("Too high.\n");
                        BEL();
                        zskill += randint(1, 2);
                        pskill -= 1;
                        if (tries < 1)
                        {
                            DED = 1;
                            break;
                        }
                    }
                    else {
                        printw("Good.\n");
                        BEL();
                        pskill = pskill + (randint(1, 5) * (randint(2, 4) * 2));
                        zskill -= (randint(1, 5) * 2);
                        break;
                        
                    }

                    if (tries < 1)
                    {
                        DED = 1;
                        break;
                    }

                    
                    tries -= 1;
                }
            }
            catch(AbigailSaphiroRuntimeThiccBreastException artbe)
            {
                throw ASRTBE;
            }
            catch(invalid_argument eia){
                printw("Give me only numbers\n");
                BEL();
            }
            catch(exception e)
            {
                printw("exception.\n");
            }
            catch(...)
            {
                printw("Exception dectected, input again\n");
            }
            if (tries < 1)
            {
                DED = 1;
                break;
            }
        }

        if (DED != 0)
        {
            break;
        }

        printw("\n");

        if (zskill > 10) {
            printw("\nHere comes some strong boy zombie!\n");
        }
        else if (zskill > 1) {
            printw("\nHere comes some zombie!\n");
        }
        else if (zskill == 1)
        {
            printw("\nYou got some weak zombie!\n");
        }
        else {
            printw("\nYou got a Whatter zombie!\n");
        }

        BEL();

        sleep_for(seconds(2));

        printw("\n");

        int bonus = randint(1, 50);
        if(bonus == 1)
        {
            printw("You have a chance for bonus skill level, would you like it? 1 for yes, other for no\n");
            try{
                int answer = 0;
                buffer = getstring();
                answer = stoi(buffer);
                if(answer == 1)
                {
                    int addition = randint(1, 5);
                    pskill += addition;
                    printw(strcat(string("You have ").c_str(), strcat(inttochar(addition), strcat(string(" levels added to your skill level, now your skill level is at ").c_str(), pskill))));
                }
                else{
                    printw("alright, this is rare\n");
                }
            }
            catch(invalid_argument eia)
            {
                printw("alright, this is rare\n");
            }
            catch(exception e)
            {
                printw("alright, this is rare\n");
            }
            catch(...){
                printw("alright, this is rare\n");
            }
        }

        printw("\n");

        int zheartattack = randint(1, 45);
        if(zheartattack != 1)
        {
            for (int i = 0; i < 5; i++) {
                string effect = attack[randint(0, (attacklen - 1))];
                printw(strcat(string("Fighting with ").c_str(), strcat(effect.c_str(), "...\n")));
                DET();
                sleep_for(seconds(1));
            }

            if (pskill < zskill && cheatmode == false)
            {
                DED = 2;
            }
            else {
                if ((pskill - zskill) > 7) {
                    printw("Zombie is wasted.\n");
                    BEL();
                    pskill++;
                    score++;
                    zombiekilled++;
                }
                else if ((pskill - zskill) > 5) {
                    printw("That must have hurt!\n");
                    BEL();
                    pskill += 2;
                    score += 2;
                    zombiekilled++;
                }
                else if ((pskill - zskill) > 0) {
                    printw("You killed the zombie!\n");
                    BEL();
                    pskill = pskill * zombiecount;
                    score = score * zombiecount;
                    zombiekilled++;
                }
                else if(cheatmode == false && (pskill - zskill) > 0) {
                    printw("You killed the zombie, but suffered injuries, no skill level for you then. So sad.\n");
                    BEL();
                }
                else{
                    printw("You killed the zombie, What. No skill level for you then.\n");
                    BEL();
                }
            }
        }
        else{
            printw("The zombie just died of a sudden heart attack, stealing your skill level.\n");
        }



        if (DED != 0)
        {
            break;
        }

        printw(strcat(string("\nYou went home, ").c_str(), strcat(name.c_str(), string(", but do you want to fight again, or end it.\n").c_str())));

        while (true)
        {
            printw(strcat(string("Here is your stats so far,  score: ").c_str(), strcat(inttochar(score) , strcat(string(", zombie army killed : ").c_str(), strcat(inttochar(zombiekilled), strcat(string(", zombie count: ").c_str(), strcat(inttochar(zombiecount), ".\n")))))));
            printw("end for ending the game. \n");
            printw("fight for fighting again. \n");
            choice = getstring();
            if (choice == "end")
            {
                quit = true;
                BEL();
                int troll = randint(1, 43);
                if(troll == 1 && cheatmode != true)
                {
                    DED = 2;
                }
                break;
            }
            else if (choice == "fight")
            {
                tries = maxtries;
                BEL();
                break;
            }
            else {
                printw("Say what?\n");
                BEL();
            }

        }

        if (DED != 0)
        {
            break;
        }

        if (quit == true)
        {
            printw("\n");
            break;
        }

        int plane = randint(1, 3);
        if(plane == 1)
        {
            printw("At this moment, an airplane full of bricks always fly by your path. \n\n");
            int bricked = randint(1, 100);
            {
                if(bricked < 3)
                {   
                    printw("One of the bricks fall out and hit your hed, you are DED as a doornail.\n");
                    DED = 3;
                }
            }
        }
    }

    // transplant and modified
    if (DED == 0)
    {
        printw(strcat(string("\nYou survived, ").c_str(), strcat(name.c_str(), "! ")));
        BEL();
    }
    else if (DED == 1) {
        printw(strcat(string("\n").c_str(), strcat(name.c_str(), ", you R DED from the guessing part. ")));
        DET();
    }
    else if (DED == 2)
    {
        printw(strcat(string("\n").c_str(), strcat(name.c_str(), ", you R DED from the zombies. ")));
        DET();
    }
    else if (DED == 3)
    {
        printw(strcat(string("\n").c_str(), strcat(name.c_str(), ", you are DED as a doornail because the brick that fell out of a cargo plane hit your head.")));
    }

    signal_exit_time_thread.set_value();
    timeThread.join();
    *blank = getstring();
    BEL();

    // transplanted code
    printw(strcat(string("\nFinal Stats played at ").c_str(), strcat(whatisthetimeanddate().c_str(), string("\n").c_str())));
    printw(strcat(string("Player Name:").c_str(), strcat(name.c_str(), string("\n").c_str())));
    printw(strcat(string("Final score: ").c_str(), strcat(inttochar(score), string("\n").c_str())));
    printw(strcat(string("Final amout of zombies killed: ").c_str(), strcat(inttochar(zombiekilled), string("\n").c_str())));
    printw(strcat(string("Final skill level: ").c_str(), strcat(inttochar(pskill), string("\n").c_str())));
    printw(strcat(string("Final zombie count: ").c_str(), strcat(inttochar(zombiecount), string("\n").c_str())));
    printw(strcat(string("Duration for playing in seconds: ").c_str(), strcat(inttochar(zeconds), string("\n").c_str())));
    *blank = getstring();
    BEL();

    if(hushmusic == false)
    {
        signal_exit_musix_thread.set_value(); //set value into promise
    }

    musixThread.join();
    printw("\n");

    while (true)
    {
        if (!showstat)
        {
            break;
        }
        string confirm = "";

        printw("Would you like your Final Stats be written to a file?\nYes for writing, No for not writting. \n");
        confirm = getstring();

        if (confirm == "yes")
        {
            std::ifstream ifile(filename);

            if (ifile)
            {
                printw(strcat(string("\nAre you sure, you want to do this, the same file, ").c_str(), strcat(filename.c_str(), string(" already exist, This action will overwrite the file.  Yes for confirm overwritting, No or other for cancel\n").c_str())));
                string res = "";
                res = getstring();
                if (res == "yes")
                {

                }
                else {
                    printw("OK then\n");
                    break;
                }
            }
            else {
                printw(strcat(string("\nSeems safe, I don't see any file named ").c_str(), strcat(filename.c_str(), string(", But do you want to stay safe than sorry? Yes for sorry, but proud, or (either you choose no or other) for the safe. \n").c_str())));
                string res = "";
                res = getstring();
                if (res == "yes")
                {

                }
                else {
                    printw("OK then\n");
                    break;
                }
            }

            ifile.close();


            std::ofstream FinalFile;
            FinalFile.open(filename, std::ofstream::out | std::ofstream::trunc);
            string endstatus = "";

            printw("\nWritting to file, please don't close the game.\n");

            if(DED == 3)
            {
                endstatus = "DED as a doornail because a brick fell on head";
            }
            else if (DED == 2)
            {
                endstatus = "DEDed by zombies.";
            }
            else if (DED == 1)
            {
                endstatus = "DEDed for running out of tries when guessing. WHAT!";
            }
            else if (DED == 0)
            {
                endstatus = "Alive and Fine";
            }
            else {
                endstatus = "Unknown";
            }

            if (FinalFile.is_open() != 1)
            {
                // cout << FinalFile.is_open();
                cerr << RED "Unknown file openning error occured";
                if(nolog == false)
                {
                    PLOG_ERROR << "File error, the code is " << FinalFile.is_open();
                }
                break;
            }


            FinalFile << "Final Stats played at " << whatisthetimeanddate() << endl;
            FinalFile << "=========================================" << endl;
            FinalFile << "Player Name: " << name << endl;
            FinalFile << "Status: " << endstatus << endl;
            FinalFile << "In cheat mode: " << cheatmode << endl;
            FinalFile << "Final score: " << score << endl;
            FinalFile << "Final amout of zombies killed: " << zombiekilled << endl;
            FinalFile << "Final skill level of player: " << pskill << endl;
            FinalFile << "Final skill level of zombie: " << zskill << endl;
            FinalFile << "Final zombie count: " << zombiecount << endl;
            FinalFile << "Duration for playing in seconds: " << zeconds << endl;

            printw("File writting is done");


            FinalFile.close();
            break;
        }
        else if (confirm == "no")
        {
            printw("\nNo file writting is done\n");
            break;
        }
        else {
            printw("\nSay what?\n");
        }


    }
    delete blank;
    BEL();
    printw("\nYou can safely exit the game. \n");
    BEL();
    pausecli();
    BEL();

    endwin();

    return EXIT_SUCCESS;
}