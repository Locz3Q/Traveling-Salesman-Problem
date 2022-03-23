#include <iostream>
#include <vector>
#include "Utilities.h"
using namespace std;

int random(int Number) {
	return rand() % Number;
}

void clearVectors(vector<vector<int>>& Population, vector<int>& Sum, vector<vector<int>>& CitiesIndex) {
	CitiesIndex.clear();
	Sum.clear();
	Population.clear();
}

void showHelper() {
	cout << endl << "Do prawidlowego dzialania programu nalezy wprowadzic nastepujace parametry:" << endl;
	cout << "-i Plik wejsciowy zawierajacy macierz odleglosci miedzy miastami" << endl;
	cout << "-o Plik wyjsciowy w ktorym zostana wypisane najlepsze rozwiazania kazdej z generacji" << endl;
	cout << "-g Liczba generacji jaka ma stworzyc algorytm" << endl;
	cout << "-n Liczba osobnikow przypadajacych na jedno pokolenie" << endl;
	cout << "NIE MA WYMOGU WPISYWANIA PARAMETROW W DANEJ KOLEJNOSCI!" << endl;
	exit(2);
}