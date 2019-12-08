// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include "Date.h"
#include "Generators/NameGenerator.h"

using std::string;
using std::unordered_set;


TEST(Dates, order) {
	Date a(1, 2, 2000);
	Date b(2, 2, 2000);
	Date c(15, 1, 2000);
	Date d(31, 6, 1970);
	EXPECT_TRUE(a < b);
	EXPECT_TRUE(c < a);
	EXPECT_TRUE(d < c);
}

TEST(Dates, randBetween) {
	Date a(12,4,2016);
	Date b(13,5,1984);
	Date c;
	c = b << a;
	EXPECT_TRUE(c < a);
	EXPECT_TRUE(b < c);
}

TEST(Rand, Stamps) {
	for (int i = 0; i < 100; ++i) {
		EXPECT_TRUE(Randomizer::stampDegenerator(6)!=6);
	}
}

TEST(Rand, NamesDegen) {
	string e = "Bushuev";
	bool p = false;
	for (int i = 0; i < 10; ++i) {
		string r = NameGenerator::degenerateName(e);
		if (r == "Buchuev") p = true;
	}
	EXPECT_TRUE(p);
}

TEST(Rand, Names) {
	unordered_set<string> a{
		"Evgeny", "Fedor", "John", "Sergey", "Konstantin","Dmitri",
		"Bill", "Shirma", "Nikolai", "Boris", "Lisevsky", "Jurianov",
		"Bushuev", "Krivenya", "Selivanov", "Burdashev", "Kravchenko",
		"Dvinyatin", "Dudikov", "Nikitin"
	};
	for(auto arg : a) {
		EXPECT_TRUE(NameGenerator::degenerateName(arg)!=arg);
	}
}
