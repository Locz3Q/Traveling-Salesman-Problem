/**  @file */
#pragma once
#ifndef SELECTION_H
#define SELECTION_H

using namespace std;
/** Funkcja zwraca Najsilniejszego osobnika (ojca) z pierwszej czesci selekcji turniejowej przeprowadzanej miedzy polowa populacji.
@param Individuals liczba osobnikow powstalych w wyniku pojedynczej generacji
@param Sum wektor zawierajacy sumy polaczen pomiedzy kazdym genomem pojedynczego osobnika
@return Indeks najsilniejszego osobnika wyselekcjowanego sposrod polowy osobnikow populacji
*/
int tournamentSelection1(int Individuals, vector<int> Sum);

/** Funkcja zwraca Najsilniejszego osobnika (Matke) z drugiej czesci selekcji turniejowej przeprowadzanej miedzy druga polowa populacji.
@param Individuals liczba osobnikow powstalych w wyniku pojedynczej generacji
@param Sum wektor zawierajacy sumy polaczen pomiedzy kazdym genomem pojedynczego osobnika
@return Indeks najsilniejszego osobnika wyselekcjowanego sposrod drugiej polowy osobnikow populacji
*/
int tournamentSelection2(int Individuals, vector<int> Sum);

#endif // !SELECTION_H