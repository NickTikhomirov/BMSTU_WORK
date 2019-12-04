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
    static const unordered_map<short, string> generates {
        {0,"Россия"},
        {1,"Бразилия"},
        {2,"Гондурас"},
        {3,"Италия"},
        {4,"Словения"},
        {5,"Германия"},
        {6,"США"},
        {7,"Китай"},
        {8,"Австрия"},
        {9,"Венгрия"}
    };
    return generates.find(rand()%10)->second;
}

string NameGenerator::generateBadCountry(){
    static const unordered_map<short, string> generates {
        {0,"Югославия"},
        {1,"СССР"},
        {2,"Чехословакия"},
        {3,"Пандария"},
        {4,"Нарния"},
        {5,"Сатурн"},
        {6,"Биробиджан"},
        {7,"Татарстан"},
        {8,"Атлантида"},
        {9,"Ералаш"}
    };
    return generates.find(rand()%10)->second;
}


string NameGenerator::degenerateName(string p) {
    static const unordered_map<string,unordered_set<string>> degenerates{
        {"Evgeny",
            {"Evgeni","Evgeniy"}},
        {"Fedor",
            {"Febor","Feedor"}},
        {"John",
            {"Jonn","Iohn"}},
        {"Sergey",
            {"Sergei","Sergeiy"}},
        {"Konstantin",
            {"Kontatin"}},
        {"Dmitri",
            {"Dmitrii","Nikita","Dmitriy"}},
        {"Bill",
            {"BiП","Bi1l"}},
        {"Shirma",
            {"Shirna","Snirma"}},
        {"Nikolai",
            {"Nikolay","Hikolai"}},
        {"Boris",
            {"Borys"}},

        {"Lisevsky",
            {"Lisevski","Licevsky"}},
        {"Jurianov",
            {"Juryanov","Jurianow"}},
        {"Bushuev",
            {"Bushuew","Buchuev"}},
        {"Krivenya",
            {"Kryvenia","Krivenia"}},
        {"Selivanov",
            {"Silivanov","Seliwanov"}},
        {"Burdashev",
            {"Burdachev","Burdachew"}},
        {"Kravchenko",
            {"Kravchenkov","Krachenko"}},
        {"Dvinyatin",
            {"Dvinyatyn","Dvinya1in"}},
        {"Dudikov",
            {"Dudykov","Dubikov"}},
        {"Nikitin",{"Nikiitin"}}
    };
    auto f = degenerates.find(p);
    if(f==degenerates.end()) return p;
    return Randomizer::randOfSet<string>(f->second);
}


