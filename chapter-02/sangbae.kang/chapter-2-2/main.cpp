#include <iostream>
#include <cmath>

double f(double x);
void integral(double a, double b, int n);
void integralBySimpson(double a, double b, int n);
void integralByCentral(double a, double b, int n);

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // integral(0, 2, 50);
    // integralBySimpson(0, 2, 50);
    integralByCentral(0, 2, 50);
    return 0;
}

double f(double x) {
    return sqrt(4 - pow(x, 2));
}

// 사다리꼴
void integral(double a, double b, int n) {
    double h = (b - a) / n;
    double x = a;
    double sum = 0.0;

    for (int i = 1; i < n; i++) {
        x += h;
        sum += f(x);
    }
    sum = h * ((f(a) + f(b)) / 2 + sum);

    cout.precision(11);
    cout << "integral: " << sum << "\n";
}

// 심슨규칙
void integralBySimpson(double a, double b, int n) {
    double h = (b - a) / (2 * n);
    double fo = 0;
    double fe = 0;

    for (int i = 1; i <= 2 * n - 3; i += 2) {
        fo += f(a + h * i);
        fe += f(a + h * (i + 1));
    }

    double sum = (f(a) + f(b) + 4 * (fo + f(b -h)) + 2 * fe) * h / 3;
    cout.precision(7);
    cout << "integral: " << sum << "\n";
}

// 중점법
void integralByCentral(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += f(a + h * (2 * i - 1) / 2);
    }

    sum *= h;
    cout.precision(7);
    cout << "integral: " << sum << "\n";
}
