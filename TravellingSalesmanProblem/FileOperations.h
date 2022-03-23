/**  @file */
#pragma once

#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

using namespace std;
/** Funkcja ktorej zadaniem jest przeczytanie i zapisanie macierzy z pliku tekstowego do wlasciwych wektorow
@param FileName nazwa pliku wejsciowego z macierza
@param Array to dwuwymiarowy wektor  wktorym zapisana jest pierwotna macierz z pliku zawierajaca odleglosci miedzy miastami
@param Connection wektor tymczasowy sluzacy do zapisywania pojedynczego wiersza macierzy
@param NameOfTowns Nazwy miast jakie wystepuja w macierzy
@return Zwraca liczbe miast w macierzy
*/
int readMatrixFromFile(string FileName, vector<vector<int>>& Array, vector<int>& Connection, vector<string>& NameOfTowns);

/** Funkcja zapisauje najlepiej przystosowanych osobnikow kazdej z generacji wraz z ich dlugoscia trasy
@param TheBestIndividuals dwuwymiarowy wektor ktory zawiera najlepiej przystosowanych osobnikow po skrzyzowaniu i ewentualnej mutacji
@param NameOfTowns wektor w ktorym zapisane sa w kolejnosci przypadajacej na osobnika nazwy miast
@param FileName nazwa pliku wyjsciowego podana przez uzytkownika w ktorej zostana zapisani najlepiej przystosowane osobniki
@param Generation przekazuje informacje ktora generacja jest aktualnie analizowana
@param BestSum wektor w ktorym sa zapisane sumy calych tras najlepiej przystosowanych osobnikow
*/
void saveInFile(vector<vector<int>> TheBestIndividuals, vector<string> NameOfTowns, string FileName, int Generation, vector<int> BestSum);

#endif // !FILEOPERATIONS_H