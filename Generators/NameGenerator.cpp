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
    case 1: return "Бразилия";
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







string NameGenerator::degenerateName(string p) {
    if (p == "Evgeny") {
        if (rand()%2) return "Evgeni";
        return "Evgeniy";
    }
    if (p == "Fedor") {
        if (rand()%2) return "Febor";
        return "Feedor";
    }
    if (p == "John") {
        if (rand()%2) return "Jonn";
        return "Iohn";
    }
    if (p == "Sergey") {
        if (rand()%2) return "Sergei";
        return "Sergeiy";
    }
    if (p == "Konstantin") return "Kontatin";
    if (p == "Dmitri") {
        if (rand()%3==0) return "Dmitrii";
        else if(rand()%2) return "Nikita";
        return "Dmitriy";
    }
    if (p == "Bill") {
        if (rand()%2) return "BiП";
        return "Bi1l";
    }
    if (p == "Shirma") {
        if (rand()%2) return "Shirna";
        return "Snirma";
    }
    if (p == "Nikolai") {
        if (rand()%2) return "Nikolay";
        return "Hikolai";
    }
    if (p == "Boris") return "Borys";


    if (p == "Lisevsky") {
        if (rand()%2) return "Lisevski";
        return "Licevsky";
    }
    if (p == "Jurianov") {
        if (rand()%2) return "Juryanov";
        return "Jurianow";
    }
    if (p == "Bushuev") {
        if (rand()%2) return "Bushuew";
        return "Buchuev";
    }
    if (p == "Krivenya") {
        if (rand()%2) return "Kryvenia";
        return "Krivenia";
    }
    if (p == "Selivanov") {
        if (rand()%2) return "Silivanov";
        return "Seliwanov";
    }
    if (p == "Burdashev") {
        if (rand()%2) return "Burdachev";
        return "Burdachew";
    }
    if (p == "Kravchenko") {
        if (rand()%2) return "Kravchenkov";
        return "Krachenko";
    }
    if (p == "Dvinyatin") {
        if (rand()%2) return "Dvinyatyn";
        return "Dvinya1in";
    }
    if (p == "Dudikov") {
        if (rand()%2) return "Dudykov";
        return "Dubikov";
    }
    if (p == "Nikitin") return "Nikiitin";

    return p;
}


