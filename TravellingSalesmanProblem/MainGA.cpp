#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <time.h>

#include "FileOperations.h"
#include "Selection.h"
#include "CrossoverAndMutate.h"
#include "Utilities.h"
#include "NewPopulation.h"

using namespace std;
int main(int argc, char* argv[]) {

	string InFile, OutFile;
	string Parametri = "-i", Parametro = "-o", Parametrg = "-g", Parametrn = "-n", Parametrh = "-h";
	int Individual = 0, Generations = 0;
	for (int i = 0; i < argc; i++) {
		if (argv[i] == Parametri) {
			InFile = argv[i + 1];
		}
		else if (argv[i] == Parametro) {
			OutFile = argv[i + 1];
		}
		else if (argv[i] == Parametrg) {
			Generations = stoi(argv[i + 1]);
		}
		else if (argv[i] == Parametrn) {
			Individual = stoi(argv[i + 1]);
		}
		else if (argv[i] == Parametrh) {
			showHelper();
		}
		else if (i == 1) {
			cout << endl << "Niewlasciwe Przelaczniki!" << endl;
			showHelper();
		}
	}
	if (!argv[1]) {
		showHelper();
	}
	vector<int> Connection, Tour, Value, Sum, BestSum;
	vector<vector<int>> Array, CitiesIndex, Population, TheStrongestIndividuals;
	vector<string> NameOfTowns;

	cout << endl;
	srand((unsigned int)time(NULL));

	int NumberOfTowns = readMatrixFromFile(InFile, Array, Connection, NameOfTowns), MutationRate = 2, Father, Mother;

	for (int i = 0; i < Generations; i++) {
		if (i == 0) {
			cout << "Rozpoczynam dzialanie Algorytmu genetycznego dla " << Generations << " Generacji, w kazdej po " << Individual << " osobnikow...";
		}
		for (int j = 0; j < Individual; j++) {
			generatePopulation(NumberOfTowns, j, Array, NameOfTowns, Tour, Value, Population, Sum, CitiesIndex);
		}
		
		Father = tournamentSelection1(Individual, Sum);
		Mother = tournamentSelection2(Individual, Sum);
		PMXCrossover(Father, Mother, NumberOfTowns, i, Array, Sum, CitiesIndex, TheStrongestIndividuals, BestSum, Individual);
		mutate(CitiesIndex, MutationRate, Individual, NumberOfTowns, Array, Sum, BestSum, TheStrongestIndividuals, i);
		clearVectors(Population, Sum, CitiesIndex);
		if (i == Generations - 1) {
			cout << "OK!" << endl;
		}
	}
	saveInFile(TheStrongestIndividuals, NameOfTowns, OutFile, Generations, BestSum);
	cout << endl;
	return 0;
}