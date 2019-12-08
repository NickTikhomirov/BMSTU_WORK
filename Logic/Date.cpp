#include "Date.h"

Date::Date()
{
    day = 1;
    month = 11;
    year = 2000;
}


/*!
    Конструктор даты по трём тривиальным параметрам
    \param a День
    \param b Месяц
    \param c Год
*/
Date::Date(int a, int b, int c){
    day = a;
    month = b;
    year = c;
}


/*!
    Проверка числа 1-12 на то, соответствует ли оно номеру длинного месяца (31 день).
    \param p Месяц
*/
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



/*!
   Шаг даты вперёд на 1 месяц (меняет объект, не возвращает ничего)
*/
void Date::operator+(){
    month++;
    if(month==13){
        month=1;
        year++;
    }
}


/*!
   Шаг даты назад на 1 месяц (меняет объект, не возвращает ничего)
*/
void Date::operator-(){
    month--;
    if(month==0){
        month=12;
        year--;
    }
}

/*!
   Тривиальный метод сравнения дат по отношению порядка (l<r)
   \param l Дата, подозрительная на меньшую
   \param r Дата, подозрительная на большую
*/
bool operator<(const Date &l, const Date &r){
    if(l.year==r.year){
        if(l.month==r.month){
            return (l.day<r.day);
        } else return (l.month<r.month);
    } else return (l.year<r.year);
}

/*!
   Тривиальный метод сравнения дат по отношению порядка (l>r)
   \param l Дата, подозрительная на большую
   \param r Дата, подозрительная на меньшую
*/
bool operator>(const Date &l, const Date &r){
    if(l.year==r.year){
        if(l.month==r.month){
            return (l.day>r.day);
        } else return (l.month>r.month);
    } else return (l.year>r.year);
}


/*!
   Инициализация поля дня правильным или неправильным (определяется по значению второго аргумента) значением.
   Пример неправильного дня - 31 апреля, 30 февраля, 29 февраля в невисокосный год.
   Значения полей месяца и года не меняются и берутся за основу для генерации дня.
   Ничего не возвращает, просто меняет исходную дату.
   \param l Дата, для которой определяется значение дня
   \param r логическое значение, качественно характеризующее требуемый результат (правильный либо неправильный день).
*/
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


/*!
   Возвращает новую дату, полученную путём уменьшения года исходной даты на число.
   Проверка на ошибку високосности не осуществляется.
   \param a Число, на которое уменьшается значение года
   \param r Исходная дата (не изменяется)
*/
Date operator<<=(int a, const Date &r){
    Date b = r;
    b.year-=a;
    return b;
}

/*!
   Возвращает новую дату, полученную путём увеличения года исходной даты на число.
   Проверка на ошибку високосности не осуществляется.
   \param l Исходная дата (не изменяется)
   \param a Число, на которое увеличивается значение года
*/
Date operator>>=(const Date &l,int a){
    Date b = l;
    b.year+=a;
    return b;
}


/*!
   Подразумевается: инкремент слева (++a)
   Заменяет дату на другую случайную, которая корректна и обязательно меньше исходной, но не меньше 1.1.1970.
   Ничего не возвращает.
*/
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

/*!
   Подразумевается: инкремент справа (a++)
   Заменяет дату на другую случайную, которая корректна и обязательно больше исходной, но меньше 31.5.2019.
   Ничего не возвращает.
*/
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


/*!
   Подразумевается: декремент слева (--a)
   Заменяет дату на другую случайную, которая некорректна и обязательно меньше исходной.
   Ничего не возвращает.
*/
void Date::operator--(){
    Date a=*this;
    do -a;
    while(longMonth(a.month));
    a^false;
    this->year=a.year;
    this->month=a.month;
    this->day=a.day;
}


/*!
   Генерирует случайную дату между левой и правой. Требование: левая строго меньше правой.
   \param l Левая дата
   \param r Правая дата
*/
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

/*!
   Возвращает случайную дату, которая меньше исходной, но расстояние между ними меньше месяца. Исходная не изменяется.
   \param k Исходная дата
*/
Date operator~(Date k){
    Date a;
    Date j=k;
    -j;
    a=j<<k;
    return a;
}

/*!
   Возвращает случайную дату, которая меньше исходной, а расстояние между ними больше месяца. Исходная не изменяется.
   \param k Исходная дата
*/
Date operator|=(const Date &l, const Date &r){
    Date b=r;
    -b;
    return l<<b;
}

/*!
   Тривиальное преобразование к строковому типу.
*/
Date::operator string(){
    return Randomizer::toString(day)+'.'+Randomizer::toString(month)+'.'+to_string(year);
}
