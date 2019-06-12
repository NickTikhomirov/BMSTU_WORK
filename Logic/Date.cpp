#include "Date.h"

Date::Date()
{

}

Date::Date(int a, int b, int c){
    day = a;
    month = b;
    year = c;
}


string Date::toString(){
    return Randomizer::toString(day)+'.'+Randomizer::toString(month)+'.'+to_string(year);
}

bool Date::longMonth(int p){
    if(p==1||p==3||p==5||p==7||p==8||p==10||p==12) return true;
    return false;
}



// Унарный+    - увеличение даты на месяц
// Унарный-    - уменьшние даты на месяц
// ++слева     - генерация новой правильной даты, которая идёт до текущей
// справа++    - генерация новой правильной даты, которая идёт после текущей
// --слева     - генерация новой неправильной (по день-месяц) даты, которая идёт до текущей
// дата^логич  - рандомное заполнение поля день (верно или не верно)


// > и <          - больше и меньше, тут без подвоха
// число<<=дата   - сдвиг даты ровно на число лет в прошлое
// дата>>=число   - сдвиг даты ровно на число лет в будущее

// дата<<дата     - генерит новую дату между двух данных
// дата|=дата     - от левой даты до "за месяц до правой даты"
// ~унарная       - не раньше, чем за месяц до




void Date::operator+(){
    month++;
    if(month==13){
        month=1;
        year++;
    }
}

void Date::operator-(){
    month--;
    if(month==0){
        month=12;
        year--;
    }
}

bool operator<(const Date &l, const Date &r){
    if(l.year==r.year){
        if(l.month==r.month){
            return (l.day<r.day);
        } else return (l.month<r.month);
    } else return (l.year<r.year);
}

bool operator>(const Date &l, const Date &r){
    if(l.year==r.year){
        if(l.month==r.month){
            return (l.day>r.day);
        } else return (l.month>r.month);
    } else return (l.year>r.year);
}


void operator^(Date &l,bool r){
    if(r){
        if(l.month==4||l.month==6||l.month==9||l.month==11) l.day=Randomizer::randInPool(1,30);
        else if(l.month==2){
            if(l.year%4==0) l.day=Randomizer::randInPool(1,29);
            else l.day=Randomizer::randInPool(1,28);
        } else l.day=Randomizer::randInPool(1,31);
    } else {
        l.day=31;
        if(l.month==2){
            l.day-=(rand()%(2+l.year%4!=0));
        }
    }
}



Date operator<<=(int a, const Date &r){
    Date b = r;
    b.year-=a;
    return b;
}

Date operator>>=(const Date &l,int a){
    Date b = l;
    b.year+=a;
    return b;
}


void Date::operator++(){
    Date a;
    do{
        a.year = Randomizer::randInPool(1970,year);
        a.month = Randomizer::randInPool(1,12);
        a^true;
    } while(!(a<*this));
    this->year=a.year;
    this->month=a.month;
    this->day=a.day;
}

void Date::operator++(int){
    Date a;
    Date t(31,5,2019);
    do{
        a.year = Randomizer::randInPool(year,2019);
        a.month = Randomizer::randInPool(1,12);
        a^true;
    } while(!(a>*this) || !(a<t));
    this->year=a.year;
    this->month=a.month;
    this->day=a.day;
}


void Date::operator--(){
    Date a=*this;
    do -a;
    while(longMonth(a.month));
    a^false;
    this->year=a.year;
    this->month=a.month;
    this->day=a.day;
}



Date operator<<(Date l, Date r){
    Date a;
    if(!(l<r)) return a;
    do{
       a.year=Randomizer::randInPool(l.year,r.year);
       a.month=Randomizer::randInPool(1,12);
       a^true;
    }while(!(l<a) || !(a<r));
    return a;
}


Date operator~(Date k){
    Date a;
    Date j=k;
    -j;
    a=j<<k;
    return a;
}

Date operator|=(const Date &l, const Date &r){
    Date b=r;
    -b;
    return l<<b;
}

string operator!(Date p){
    return p.toString();
}
