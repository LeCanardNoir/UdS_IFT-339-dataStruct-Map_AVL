// map.cpp : définit le point d'entrée de l'application.
//

#include "map.h"
#include <iostream>

using namespace std;

int main()
{
	map<int, string> m1;
	map<int, string> m3;
	m1.insert(0, "rien");
	m1.insert(1, "Premier");
	m1.insert(2, "Deuxième");
	m1.insert(3, "Troisième");
	m1.insert(4, "Quatrième");
	m1.insert(5, "Cinquième");
	m1.insert(-5, "- Cinquième");
	m1.insert(6, "Sixième");
	m1.insert(-6, "moins Sixième");
	m1.insert(7, "Septième");
	m1.insert(-7, "- Septième");
	m1.insert(8, "Huitième");
	m1.insert(9, "Neuvième");
	m1.insert(10, "Dixième");
	m1.insert(11, "Onzième");
	m1.insert(12, "Douzième");
	m1.insert(13, "Treizième");
	m1.insert(14, "quatorze");
	m1.insert(15, "15");
	m1.insert(16, "16");
	m1.insert(-10, "moins dix");

	/*auto it = m1.lower_bound(10);
	std::cout << (*it).second << endl;*/

	m1.afficher(cout);

	map<string, string> m2;
	m2.insert("help", "I'm stuck");
	m2.insert("Bruno", "Is a fucking dumb");
	m2.insert("Gab", "Is a genuis");
	m2.insert("Mario", "It's MARIO");
	m2.insert("Batman", "I'm Batman,... i guess!!");
	m2.insert("Robin", "Who????");
	m2.insert("Flash", "It's so long");
	m2.insert("SuperMan", "I'm Clark Ken,... the Barbie's boyfriend");
	m2.insert("ish", "lebidish");
	m2.insert("ZZZZZ", "Wake up ostie");
	m2.insert("zzzzz", "baby ZZZZZ");
	m2.insert("aaa", "3a");
	m2.insert("10", "10");
	m2.afficher(cout);


	cout << endl << "Tests de la prof" << endl;
	map<int, std::string> mapDuProf;

	cout << endl << "État initial du map" << endl;
	mapDuProf.afficher(cout);

	cout << endl << "Insertion de 9" << endl;
	mapDuProf.insert(9, "9");
	mapDuProf.afficher(cout);

	cout << endl << "Insertion de 4" << endl;
	mapDuProf.insert(4, "4");
	mapDuProf.afficher(cout);

	cout << endl << "Insertion de 12" << endl;
	mapDuProf.insert(12, "12");
	mapDuProf.afficher(cout);

	cout << endl << "Insertion de 8" << endl;
	mapDuProf.insert(8, "8");
	mapDuProf.afficher(cout);

	cout << endl << "Insertion de 6" << endl;
	mapDuProf.insert(6, "6");
	mapDuProf.afficher(cout);

	cout << endl << "Insertion de 5" << endl;
	mapDuProf.insert(5, "5");
	mapDuProf.afficher(cout);

	cout << endl << "Insertion de 15" << endl;
	mapDuProf.insert(15, "15");
	mapDuProf.afficher(cout);

	cout << endl << "Supression de 9" << endl;
	mapDuProf.erase(9);
	mapDuProf.afficher(cout);

	cout << endl << "Supression de 6" << endl;
	mapDuProf.erase(6);
	mapDuProf.afficher(cout);

	cout << endl << "Ajout de 50" << endl;
	mapDuProf.insert(50, "50");
	mapDuProf.afficher(cout);

	cout << endl << "Insertion de 49 en utilisant iterateur resultant de l'ajout de 50" << endl;

	/*map<int, std::string> mIterator;
	mIterator.insert(49, "49");*/
	map<int, string>::iterator it = mapDuProf.lower_bound(50);

	cout << (*it).first << endl;

	mapDuProf.insert(it, 49, "test");
	mapDuProf.afficher(cout);

	cout << endl << "Supression du 3e element" << endl;
	auto itTroisiemeElement = mapDuProf.begin();
	itTroisiemeElement++;
	itTroisiemeElement++;
	mapDuProf.erase(itTroisiemeElement);


	cout << "Fin des tests du prof" << endl;

	return 0;
}
