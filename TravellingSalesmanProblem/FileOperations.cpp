#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "FileOperations.h"

using namespace std;

int readMatrixFromFile(string FileName, vector<vector<int>>& Array, vector<int>& Connection, vector<string>& NameOfTowns) {
	fstream File;
	File.open(FileName, ios::in);
	cout << "Sprawdzam poprawnosc pliku z macierza...";
	if (File.good() == 0) {
		cout << "Plik jest bledny!!!" << endl;
		exit(2);
	}
	cout << "OK!" << endl;

	string Towns;
	int TConnect, It = 0;
	while (File >> Towns) {
		if (Towns == "0") {
			break;
		}
		NameOfTowns.push_back(Towns);
		It++;
	}

	size_t NumberOfTowns = NameOfTowns.size();
	It *= 2;
	File.seekg(It);
	size_t column = 0;

	while (!File.eof()) {
		File >> TConnect;
		Connection.push_back(TConnect);
		column++;
		if (column == NumberOfTowns) {
			column = 0;
			Array.push_back(Connection);
			Connection.clear();
		}
	}
	File.close();
	return NumberOfTowns;
}



void saveInFile(vector<vector<int>> TheBestIndividuals, vector<string> NameOfTowns, string FileName, int Generation, vector<int> BestSum) {
	cout << "Zapisuje najsilniejszych osobnikow kazdej z generacji do pliku o nazwie " << FileName << "...";
	ofstream OutFile(FileName);
	OutFile << "Oto najlepsze trasy znalezione przez algorytm:" << endl;
	int j = 0;
	for (int i = 0; i < Generation; i++) {
		OutFile << "Generacja " << i + 1 << ", dlugosc " << BestSum[i] << endl;
		for (auto& Iterator : NameOfTowns) {
			OutFile << NameOfTowns[TheBestIndividuals[i][j]] << " ";
			j++;
		}
		OutFile << NameOfTowns[TheBestIndividuals[i][0]];
		OutFile << endl << endl;
		j = 0;
	}
	cout << "OK!" << endl;
}