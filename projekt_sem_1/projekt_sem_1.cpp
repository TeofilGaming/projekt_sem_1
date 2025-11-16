#include <iostream>
#include <stdlib.h>
using namespace std;
float FtoC();
float FtoK();
float CtoF();
float CtoK();
float KtoC();
float KtoF();
void menu();
float pobierzC();
float pobierzF();
float pobierzK();
int check(float temp, char stopnie);
void zapiszDane(float pod,float temp, char stopnie_pod, char stopnie_wyn);
int sprawdzenie;
float celsius;
float fahr;
float kelwin;
float wyn;
double dane[99];
char znak[99];
int dataCounter = 0;
int main() {
	int wybor;
	while (true) {
		system("cls");
		menu();
		cout << "Wybierz jedno z powyżchych opcje(1-7): ";
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			wyn = FtoC();
			zapiszDane(fahr, wyn, 'F','C');
			cout << "Wynik w Celsius: " << wyn << endl;
			cout << "Prosze wcisnac enter";
			cin.ignore();
			cin.get();
			break;
		case 2:
			wyn = FtoK();
			zapiszDane(fahr, wyn,'F','K');
			cout << "Wynik w Kelwin: " << wyn << endl;
			cout << "Prosze wcisnac enter";
			cin.ignore();
			cin.get();;
			break;
		case 3:
			wyn = CtoF();
			zapiszDane(celsius, wyn,'C','F');
			cout << "Wynik w Fahr: " << wyn << endl;
			cout << "Prosze wcisnac enter";
			cin.ignore();
			cin.get();
			break;
		case 4:
			wyn = CtoK();
			zapiszDane(celsius, wyn,'C','K');
			cout << "Wynik w Kelwin: " << wyn << endl;
			cout << "Prosze wcisnac enter";
			cin.ignore();
			cin.get();
			break;
		case 5:
			wyn = KtoC();
			zapiszDane(kelwin, wyn,'K','C');
			cout << "Wynik w Celsius: " << wyn << endl;
			cout << "Prosze wcisnac enter";
			cin.ignore();
			cin.get();
			break;
		case 6:
			wyn = KtoF();
			zapiszDane(kelwin, wyn,'K','F');
			cout << "Wynik w Fahr: " << wyn << endl;
			cout << "Prosze wcisnac enter";
			cin.ignore();
			cin.get();
			break;
		case 7:
			if(dataCounter==0){
				cout << "Brak historii przeliczen. Prosze wykonac przeliczenie." << endl;
				cout << "Prosze wcisnac enter";
				cin.ignore();
				cin.get();
				break;
			}
			else {
				for (int i = 0; i < dataCounter / 2; i++) {
					cout << "<1> " << dane[i] << znak[i] << " = " << dane[i + 1] << znak[i + 1] << endl;
				}
				cout << "Prosze wcisnac enter";
				cin.ignore();
				cin.get();
				break;
			}
		case 8:
			cout << "Koniec programu." << endl;
			return 0;
			break;
		default:
			cout << "Koniec programu." << endl;
			return 0;
			break;
		}
		for (int i = dataCounter; i < dataCounter + 2;i++) {

		}
	}
}
//Funkcje przeliczajace
float FtoC() {
	float wynik = (5.0 / 9.0) *(pobierzF() - 32.0);
	return wynik;
}
float FtoK() {
	float wynik = (5.0 / 9.0) * (pobierzF() +459.67);
	return wynik;
}
float CtoF() {
	float wynik = (pobierzC() * 9.0 / 5.0) + 32.0;
	return wynik;
}
float CtoK() {
	float wynik = pobierzC() + 273.15;
	return wynik;
}
float KtoC() {
	float wynik = pobierzK() - 273.15;
	return wynik;
}
float KtoF() {
	float wynik = pobierzK() * 9.0 / 5.0 - 459.67;
	return wynik;
}
//menu wyboru opcji
void menu() {
	cout << "1 - przelicz Fahr->Celsius" << endl;
	cout << "2 - przelicz Fahr->Kelwin" << endl;
	cout << "3 - przelicz Celsius->Fahr" << endl;
	cout << "4 - przelicz Celsius->Kelwin" << endl;
	cout << "5 - przelicz Kelwin->Celsius" << endl;
	cout << "6 - przelicz Kelwin->Fahr" << endl;
	cout << "7 - pokaz historie" << endl;
	cout << "8 - zakończ działanie programu" << endl;
}
//Funkcje pobierajace wartosci temperatur
float pobierzC() {
	cout << "Podaj stopnie w Celsius: ";
	cin >> celsius;
	sprawdzenie = check(celsius, 'C');
	if (sprawdzenie == -999) {
		return pobierzC();
	}
	cout << "Podane stopnie w Celsius: " << celsius << endl;
	return celsius;
}
float pobierzF() {
	cout << "Podaj stopnie w Fahr: ";
	cin >> fahr;
	sprawdzenie = check(fahr, 'F');
	if (sprawdzenie == -999) {
		return pobierzF();
	}
	cout << "Podane stopnie w Fahr: " << fahr << endl;
	return fahr;
}
float pobierzK() {
	cout << "Podaj stopnie w Kelwin: ";
	cin >> kelwin;
	sprawdzenie=check(kelwin, 'K');
	if(sprawdzenie==-999){
		return pobierzK();
	}
	cout << "Podane stopnie w Kelwin: " << kelwin << endl;
	return kelwin;
}
//funkcja sprawdzajaca poprawnosc wartosci temperatur
int check(float temp, char stopnie) {
	if(temp < 0 && (stopnie == 'K' || stopnie=='k')) {
		cout << "Niepoprawna wartosc temperatury w Kelwinach! Nie moze byc mniejsza od 0\nProsze wcisnac enter" << endl;
		cin.ignore();
		cin.get();
		return -999;
	}
	else if (temp < -273.15 && (stopnie == 'C' || stopnie == 'c')) {
		cout << "Niepoprawna wartosc temperatury w Celsiusach! Nie moze byc mniejsza od -273.15\nProsze wcisnac enter" << endl;
		cin.ignore();
		cin.get();
		return -999;
	}
	else if (temp < -459.67 && (stopnie == 'F' || stopnie == 'f')) {
		cout << "Niepoprawna wartosc temperatury w Fahr! Nie moze byc mniejsza od -459.67\nProsze wcisnac enter" << endl;
		cin.ignore();
		cin.get();
		return -999;
	}
	else {
		return temp;
	}
}
//funkcja zapisujaca dane do tablicy
void zapiszDane(float pod,float temp, char stopnie_pod, char stopnie_wyn) {
	dane[dataCounter] = pod;
	dane[dataCounter+1] = temp;
	znak[dataCounter] = stopnie_pod;
	znak[dataCounter + 1] = stopnie_wyn;

	dataCounter += 2;
}
