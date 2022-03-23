/**  @file */
#pragma once
#ifndef UTILITIES_H
#define UTILITIES_H

using namespace std;
/** Funkcja zwraca pseudolosowa liczbe w zaleznosci od potrzeby algorytmu.
@param Number liczba przekazywana do funkcji z ktorej bedzie brana reszta z dzielenia
@return Liczba pseudolosowa wygenerowana na podstawie czasu systemowego, mniejsza od liczby Number
*/
int random(int Number);

/** Funkcja ma za zadanie wyczyscic zawartosc podanych wektorow w celu przygotowania ich do kolejnej generacji.
@param Population wektor dwuwymiarowy zawierajacy odleglosci miedzy miastami kazdego osobnika populacji
@param Sum wektor zawierajacy sumy polaczen pomiedzy kazdym genomem pojedynczego osobnika
@param CitiesIndex wektor dwuwymiarowy w ktorym zapisane sa indeksy miast kazdego osobnika generacji, np. "0 2 3 1" gdzie 0=A, 1=B, 2=C, 3=D
*/
void clearVectors(vector<vector<int>>& Population, vector<int>& Sum, vector<vector<int>>& CitiesIndex);

/** Funkcja informuje uzytkownika o mozliwych do uzycia przelacznikach*/
void showHelper();

#endif // !UTILITIES_H
