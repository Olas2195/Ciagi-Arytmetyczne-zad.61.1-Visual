#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

public class Ciag {
	ifstream plik;
	vector <int> liczby;
	int dlugosc;
	int max = 0;
	int poprawnych = 0;
	int roznica;
	int liczba;

public:
	string wynik;

	Ciag(string name) {
		plik.open(name);
	}

	void wczytaj() {
		if (plik.good()) {
			while (!plik.eof()) {
				plik >> dlugosc;
				for (int i = 0; i < dlugosc; i++) {
					plik >> liczba;
					liczby.push_back(liczba);
				}
				if (this->arytm()) {
					poprawnych++;
					if (roznica > max) {
						max = roznica;
					}
				}
				liczby.clear();
			}
		}
	}

	string wypisz() {
		wynik = "Najwieksza roznica: " + to_string(max) + "\nIlosc poprawnych ciagow: " + to_string(poprawnych);
		return wynik;
	}

	bool arytm() {
		roznica = liczby[1] - liczby[0];
		for (int i = 0; i < dlugosc - 1; i++) {
			if (liczby[i] + roznica != liczby[i + 1])
				return false;
		}
		return true;
	}

	~Ciag() {
		plik.close();
	}
};