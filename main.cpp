// map.cpp : définit le point d'entrée de l'application.
//

#include "map.h"
#include <iostream>

using namespace std;

int main()
{
	map<string, string> m1;
	m1.insert("help", "I'm stuck");
	m1.insert("Bruno", "Is a fucking dumb");
	m1.insert("Gab", "Is a genuis");
	m1.insert("Mario", "It's MARIO");
	m1.insert("Batman", "I'm Batman,... i guess!!");
	m1.insert("Robin", "Who????");
	m1.insert("Flash", "It's so long");
	m1.insert("SuperMan", "I'm Clark Ken,... the Barbie's boyfriend");
	m1.insert("ish", "lebidish");
	m1.insert("ZZZZZ", "Wake up ostie");
	m1.insert("zzzzz", "baby ZZZZZ");
	m1.insert("aaa", "3a");

	m1.afficher(cout);
	return 0;
}
