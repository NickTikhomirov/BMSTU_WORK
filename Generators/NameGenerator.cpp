#include "NameGenerator.h"
#include "Randomizer.h"
#include <unordered_set>
#include <unordered_map>


using std::unordered_set;
using std::unordered_map;



string NameGenerator::generateName() {
    short a = (short)Randomizer::randInPool(1, 10);
    static const unordered_map<short, string> values = {
        {1,"Evgeny"},
        {2,"Fedor"},
        {3,"John"},
        {4,"Sergey"},
        {5,"Konstantin"},
        {6,"Dmitri"},
        {7,"Bill"},
        {8,"Shirma"},
        {9,"Nikolai"},
        {10,"Boris"}
    };
    return values.at(a);
}

string NameGenerator::generateName2() {
    short a = (short)Randomizer::randInPool(1, 10);
    static const unordered_map<short, string> values = {
        {1,"Lisevsky"},
        {2,"Jurianov"},
        {3,"Bushuev"},
        {4,"Krivenya"},
        {5,"Selivanov"},
        {6,"Burdashev"},
        {7,"Kravchenko"},
        {8,"Dvinyatin"},
        {9,"Dudikov"},
        {10,"Nikitin"}
    };
    return values.at(a);
}



string NameGenerator::generateCountry(){
    switch(rand()%10){
    case 0: return "Россия";
    case 1: return "Великобритания";
    case 2: return "Гондурас";
    case 3: return "Италия";
    case 4: return "Словения";
    case 5: return "Германия";
    case 6: return "США";
    case 7: return "Китай";
    case 8: return "Австрия";
    case 9: return "Венгрия";
    }
    return "Зимбабве";
}

string NameGenerator::generateBadCountry(){
    switch(rand()%10){
    case 0: return "Югославия";
    case 1: return "СССР";
    case 2: return "Чехословакия";
    case 3: return "Пандария";
    case 4: return "Нарния";
    case 5: return "Сатурн";
    case 6: return "Биробиджан";
    case 7: return "Татарстан";
    case 8: return "Атлантида";
    case 9: return "Ералаш";
    }
}







void NameGenerator::degenerateName(string &p) {
    short r;
    if (p == "Evgeny") {
        r = rand() % 2;
        if (r == 0) p = "Evgeni";
        else p = "Evgeniy";
    }
    if (p == "Fedor") {
        r = rand() % 2;
        if (r == 0) p = "Febor";
        else p = "Feedor";
    }
    if (p == "John") {
        r = rand() % 2;
        if (r == 0) p = "Jonn";
        else p = "Iohn";
    }
    if (p == "Sergey") {
        r = rand() % 2;
        if (r == 0) p = "Sergei";
        else p = "Sergeiy";
    }
    if (p == "Konstantin") p = "Kontatin";
    if (p == "Dmitri") {
        r = rand() % 3;
        if (r == 0) p = "Dmitrii";
        else if(r==1) p = "Nikita";
        else if (r == 2) p = "Dmitriy";
    }
    if (p == "Bill") {
        r = rand() % 2;
        if (r == 0) p = "BiII";
        else p = "Bi1l";
    }
    if (p == "Shirma") {
        r = rand() % 2;
        if (r == 0) p = "Shirna";
        else p = "Snirma";
    }
    if (p == "Nikolai") {
        r = rand() % 2;
        if (r == 0) p = "Nikolay";
        else p = "Hikolai";
    }
    if (p == "Boris") p = "Borys";


    if (p == "Lisevsky") {
        r = rand() % 2;
        if (r == 0) p = "Lisevski";
        else p = "Licevsky";
    }
    if (p == "Jurianov") {
        r = rand() % 2;
        if (r == 0) p = "Juryanov";
        else p = "Jurianow";
    }
    if (p == "Bushuev") {
        r = rand() % 2;
        if (r == 0) p = "Bushuew";
        else p = "Buchuev";
    }
    if (p == "Krivenya") {
        r = rand() % 2;
        if (r == 0) p = "Kryvenia";
        else p = "Krivenia";
    }
    if (p == "Selivanov") {
        r = rand() % 2;
        if (r == 0) p = "Silivanov";
        else p = "Seliwanov";
    }
    if (p == "Burdashev") {
        r = rand() % 2;
        if (r == 0) p = "Burdachev";
        else p = "Burdachew";
    }
    if (p == "Kravchenko") {
        r = rand() % 2;
        if (r == 0) p = "Kravchenkov";
        else p = "Krachenko";
    }
    if (p == "Dvinyatin") {
        r = rand() % 2;
        if (r == 0) p = "Dvinyatyn";
        else p = "Dvinya1in";
    }
    if (p == "Dudikov") {
        r = rand() % 2;
        if (r == 0) p = "Dudykov";
        else p = "Dubikov";
    }
    if (p == "Nikitin") p = "Nikiitin";
}


