#include "Randomizer.h"
#include <string>
#include <unordered_set>

using std::string;
using std::to_string;
using std::pair;
using std::unordered_set;

string Randomizer::toString(short a) {
    string p;
    if (a == a % 10) p = "0" + to_string(a);
    else p = to_string(a);
    return p;
}




unsigned char Randomizer::randomForMistakes(char soft){
    char c;
    if(soft==1){
        c=rand()%5;
        if(c==1) c = 8;
        if(c==0) c = 5;
    } else {
        c = rand()%7;
        if(c==1) c=7;
        if(c==6) c=8;
        if(c==0) c=11;
    }
    return c;
}

int Randomizer::randInPool(int b, int e) {
    if (e < b) return 0;
    if (e == b) return b;
    return b + (rand() % (e - b + 1));
}


bool Randomizer::generatePerc(short a) {
	if (a > 99) return true;
	if (a < 1) return false;
    return (randInPool(1, 100)<a);
}




string Randomizer::timeGenerator(bool dinner) {
    short m = randInPool(0, 59);
    short h;
    if (dinner) h = 14;
    else do h = randInPool(9, 18);
    while (h == 14);
    string p = toString(h);
    p += ':';
    p += toString(m);
    return p;
}


string Randomizer::generateDocumentNumber(){
    string p = to_string(rand()%10);
    for(int i=0;i<9;i++)
        p+=to_string(rand()%10);
    return p;
}




char Randomizer::stampDegenerator(char a){
    if(rand()%4)
        return -a;
    if(56%a==0){
        return ((rand()%2+5)*(-1+rand()%2*2));
    }
    unordered_set<char> variants {-8,-7,-6,-5,5,6,7,8};
    variants.erase(variants.find(a));
    variants.erase(variants.find(-a));
    return Randomizer::randOfSet<char>(variants);


    /*
    if(a==5)
        return ((rand()%3+6)*(-1+rand()%2*2));
    if(56%a==0)
        return ((rand()%2+5)*(-1+rand()%2*2));
    if(a==6){
        return (a=(-1+rand()%2*2)*(rand()%3+6))-(a==6)+(a==-6);
    }
    */
}
