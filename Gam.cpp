#include <iostream>
#include <string.h>
#include <exception>
#include <thread>
#include <fstream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/generator_iterator.hpp>
#include <boost/random.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#include "doot.h"

using namespace std;
using namespace boost::multiprecision;
using namespace boost::random;

typedef independent_bits_engine<mt19937, 256, cpp_int> generator_type;
generator_type gen(time(NULL));


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


// main boi
int main(int argc, char* argv[]){
    throw ASRTBE;
    return 0;
}