#include "Generators\DateGenerator.h"
#include "Generators\Randomizer.h"
#include <string>

using std::to_string;




DateGenerator::DateGenerator()
{
}

DateGenerator::DateGenerator(short p1, short p2, short p3)
{
    d=p1;
    m=p2;
    y=p3;
}


short DateGenerator::getDays(short i){
    if(i==4 || i==6 || i==9 || i==11) return 30;
    if(i==2) return 28;
    return 31;
}


void DateGenerator::generateDay(char a){
    d=0;
    if(a==2) {
        d=((y%4)==0);
        d=(short)Randomizer::randInPool(1,28+d);
    }
    if(a==4 || a==6 || a==9 || a==11) d=(short)Randomizer::randInPool(1,30);
    if(a==13) generateDay((char)m);
    if(d==0) a=0;
    if(a==0) d=(short)Randomizer::randInPool(1,31);
}


void DateGenerator::generateMonth(){
    m=(short)Randomizer::randInPool(1,12);
}

void DateGenerator::generateYear(char a){
    if(a==0) y=(short)Randomizer::randInPool(1970, 2019);
}


void DateGenerator::regenerate(){
    generateYear(0);
    generateMonth();
    generateDay(13);

}


DateGenerator DateGenerator::d_today(){
    DateGenerator a(31,5,2019);
    return a;
}

/*
string DateGenerator::toString(short a) {
    string p;
    if (a == a % 10) p = "0" + to_string(a);
    else p = to_string(a);
    return p;
}
*/

string DateGenerator::toString(){
    return Randomizer::toString(d)+'.'+Randomizer::toString(m)+'.'+to_string(y);
}


void DateGenerator::generateBad(){
    generateYear(0);
    m = 2;
    d = 31;
    short r;
    if (y % 4 != 0) r = (short)Randomizer::randInPool(-2, 4);
    else r = (short)Randomizer::randInPool(-1, 4);
    if (r < 1) d += r;
    if (r >= 1) m += r + r;
    if (r >= 3) m += 1;
}

bool operator<(const DateGenerator &l,const DateGenerator &r){
    if(l.y<r.y) return true;
    if(l.m<r.m) return true;
    if(l.d<r.d) return true;
    return false;
}

int operator-(const DateGenerator &ll,const DateGenerator &rr){
    int days=0;
    DateGenerator l=ll;
    DateGenerator r=rr;
    if(l<r) std::swap(l,r);
    for(short i=1; i!=l.m;i++)
        days+=DateGenerator::getDays(i);
    if(l.m>2 || (l.m==2 && l.d==29)) days+=1;
    days+=l.d;

    for(short i=r.m; i!=12;i++)
        days+=DateGenerator::getDays(i);
    if(r.m<2 || (l.m==2 && l.d!=29)) days+=1;
    days+=31-r.d;

    for(short i=r.y+1; i<l.y; i++)
        days+=365+(i%4!=0);
    if(ll<rr) days*=-1;
    return days;
}


DateGenerator operator-(const DateGenerator &ll,const int &rr){
    DateGenerator p=ll;
    if(rr<1 || rr>31) return p;
    p.d-=rr;
    if(p.d<1){
        p.m--;
        if(p.m==0){
            p.m=12;
            p.y--;
        } else{
            if(p.m==2 && p.y%4==0) p.d++;
        }
        p.d+=DateGenerator::getDays(p.m);
    }
    return p;
}



DateGenerator operator<<(const DateGenerator &l,const DateGenerator &r){
    DateGenerator a;
    if(r-l<5) return a;
    do
      a.regenerate();
    while(!(l<a && a<r));
    return a;
}


DateGenerator operator>>(const DateGenerator &l,const DateGenerator &r){
    DateGenerator a;
    do
      a.regenerate();
    while(l<a && a<r);
    return a;
}



DateGenerator DateGenerator::operator[](short a){
    DateGenerator p = *this;
    if(a==1){
        p=p-31;
        return p<<*this;
    }
    if(a==-1){
        p=p-31;
        return p>>*this;
    }
    if(a==14){
        p.y=p.y+14;
        return p<<*this;
    }
    if(a==-14){
        p.y=p.y+14;
        return p>>*this;
    }
    return p;
}

string DateGenerator::birthDate(){
    DateGenerator p;
    do
        p.regenerate();
    while(p.y>2000);
    return p.toString();
}
