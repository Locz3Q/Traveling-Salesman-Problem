#include <iostream>
#include <vector>
#include <list>

#include "Utilities.h"
#include "NewPopulation.h"

using namespace std;

void generatePopulation(int NumberOfTowns, int Iteration, vector<vector<int>> Array, vector<string> NameOfTowns,
						vector<int>& Tour, vector<int>& Value, vector<vector<int>>& Population, vector<int>& Sum,
						vector<vector<int>>& CitiesIndex) {
	int Target, Add = 0, MinusOne = 0, IminusOne = 0;
	vector<int> Check;
	bool FirstLoop = false, SecondLoop = false, LeaveSecondLoop = false, LeaveFirstLoop = false;
	while (!FirstLoop) {
		Add = 0; 
		MinusOne = 0;
		for (int i = 0; i < NumberOfTowns; i++) {
			SecondLoop = false;
			IminusOne = i - 1;
			while (!SecondLoop) {
				if (MinusOne > NumberOfTowns * 2) {
					MinusOne = 0;
					Tour.clear();
					Value.clear();
					Check.clear();
					LeaveFirstLoop = true;
					break;
				}
				Target = random(NumberOfTowns);
				Check.push_back(Target);
				for (int j = 0; j < i; j++) {
					if (Check[j] == Target || Array[Check[IminusOne]][Check[i]] == -1) {
						MinusOne++;
						Check.pop_back();
						LeaveSecondLoop = true;
						break;
					}
				}
				if (LeaveSecondLoop) {
					LeaveSecondLoop = false;
					i--;
					break;
				}
				if (i > 0) {
					Tour.push_back(Check[IminusOne]);
					Value.push_back(Array[Check[IminusOne]][Check[i]]);
					Add += Array[Check[IminusOne]][Check[i]];
				}
				if (i == NumberOfTowns - 1) {
					if (Array[Check[i]][Check[0]] == -1) {
						MinusOne++;
						Tour.clear();
						Value.clear();
						Check.clear();
						LeaveFirstLoop = true;
						break;
					}
					Tour.push_back(Check[i]);
					Value.push_back(Array[Check[IminusOne]][Check[i]]);
					Add += Array[Check[i]][Check[0]];
				}
				SecondLoop = true;
			}
			if (LeaveFirstLoop) {
				LeaveFirstLoop = false;
				break;
			}
			if (i == NumberOfTowns - 1) {
				FirstLoop = true;
			}
		}
	}
	
	Population.push_back(Value);
	CitiesIndex.push_back(Tour);
	Sum.push_back(Add);
	Check.clear();
	MinusOne = 0;
	Tour.clear();
	Value.clear();
}