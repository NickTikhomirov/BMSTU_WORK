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


bool Randomizer::isDocumentCoding(char a) {
    return (a=='P'||a=='H'||a=='A'||a=='M'||a=='X'||a=='R');
}






char Randomizer::randomForMistakes(char soft){
    char c;
    if(soft==1){
        c=rand()%5;
        if(c==1) c = 8;
        if(c==0) c = 5;
    } else {
        c = rand()%8;
        if(c==1) c=-1;
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

string Randomizer::generateMistakes() {
	string p;
    if (generatePerc(30)) {
		p = "0";
		return p;
	}
    if (generatePerc(10)) {
        if(rand()%2) return "B";
          p="A";
          short i=(short)randInPool(1,9);
          if(i<5) p+='C';
          if(i==5) p+='0';
          if(i==6) p+='s';
          if(i==7 || i==8) p+=(rand()%2)?'N':'n';
          if(i==9) p+='D';

          if(rand()%2){
              if(i==2) p+='D';
              if(i==4) p+='s';
              if(i==8) p+='C';
          }
          return p;
	}
    short i=rand()%7;
    if(i<4) p+=(rand()%2)?'N':'n';
    if(i==4 || i==5) p+='D';
    if(i==6) p+='F';
    return p;
}


string Randomizer::generateDocumentNumber(){
    string p = to_string(rand()%10);
    for(int i=0;i<9;i++)
        p+=to_string(rand()%10);
    return p;
}

