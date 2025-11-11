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
			cout << "Wynik w Celsius: " << FtoC() << endl;
			cout << "Prosze wcisnac enter";
			break;
		case 2:
			cout << "Wynik w Kelwin: " << FtoK() << endl;
			break;
		case 3:
			cout << "Wynik w Fahr: " << CtoF() << endl;
			break;
		case 4:
			cout << "Wynik w Kelwin: " << CtoK() << endl;
			break;
		case 5:
			cout << "Wynik w Celsius: " << KtoC() << endl;
			break;
		case 6:
			cout << "Wynik w Fahr: " << KtoF() << endl;
			break;
		case 7:
			cout << "Koniec programu." << endl;
			return 0;
			break;
		default:
			cout << "Koniec programu." << endl;
			return 0;
			break;
		}
	}
}
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
void menu() {
	cout << "1 - przelicz Fahr->Celsius" << endl;
	cout << "2 - przelicz Fahr->Kelwin" << endl;
	cout << "3 - przelicz Celsius->Fahr" << endl;
	cout << "4 - przelicz Celsius->Kelwin" << endl;
	cout << "5 - przelicz Kelwin->Celsius" << endl;
	cout << "6 - przelicz Kelwin->Fahr" << endl;
	cout << "7 - zakończ działanie programu" << endl;
}
float pobierzC() {
	float celsius;
	cout << "Podaj stopnie w Celsius: ";
	cin >> celsius;
	check(celsius, 'C');
	cout << "Podane stopnie w Celsius: " << celsius << endl;
	return celsius;
}
float pobierzF() {
	float fahr;
	cout << "Podaj stopnie w Fahr: ";
	cin >> fahr;
	check(fahr, 'F');
	cout << "Podane stopnie w Fahr: " << fahr << endl;
	return fahr;
}
float pobierzK() {
	float kelwin;
	cout << "Podaj stopnie w Kelwin: ";
	cin >> kelwin;
	check(kelwin, 'K');
	cout << "Podane stopnie w Kelwin: " << kelwin << endl;
	return kelwin;
}
int check(float temp, char stopnie) {
	if(temp < 0 && (stopnie == 'K' || stopnie=='k')) {
		cout << "Niepoprawna wartosc temperatury w Kelwinach!\n Prosze wcisnac enter" << endl;
		cin.ignore();
		return -999;
	}
	else if (temp < 273.15 && (stopnie == 'C' || stopnie == 'c')) {
		cout << "Niepoprawna wartosc temperatury w Celsiusach!\n Prosze wcisnac enter" << endl;
		cin.ignore();
		return -999;
	}
	else if (temp < -459.67 && (stopnie == 'F' || stopnie == 'f')) {
		cout << "Niepoprawna wartosc temperatury w Fahr!\n Prosze wcisnac enter" << endl;
		cin.ignore();
		return -999;
	}
	else {
		return temp;
	}
}
