#include <iostream>
#include <vector>

using namespace std;

// funkcja wykonująca sito Eratostenesa
vector<bool> sito(int n) {
    vector<bool> liczby(n + 1, true);

    liczby[0] = liczby[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (liczby[i]) {
            for (int j = i * i; j <= n; j += i) {
                liczby[j] = false;
            }
        }
    }

    return liczby;
}

// funkcja znajdująca liczby bliźniacze
void liczbyBlizniacze(const vector<bool>& pierwsze, int n) {
    int licznik_par = 0;
    long long suma = 0;

    cout << "Liczby blizniacze do " << n << ":" << endl;

    for (int i = 2; i <= n - 2; i++) {
        if (pierwsze[i] && pierwsze[i + 2]) {
            cout << "(" << i << ", " << i + 2 << ")" << endl;

            licznik_par++;
            suma += i + (i + 2);
        }
    }

    cout << "\nLiczba par blizniaczych: " << licznik_par << endl;
    cout << "Suma wszystkich liczb blizniaczych: " << suma << endl;
}

int main() {
    int n = 1000000;

    vector<bool> pierwsze = sito(n);
    liczbyBlizniacze(pierwsze, n);

    return 0;
}
