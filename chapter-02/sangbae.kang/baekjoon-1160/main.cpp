#include <iostream>

using namespace std;

int64_t problem1160(int64_t m, int64_t a, int64_t c, int64_t x0, int64_t i, int g);
void makeHistogram(int maxN);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

//    int64_t m, a, c, x0, n, g;
//    cin >> m;
//    cin >> a;
//    cin >> c;
//    cin >> x0;
//    cin >> n;
//    cin >> g;
//
//    int64_t xn = problem1160(m, a, c, x0, n, g);
//    cout << xn % g << "\n";

    makeHistogram(1000);
    return 0;
}

//
int64_t problem1160(int64_t m, int64_t a, int64_t c, int64_t x0, int64_t n, int g) {
    int64_t xVal = x0;
    int64_t modN = (n % m);

    for (int64_t i = 1; i <= modN; i++) {
        xVal = (a * xVal + c) % m;
        // cout << i << ": " << xVal << "\n";
    }
    return xVal;
}


int xn = 13;
int64_t random() {
    xn = (109 * xn + 1021) % 32768;
    return xn;
}

int histogram[10];

void makeHistogram(int maxN) {
    fill_n(histogram, 10, 0);

    for (int i = 0; i < maxN; i++) {
        int64_t num = random();
        int index = (num * 10) / 32768;
        histogram[index]++;
    }

    double x2 = 0;
    for (int i = 0; i < 10; i++) {
        x2 += static_cast<double > (histogram[i] - 100) * (histogram[i] - 100) / 100;
        cout << i + 1 << ": " << histogram[i] << "\n";
    }
    cout << "x2: " << x2 << "\n";
}

