#include "StampGenerator.h"

QPixmap StampGenerator::generate(char a, bool k){
    if(a=='X') a='M';
    char b;
    if(k) b=generate(a);
    else b=generate_not(a);
    return QPixmap(QString::fromStdString("://b//Pictures//buttons//id"+to_string(b)+".png"));
}

char StampGenerator::generate(char a){
    if(a=='M') return (7+rand()%2);
    if(a=='P') return 5;
    if(a=='R') return 6;
    return 0;
}

char StampGenerator::generate_not(char a){
    char b1,b2,r;
    if(a=='M'){
        b1=7;
        b2=8;
    }
    if(a=='P') b1=b2=5;
    if(a=='R') b1=b2=6;
    do r=generate();
    while(r==b1||r==b2);
    return r;
}

char StampGenerator::generate(){
    char p = rand()%4 +5;
    if(rand()%2) p=-p;
    return p;
}
