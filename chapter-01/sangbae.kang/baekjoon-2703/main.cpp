#include <iostream>
#include <map>

using namespace std;

void problem2703(const string& line, const string& cryptoLine);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore(1, '\n');

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        string cryptoLine;
        getline(cin, cryptoLine);

        problem2703(line, cryptoLine);
    }

    return 0;
}

void problem2703(const string& line, const string& cryptoLine) {
    map<char, char> cryptoMap;
    cryptoMap[' '] = ' ';  // space char는 암호화하지 않음.

    char destCh = 'A';
    for (char ch : cryptoLine) {
        cryptoMap[destCh] = ch;
        destCh++;
    }

    for (char ch : line) {
        cout << cryptoMap[ch];
    }
    cout << "\n";
}
