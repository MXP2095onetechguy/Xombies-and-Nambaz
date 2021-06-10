/*
* Copyright [yyyy] [name of copyright owner]
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

#include <iostream>
#include <string.h>
#include <exception>
#include <thread>
#include <fstream>
#include <chrono>
#include <future>
#include <vector>
#include <csignal>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/generator_iterator.hpp>
#include <boost/random.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#include "doot.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
using namespace boost::multiprecision;
using namespace boost::random;

typedef independent_bits_engine<mt19937, 256, cpp_int> generator_type;
generator_type gen(time(NULL));

string* blank = new string("");
string buffer = "";
string title = "Xombies and Nambaz";
bool showstat = true;
string name = "Abigail";


// class

class AbigailSaphiroRuntimeThiccBreastException : public exception {
public:
    const char* what() const throw()
    {
        return "What, EXCEPTION because Abigail Saphiro's breast are to fat and your t-strap high heel shoes bow tie is falling off, also your t-strap is torn on your t-strap high heel shoe and also the fact that you are sexy and better destory those flats and high heel and tear the straps on the flats and the high heel and now your bow tie on your t - strap high heel shoes bow tie has fallen off, and they smell horrible as Abigail Spahiro's breast scent and her feet scent combined, P-U, however Abigail Saphiro's feet should be licked by a goat and you better make her breast thicc!";
    }
};

AbigailSaphiroRuntimeThiccBreastException ASRTBE;


// functions

int randint(int min, int max) { // new randomizer
    boost::random::uniform_int_distribution<> dist(min, max);
    int res = dist(gen);
    return res;
}

void keyboardinterruptsignal(int signum) {
    cout << endl << "Keyboard interrupt dectected, exiting with code " << signum << ".";

    // cleanup and close up stuff here  
    // terminate program  

    exit(signum);
}

void programtermsignal(int signum) {
    cout << endl << "Program either did an illegal instruction or Another program sent a termination request to this program, exiting with code " << signum << ".";

    exit(signum);
}

static void show_usage(string name)
{
    std::cout << "Usage: " << name << " <option(s)> SOURCES\n"
        << "Options:\n"
        << "\t-h,--help\t\tShow this help message\n"
        << "\t-ns, --NOSTAT\t\tNo stat writting prompt\n"
        << std::endl;
}

void BEL()
{
    beep(1000, 100);
}

void DET()
{
    beep(500, 55);
}


// main boi
int main(int argc, char* argv[]){

    int zombiecount = 0;
    string attack[6] = { "SWOSH", "POW", "PEW", "CLANG", "CLASH", "BANG" };
    string choice = "";


    BEL();
    signal(SIGABRT, keyboardinterruptsignal);
    signal(SIGINT, keyboardinterruptsignal);
    signal(SIGILL, programtermsignal);
    signal(SIGTERM, programtermsignal);

#ifdef _WIN32
    system("color 02");
#endif

    if (argc < 2)
    {

    }
    else {
        std::vector <std::string> sources;
        std::string destination;
        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];
            if ((arg == "-h") || (arg == "--help")) {
                show_usage(argv[0]);
                return 0;
            }
            else if ((arg == "-ns") || (arg == "--NOSTAT"))
            {
                showstat = false;
            }
            else {
                sources.push_back(argv[i]);
            }
        }
    }



    cout << "\033]2;" << title << "\007" << "Welcome to " << title << endl << "Press enter to get started. Type [EXIT or exit] to exit," << endl << "maybe do a keyboard interrupt anytime you want to also exit";
    string shouldiexit = "";
    getline(cin, shouldiexit);
    shouldiexit = *blank;
    if(shouldiexit == "exit" || shouldiexit == "EXIT"){
        return 0;
    }

    cout << "What is your name?" << endl;
    getline(cin, name);

    cout<< "Ok " << name << ", How many zombies do you want to fight?" << endl;

    while(true){
        cin >> buffer;
        try{
            if (buffer == "Abigail") {
                throw ASRTBE;
            }
            zombiecount = stoi(buffer);
            BEL();
            break;
        }
        catch(invalid_argument eia){
            cout << "Give me only numbers";
            BEL();
        }
        catch(AbigailSaphiroRuntimeThiccBreastException artbe){
            BEL();
            cout << artbe.what();
            throw ASRTBE;
            return 1;
        }
        catch(...){

        }
    }
    cout << endl << "You fight by guessing numbers to train yourself and increase your skill!" << endl << "If you guess corectly and you killed the zombie, you win and get to live another day and fight again with another zombie!" << endl << "You lose and you are DED, no more fighting." << endl << "You lose by running out of tries in the guessing game or losing to a zombie with a higher skill level." << endl << "You win by killinng the zombie and you can increase the change if winning by guessing correctly with as little mistake as possible." << endl << "Your score and skill is multiplied depending on how much zombies you want to fight" << endl;
    cin >> *blank;
    BEL();

    cout << "Fight Fight Fight " << name << "!";
    sleep_for(seconds(2));
    BEL();
    
    delete blank;

    return 0;
}