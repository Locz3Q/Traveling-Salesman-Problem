/**  @file */
#pragma once
#ifndef NEWPOPULATION_H
#define NEWPOPULATION_H

using namespace std;
/** Funkcja generuje osobnika i zostaje powtarzana tyle razy az stworzy populacje w ramach kazdej generacji zapisujac dane do wektorow
@param NumberOfTowns ilosc miast z ktorych nalezy stworzyc osobnika
@param Iteration Zawiera indeks ktory oznacza ktory osobnik jest aktualnie tworzony
@param Array to dwuwymiarowy wektor  wktorym zapisana jest pierwotna macierz z pliku zawierajaca odleglosci miedzy miastami
@param NameOfTowns wektor w ktorym zapisane sa w kolejnosci przypadajacej na osobnika nazwy miast
@param Tour wektor tymczasowy sluzacy do zapisywania genomu jednego osobnika w formie indeksow miast
@param Value wektor tymczasowy w ktorym zawarte sa wielkosci polaczen miedzy miastami danego osobnika
@param Population wektor dwuwymiarowy zawierajacy odleglosci miedzy miastami kazdego osobnika populacji
@param Sum wektor zawierajacy sumy polaczen pomiedzy kazdym genomem pojedynczego osobnika
@param CitiesIndex wektor dwuwymiarowy w ktorym zapisane sa indeksy miast kazdego osobnika generacji, np. "0 2 3 1" gdzie 0=A, 1=B, 2=C, 3=D
*/
void generatePopulation(int NumberOfTowns, int Iteration, vector<vector<int>> Array, vector<string> NameOfTowns, vector<int>& Tour, vector<int>& Value, vector<vector<int>>& Population, vector<int>& Sum, vector<vector<int>>& CitiesIndex);

#endif // !NEWPOPULATION_H