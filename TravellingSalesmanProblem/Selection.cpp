#include <iostream>
#include <vector>

#include "Selection.h"

using namespace std;

int tournamentSelection1(int Individuals, vector<int> Sum) {
	int Group1 = Individuals / 2;
	int G1 = 0;
	int Parent1 = Sum[G1];
	for (int i = 0; i < Group1; i++) {
		if (Sum[i] < Parent1) {
			Parent1 = Sum[i];
			G1 = i;
		}
	}
	return G1;
}

int tournamentSelection2(int Individuals, vector<int> Sum) {
	int Group2 = Individuals - (Individuals / 2);
	int G2 = Group2;
	int Parent2 = Sum[G2];
	for (int i = (Individuals / 2); i < Individuals; i++) {
		if (Sum[i] < Parent2) {
			Parent2 = Sum[i];
			G2 = i;
		}
	}
	return G2;
}