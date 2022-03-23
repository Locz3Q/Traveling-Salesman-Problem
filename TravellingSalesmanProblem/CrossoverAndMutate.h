/**  @file */
#pragma once

#ifndef CROSSOVERANDMUTATE_H
#define CROSSOVERANDMUTATE_H

using namespace std;
/** Funkcja krzyzuje dwoch najlepszych osobnikow wyselekcjonowanych w selekcji turniejowej
@param Parent1 indeks do osobnika najlepiej przystosowanego z pierwszej selekcji
@param Parent2 indeks do osobnika najlepiej przystosowanego z drugiej selekcji
@param Towns ilosc miast z ktorych zbudowane sa osobniki
@param Generation przekazuje informacje ktora generacja jest aktualnie analizowana
@param Array to dwuwymiarowy wektor  wktorym zapisana jest pierwotna macierz z pliku zawierajaca odleglosci miedzy miastami
@param Sum wektor zawierajacy sumy polaczen pomiedzy kazdym genomem pojedynczego osobnika
@param CitiesIndex wektor dwuwymiarowy w ktorym zapisane sa indeksy miast kazdego osobnika generacji, np. "0 2 3 1" gdzie 0=A, 1=B, 2=C, 3=D
@param TheStrongestIndividuals dwuwymiarowy wektor ktory zawiera najlepiej przystosowanych osobnikow
@param BestSum wektor w ktorym sa zapisane sumy calych tras najlepiej przystosowanych osobnikow
@param Individuals przekazuje indeks aktualnie analizowanego osobnika generacji
*/
void PMXCrossover(int Parent1, int Parent2, int Towns, int Generation, vector<vector<int>> Array, vector<int> Sum, vector<vector<int>> CitiesIndex, vector<vector<int>>& TheStrongestIndividuals, vector<int>& BestSum, int Individuals);

/** Funkcja w ktorej przeprowadzana jest ewentualna mutacja losowo wybranych osobnikow z generacji. Domyslnie szansa na mutacje wynosi 0.02
@param CitiesIndex wektor dwuwymiarowy w ktorym zapisane sa indeksy miast kazdego osobnika generacji, np. "0 2 3 1" gdzie 0=A, 1=B, 2=C, 3=D
@param MutationRate przekazuje wartosc szansy na przeprowadzenie mutacji. Intuicyjnie wartosc mozna uznac jako przekazywana w %
@param Individual przekazuje indeks aktualnie analizowanego osobnika generacji
@param Towns ilosc miast z ktorych zbudowane sa osobniki
@param Array to dwuwymiarowy wektor  wktorym zapisana jest pierwotna macierz z pliku zawierajaca odleglosci miedzy miastami
@param Sum wektor zawierajacy sumy polaczen pomiedzy kazdym genomem pojedynczego osobnika
@param BestSum wektor w ktorym sa zapisane sumy calych tras najlepiej przystosowanych osobnikow
@param TheBestIndividuals dwuwymiarowy wektor ktory zawiera najlepiej przystosowanych osobnikow po skrzyzowaniu
@param Generation przekazuje informacje ktora generacja jest aktualnie analizowana
*/
void mutate(vector<vector<int>> CitiesIndex, int MutationRate, int Individual, int Towns, vector<vector<int>> Array, vector<int> Sum, vector<int>& BestSum, vector<vector<int>>& TheBestIndividuals, int Generation);

/** Funkcja sprawdza poprawnosc mapowania oraz skraca je do najbardziej optymalnej wielkosci
@param Mapping wektor dwuwymiarowy przechowujacy wartosci mapowania powstalego w celu eliminacji blednych polaczen 
@param FirstCut numer OD ktorego ma odbyc sie krzyzowanie
@param SecondCut numer DO ktorego ma odbyc sie krzyzowanie
@param CitiesIndex wektor dwuwymiarowy w ktorym zapisane sa indeksy miast kazdego osobnika generacji, np. "0 2 3 1" gdzie 0=A, 1=B, 2=C, 3=D
@param Children wektor dwuwymiarowy zawierajacy dwoch osobnikow powstalych w ramach krzyzowania
@param Parent1 indeks do osobnika najlepiej przystosowanego z pierwszej selekcji
@param Parent2 indeks do osobnika najlepiej przystosowanego z drugiej selekcji
@param Leave Przyjmuje false lub true w celu wyjscia z petli while
@param LeaveLoop Przyjmuje false lub true w celu wyjscia z wewnetrznej petli while
*/
void checkMapping(vector<vector<int>>& Mapping, int FirstCut, int SecondCut, 
					vector<vector<int>> CitiesIndex, vector<vector<int>>& Children, int Parent1, int Parent2,
					bool Leave, bool LeaveLoop);

/** Funkcja przeprowadza mapowanie czyli zamiane czesci genomu w celu unikniecia nieprawidlowych polaczen
@param FirstCut numer OD ktorego ma odbyc sie krzyzowanie
@param SecondCut numer DO ktorego ma odbyc sie krzyzowanie
@param SizeOfMapping przechowuje rozmiar wektora mapowania
@param Children wektor dwuwymiarowy zawierajacy dwoch osobnikow powstalych w ramach krzyzowania
@param Mapping wektor dwuwymiarowy przechowujacy wartosci mapowania powstalego w celu eliminacji blednych polaczen
@param Towns ilosc miast z ktorych zbudowane sa osobniki
@param Leave Przyjmuje false lub true w celu wyjscia z petli while
@param LeaveLoop Przyjmuje false lub true w celu wyjscia z wewnetrznej petli while
@param Array to dwuwymiarowy wektor  wktorym zapisana jest pierwotna macierz z pliku zawierajaca odleglosci miedzy miastami
@param FirstSum przechowuje dlugosc trasy jednego dziecka po mapowaniu
@param FirstSum przechowuje dlugosc trasy drugiego dziecka po mapowaniu
*/
void mapping(int FirstCut, int SecondCut, size_t& SizeOfMapping, vector<vector<int>>& Children, vector<vector<int>> Mapping, 
			int Towns, bool Leave, bool LeaveLoop, vector<vector<int>> Array, int& FirstSum, int& SecondSum);
#endif // !CROSSOVERANDMUTATE_H
