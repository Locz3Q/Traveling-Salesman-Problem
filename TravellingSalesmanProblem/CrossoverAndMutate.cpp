#include <iostream>
#include <vector>
#include <time.h>
#include <list>

#include "Utilities.h"
using namespace std;

void checkMapping(vector<vector<int>>& Mapping, int FirstCut, int SecondCut, vector<vector<int>> CitiesIndex, vector<vector<int>>& Children, int Parent1, int Parent2, bool Leave, bool LeaveLoop) {
	vector<int> MappingValue;
	int k = 0;
	for (int i = FirstCut; i <= SecondCut; i++) {
		MappingValue.push_back(CitiesIndex[Parent1][i]);
		MappingValue.push_back(CitiesIndex[Parent2][i]);
		Mapping.push_back(MappingValue);
		Children[0][i] = Mapping[k][1];
		Children[1][i] = Mapping[k][0];
		k++;
		MappingValue.clear();
	}
	size_t SizeOfMapping = Mapping.size();
	while (!Leave) {
		SizeOfMapping = Mapping.size();
		for (size_t i = 0; i < SizeOfMapping; i++) {
			for (size_t j = i + 1; j <= SizeOfMapping; j++) {
				if (j < SizeOfMapping && Mapping[i][1] == Mapping[j][0]) {
					Mapping[i][1] = Mapping[j][1];
					Mapping.erase(Mapping.begin() + j);
					LeaveLoop = true;
					break;
				}
				else if (j < SizeOfMapping && Mapping[i][0] == Mapping[j][1]) {
					Mapping[i][0] = Mapping[j][0];
					Mapping.erase(Mapping.begin() + j);
					LeaveLoop = true;
					break;
				}
			}
			if (LeaveLoop) {
				LeaveLoop = false;
				break;
			}
			if (Mapping[i][0] == Mapping[i][1]) {
				Mapping.erase(Mapping.begin() + i);
				break;
			}
			if (i == SizeOfMapping - 1) {
				Leave = true;
				break;
			}
		}
	}
}

void mapping(int FirstCut, int SecondCut, size_t& SizeOfMapping, vector<vector<int>>& Children, vector<vector<int>> Mapping, int Towns, bool Leave, bool LeaveLoop, vector<vector<int>> Array, int& FirstSum, int& SecondSum) {
	int a = 0;
	while (a < 2) {
		for (int i = 0; i < FirstCut; i++) {
			for (size_t j = 0; j < SizeOfMapping; j++) {
				if (Children[a][i] == Mapping[j][0]) {
					Children[a][i] = Mapping[j][1];
				}
				else if (Children[a][i] == Mapping[j][1]) {
					Children[a][i] = Mapping[j][0];
				}
			}
		}
		for (int i = SecondCut + 1; i < Towns; i++) {
			for (size_t j = 0; j < SizeOfMapping; j++) {
				if (Children[a][i] == Mapping[j][0]) {
					Children[a][i] = Mapping[j][1];
				}
				else if (Children[a][i] == Mapping[j][1]) {
					Children[a][i] = Mapping[j][0];
				}
			}
		}
		int ChildrenHelper, RandomCity, PreviousGenom;
		Leave = false;
		LeaveLoop = false;
		bool LeaveFirstWhile = false, LeaveSecondWhile = false;
		while (!Leave) {
			for (int i = 1; i < Towns; i++) {
				PreviousGenom = i - 1;
				if (Array[Children[a][PreviousGenom]][Children[a][i]] == -1) {
					while (1) {
						RandomCity = random(Towns);
						if (RandomCity != i) {
							break;
						}
					}
					ChildrenHelper = Children[a][RandomCity];
					Children[a][RandomCity] = Children[a][i];
					Children[a][i] = ChildrenHelper;
					break;
				}
				if (i == Towns - 1 && Array[Children[a][i]][Children[a][0]] == -1) {
					while (1) {
						RandomCity = random(Towns);
						if (RandomCity != i) {
							break;
						}
					}
					ChildrenHelper = Children[a][RandomCity];
					Children[a][RandomCity] = Children[a][0];
					Children[a][0] = ChildrenHelper;
					break;
				}
				if (i == Towns - 1) {
					Leave = true;
				}
			}
		}

		for (int i = 0; i < Towns; i++) {
			PreviousGenom = i - 1;
			if (a == 0 && i > 0) {
				FirstSum += Array[Children[0][PreviousGenom]][Children[0][i]];
			}
			if (a == 1 && i > 0) {
				SecondSum += Array[Children[1][PreviousGenom]][Children[1][i]];
			}
		}
		a++;
	}
}

void PMXCrossover(int Parent1, int Parent2, int Towns, int Generation, vector<vector<int>> Array, vector<int> Sum,
	vector<vector<int>> CitiesIndex, vector<vector<int>>& TheStrongestIndividuals, vector<int>& BestSum, int Individuals) {
	int FirstCut = random(Towns / 2), SecondCut;
	switch (FirstCut) {
		case 0: FirstCut++;
		case 1: {
			SecondCut = Towns - (Towns - FirstCut) / 2 - 1;
			break;
		}
		default: {
			SecondCut = Towns - (Towns - FirstCut) / 2;
		}
	}
	vector<int> Helper, Temporary;
	vector<vector<int>> Children;
	for (int i = 0; i < Individuals; i++) {
		for (int j = 0; j < Towns; j++) {
			if (i == Parent1) {
				Helper.push_back(CitiesIndex[i][j]);
			}
			else if (i == Parent2) {
				Helper.push_back(CitiesIndex[i][j]);
			}
		}
		if (i == Parent1 || i == Parent2) {
			Children.push_back(Helper);
		}
		Helper.clear();
	}
	vector<vector<int>> Mapping;
	checkMapping(Mapping, FirstCut, SecondCut, CitiesIndex, Children, Parent1, Parent2, false, false);
	int FirstSum = 0, SecondSum = 0, LastGenom = Towns - 1;
	size_t SizeOfMapping = Mapping.size();
	mapping(FirstCut, SecondCut, SizeOfMapping, Children, Mapping, Towns, false, false, Array, FirstSum, SecondSum);
	FirstSum += Array[Children[0][LastGenom]][Children[0][0]];
	SecondSum += Array[Children[1][LastGenom]][Children[1][0]];

	list<int> SumOfChildren;
	SumOfChildren.assign({ FirstSum, SecondCut, 0});
	list<int>::reverse_iterator IteratorOfChildren = SumOfChildren.rbegin();
	if (FirstSum <= SecondSum) {
		*IteratorOfChildren = FirstSum;
		for (int i = 0; i < Towns; i++) {
			Temporary.push_back(Children[0][i]);
		}
	}
	else {
		*IteratorOfChildren = SecondSum;
		for (int i = 0; i < Towns; i++) {
			Temporary.push_back(Children[1][i]);
		}
	}
	if (Sum[Parent1] <= Sum[Parent2]) {
		if (Sum[Parent1] < *IteratorOfChildren) {
			Temporary.clear();
			for (int i = 0; i < Towns; i++) {
				Temporary.push_back(CitiesIndex[Parent1][i]);
			}
			TheStrongestIndividuals.push_back(Temporary);
			*IteratorOfChildren = Sum[Parent1];
		}
		else
			TheStrongestIndividuals.push_back(Temporary);
	}
	else {
		if (Sum[Parent2] < *IteratorOfChildren) {
			Temporary.clear();
			for (int i = 0; i < Towns; i++) {
				Temporary.push_back(CitiesIndex[Parent2][i]);
			}
			TheStrongestIndividuals.push_back(Temporary);
			*IteratorOfChildren = Sum[Parent2];
		}
		else
			TheStrongestIndividuals.push_back(Temporary);
	}
	Mapping.clear();
	Children.clear();
	Temporary.clear();
	BestSum.push_back(*IteratorOfChildren);
}

void mutate(vector<vector<int>> CitiesIndex, int MutationRate, int Individual, int Towns,
			vector<vector<int>> Array, vector<int> Sum, vector<int>& BestSum, vector<vector<int>>& TheBestIndividuals, int Generation) {
	int RandomNumber, LastGenom = Towns - 1, PreviousMut1 = 0, PreviousMut2 = 0, NextMut1 = 0, NextMut2 = 0, JminusOne = 0;;
	bool Loop = false, LeaveSecondLoop = false;
	vector<int> BestMutation;
	for (int i = 0; i < Individual; i++) {
		RandomNumber = random(100);
		if (RandomNumber <= MutationRate) {
			int Helper1, Helper2, Mut1, Mut2, MutateSum = 0;
			Mut1 = random(Towns);
			PreviousMut1 = Mut1 - 1;
			NextMut1 = Mut1 + 1;
			while (!Loop) {
				while (!Loop) {
					Mut2 = random(Towns);
					PreviousMut2 = Mut2 - 1;
					NextMut2 = Mut2 + 1;
					if (Mut2 == Mut1) {
						break;
					}
					if ((Mut1 == 0) && (Array[CitiesIndex[i][LastGenom]][Mut2] == -1 || Array[Mut2][CitiesIndex[i][NextMut1]] == -1)) {
						break;
					}
					else if ((Mut1 == (LastGenom)) && (Array[Mut2][CitiesIndex[i][0]] == -1 || Array[CitiesIndex[i][PreviousMut1]][Mut2] == -1)) {
						break;
					}
					else if ((Mut2 == 0) && (Array[CitiesIndex[i][LastGenom]][Mut1] == -1 || Array[Mut1][CitiesIndex[i][NextMut2]] == -1)) {
						break;
					}
					else if ((Mut2 == (LastGenom)) && (Array[Mut1][CitiesIndex[i][0]] == -1 || Array[CitiesIndex[i][PreviousMut2]][Mut1] == -1)) {
						break;
					}
					if (Mut1 - Mut2 == 1 || Mut2 - Mut1 == 1) {
						if (Array[Mut1][Mut2] == -1 || Array[Mut2][Mut1] == -1) {
							break;
						}
					}
					Helper1 = CitiesIndex[i][Mut1];
					Helper2 = CitiesIndex[i][Mut2];
					CitiesIndex[i][Mut1] = CitiesIndex[i][Mut2];
					CitiesIndex[i][Mut2] = Helper1;
					for (int j = 0; j < Towns; j++) {
						JminusOne = j - 1;
						if (j > 0 && j != (LastGenom)) {
							if (Array[CitiesIndex[i][JminusOne]][CitiesIndex[i][j]] == -1) {
								LeaveSecondLoop = true;
								break;
							}
						}
						else if (j == (LastGenom)) {
							if (Array[CitiesIndex[i][j]][CitiesIndex[i][0]] == -1 || Array[CitiesIndex[i][JminusOne]][CitiesIndex[i][j]] == -1) {
								LeaveSecondLoop = true;
								break;
							}
						}
					}
					if (LeaveSecondLoop) {
						LeaveSecondLoop = false;
						break;
					}
					Loop = true;
				}
			}
			for (int j = 0; j < Towns; j++) {
				BestMutation.push_back(CitiesIndex[i][j]);
				if (j > 0) {
					JminusOne = j - 1;
					MutateSum += Array[CitiesIndex[i][JminusOne]][CitiesIndex[i][j]];
				}

			}
			MutateSum += Array[CitiesIndex[i][LastGenom]][CitiesIndex[i][0]];
			if (MutateSum < BestSum[Generation]) {
				BestSum.pop_back();
				BestSum.push_back(MutateSum);
				TheBestIndividuals.pop_back();
				TheBestIndividuals.push_back(BestMutation);
			}
			BestMutation.clear();
		}
	}
}

