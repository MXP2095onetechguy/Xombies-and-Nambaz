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

/* install boost by dropping the boost library onto the include folder in the c++ include folder of g++ */

// some of these code is original, while some are transplanted from my msvc code, and maybe the transplanted code is modified


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
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/generator_iterator.hpp>
#include <boost/random.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#include "doot.h"
#include "term.hpp"
#include "color.hpp"
#include "MXPFunc.hpp"

#define GRN "\e[0;32m"
#define RED "\e[0;31m"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
using namespace boost::multiprecision;
using namespace boost::random;

typedef independent_bits_engine<mt19937, 256, cpp_int> generator_type;
generator_type gen(time(NULL));

string getdesktop()
{
    string p = "";
    string pd = "";
#ifdef _WIN32
    p = getenv("USERPROFILE");
    pd = p + "\\desktop";
    return pd;
#elif defined(unix)
    p = getenv("HOME");
    pd = p + "/Desktop/example.txt";
    return pd;
#else
    return "error, unknown os";
#endif

}

string* blank = new string("");
string buffer = "";
string title = "Xombies and Nambaz";
bool showstat = true;
string defname = "Abigail";
string name = defname;
int maxtries = 8;
string desktop = getdesktop();
string filename = "Final-Stats.txt";
bool cheatmode = false;

promise<void> signal_exit_musix_thread; //create promise object
std::future<void> futura = signal_exit_musix_thread.get_future(); // create future objects


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
    cerr << endl << RED "Keyboard interrupt dectected, exiting with code " << signum << ".";

    // cleanup and close up stuff here  
    // terminate program  

    exit(signum);
}

void programtermsignal(int signum) {
    cerr << endl << RED "Program either did an illegal instruction or Another program sent a termination request to this program, exiting with code " << signum << ".";

    exit(signum);
}

void termexitsignal(int signum)
{
    cerr << endl << RED "Either the program hung up or the controlling terminal got terminated";
}

static void show_usage(string name)
{
    std::cout << "Usage: " << name << " <option(s)> SOURCES\n"
        << "Options:\n"
        << "\t-h,--help\t\tShow this help message\n"
        << "\t-ns, --NOSTAT\t\tNo stat writting prompt\n"
        << "\t-fn, --FILENAME\t\tThe name of the file\n"
        << endl;
}

string whatisthetimeanddate()
{

    auto givemetime = system_clock::to_time_t(system_clock::now());


    string time = ctime(&givemetime);

    return time;
}


void BEL()
{
    beep(1000, 100);
}

void DET()
{
    beep(500, 55);
}

// this is transplanted
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
        cout << '\a';
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


// main boi
int main(int argc, char* argv[]){

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
            if ((arg == "-h") || (arg == "--help")) {
                show_usage(argv[0]);
                return 0;
            }
            else if ((arg == "-ns") || (arg == "--NOSTAT"))
            {
                showstat = false;
            }
            else if((arg == "-fn") || (arg == "--FILENAME"))
            {
                string clifilename = argv[(i + 1)];
                if(clifilename.empty())
                {
                    cout << RED "Filename expected ar -fn or --FILENAME";
                    return 1;
                }
                else{
                    filename = clifilename;
                }
            }
            else {
                sources.push_back(argv[i]);
            }
        }
    }

    thread musixThread(music, std::move(futura));


#ifdef _WIN32
    system("color 02");
#endif

    cout << "\033]2;" << title << "\007" << GRN "Welcome to " << title << endl << "Press enter to get started. Type [EXIT or exit] to exit," << endl << "maybe do a keyboard interrupt anytime you want to also exit" << endl;
    string shouldiexit = "";
    getline(cin, shouldiexit);
    shouldiexit = *blank;
    if(shouldiexit == "exit" || shouldiexit == "EXIT"){
        return 0;
    }

    cout << "What is your name?" << endl;
    getline(cin, name);
    if(name.empty())
    {
        name = defname;
    }
    else if(name == defname)
    {
        name = defname;
    }

    if(name == "Andry Lie" || name == "andry lie" || name == "Andry lie" || name == "andry Lie")
    {
        cheatmode = true;
        cout << "Cheat mode activated" << endl;
    }

    cout<< "Ok " << name << ", How many zombies do you want to fight?" << endl;

    while(true){
        cin >> buffer;
        try{
            if (buffer == "Abigail") {
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
            cout << "Give me only numbers" << endl;
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

    cout << "Fight Fight Fight " << name << "!" << endl << endl;
    sleep_for(seconds(2));
    BEL();

    while(DED == 0)
    {
        mynumber = randint(min, max);
        cout << "My number is between " << min << " and " << max << endl;
        while(true)
        {
            cout << "You have " << tries << " tries" << endl;
            if (tries < 1)
            {
                DED = 1;
                break;
            }
            if (tries == 1) {
                cout << "This is your last chance!" << endl;
            }
            cin >> buffer;
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
                        cout << "Too low." << endl;
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
                        cout << "Too high." << endl;
                        BEL();
                        zskill += 2;
                        pskill / randint(1, 2);
                        if (tries < 1)
                        {
                            DED = 1;
                            break;
                        }
                    }
                    else {
                        cout << "Good." << endl;
                        BEL();
                        pskill = pskill * randint(2, 4);
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
                cout << "Give me only numbers" << endl;
                BEL();
            }
            catch(exception e)
            {
                cout << "exception." << endl;
            }
            catch(...)
            {
                cout << "Exception dectected, input again" << endl;
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

        cout << endl;

        if (zskill > 10) {
            cout << endl << "Here comes some strong boy zombie!" << endl;
        }
        else if (zskill > 1) {
            cout << endl << "Here comes some zombie!" << endl;
        }
        else if (zskill == 1)
        {
            cout << endl << "You got some weak zombie!" << endl;
        }
        else {
            cout << endl << "What zombie?" << endl;
        }

        BEL();

        sleep_for(seconds(2));

        cout << endl;

        int bonus = randint(1, 50);
        if(bonus == 1)
        {
            cout << "You have a chance for bonus skill level, would you like it? 1 for yes, other for no" << endl;
            try{
                int answer = 0;
                cin >> buffer;
                answer = stoi(buffer);
                if(answer == 1)
                {
                    int addition = randint(1, 5);
                    pskill += addition;
                    cout << "You have " << addition << " levels added to your skill level, now your skill level is at " << pskill;
                }
                else{
                    cout << "alright, this is rare";
                }
            }
            catch(invalid_argument eia)
            {
                cout << "alright, this is rare";
            }
            catch(exception e)
            {
                cout << "alright, this is rare";
            }
            catch(...){
                cout << "alright, this is rare";
            }
        }

        cout << endl;

        int zheartattack = randint(1, 45);
        if(zheartattack != 1)
        {
            for (int i = 0; i < 5; i++) {
                string effect = attack[randint(0, (attacklen - 1))];
                cout << "Fighting with " << effect << "..." << endl;
                DET();
                sleep_for(seconds(1));
            }

            if (pskill < zskill && cheatmode == false)
            {
                DED = 2;
            }
            else {
                if ((pskill - zskill) > 7) {
                    cout << "Zombie is wasted." << endl;
                    BEL();
                    pskill++;
                    score++;
                    zombiekilled++;
                }
                else if ((pskill - zskill) > 5) {
                    cout << "That must have hurt!" << endl;
                    BEL();
                    pskill += 2;
                    score += 2;
                    zombiekilled++;
                }
                else if ((pskill - zskill) > 0) {
                    cout << "You killed the zombie!" << endl;
                    BEL();
                    pskill = pskill * zombiecount;
                    score = score * zombiecount;
                    zombiekilled++;
                }
                else if(cheatmode == false && (pskill - zskill) > 0) {
                    cout << "You killed the zombie, but suffered injuries, no skill level for you then." << endl;
                    BEL();
                }
                else{
                    cout << "You killed the zombie, What. No skill level for you then." << endl;
                    BEL();
                }
            }
        }
        else{
            cout << "The zombie just died of a sudden heart attack, stealing your skill level." << endl;
        }



        if (DED != 0)
        {
            break;
        }

        cout << endl << "You went home, " << name << ", but do you want to fight again, or end it." << endl;

        while (true)
        {
            cout << "Here is your stats so far,  score: " << score << ", zombie army killed : " << zombiekilled << ", zombie count: " << zombiecount << "." << endl;
            cout << "end for ending the game. " << endl;
            cout << "fight for fighting again. " << endl;
            cin >> choice;
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
                cout << "Say what?" << endl;
                BEL();
            }

        }

        if (DED != 0)
        {
            break;
        }

        if (quit == true)
        {
            cout << endl;
            break;
        }
    }

    // transplant and modified
    if (DED == 0)
    {
        cout << endl << "You survived, " << name << "! ";
        BEL();
    }
    else if (DED == 1) {
        cout << endl << name << ", you R DED from the guessing part. ";
        DET();
    }
    else if (DED == 2)
    {
        cout << endl << name << ", you R DED from the zombies. ";
        DET();
    }

    cin >> *blank;
    BEL();

    // transplanted code
    cout << endl << "Final Stats played at " << whatisthetimeanddate() << endl;
    cout << "Player Name:" << name << endl;
    cout << "Final score: " << score << endl;
    cout << "Final amout of zombies killed: " << zombiekilled << endl;
    cout << "Final skill level: " << pskill << endl;
    cout << "Final zombie count: " << zombiecount << endl;
    cin >> *blank;
    BEL();


    signal_exit_musix_thread.set_value(); //set value into promise
    musixThread.join();
    cout << endl;

    while (true)
    {
        if (!showstat)
        {
            break;
        }
        string confirm = "";

        cout << "Would you like your Final Stats be written to a file?" << endl << "Yes for writing, No for not writting. " << endl;
        cin >> confirm;

        if (confirm == "yes")
        {
            std::ifstream ifile(filename);

            if (ifile)
            {
                cout << endl << "Are you sure, you want to do this, the same file, " << filename << " already exist, This action will overwrite the file.  Yes for confirm overwritting, No or other for cancel" << endl;
                string res = "";
                cin >> res;
                if (res == "yes")
                {

                }
                else {
                    cout << "OK then" << endl;
                    break;
                }
            }
            else {
                cout << endl << "Seems safe, I don't see any file named " << filename << ", But do you want to stay safe than sorry? Yes for sorry, but proud, or (either you choose no or other) for the safe." << endl;
                string res = "";
                cin >> res;
                if (res == "yes")
                {

                }
                else {
                    cout << "OK then" << endl;
                    break;
                }
            }


            std::ofstream FinalFile;
            FinalFile.open(filename, std::ofstream::out | std::ofstream::trunc);
            string endstatus = "";

            cout << endl << "Writting to file, please don't close the game." << endl;

            if (DED == 2)
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
                cout << "Unknown file openning error occured";
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

            cout << "File writting is done";


            FinalFile.close();
            break;
        }
        else if (confirm == "no")
        {
            cout << endl << "No file writting is done";
            break;
        }
        else {
            cout << endl << "Say what?" << endl;
        }


    }


    cout << endl << "You can safely exit the game. ";
    BEL();
    cin >> *blank;
    BEL();
    delete blank;
    BEL();

    return 0;
}