#include <iostream>
#include <cmath>


using namespace std;

double myexp(double x, double s, double e, double d, int k);
double mycosine(double x, double s, double e, double d, int k);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(11);

    cout << "myexp.\n";
    for (int x = -40; x <= 40; x += 10) {
        cout << x << " - " << myexp(x, 1.0, 1.0, 1.0, 1) << "\n";
    }

    cout << "mycousine.\n";
    double rd = 3.14159 / 180;
    for (int x = 0; x <= 180; x += 10) {
        double newx = fmod(x * rd, 2 * 3.1415);
        cout << x << " - " << mycosine(newx, 1.0, 1.0, 1.0, 1) << "\n";
    }
    return 0;
}

#define EPS 0.00000001

// recursive
double myexp(double x, double s, double e, double d, int k) {
    if (k == 200) {
        return 0.0;
    } else {
        double newE = e * (x / k);
        double newS = s + newE;
        if (fabs(newS - d) < EPS * fabs(d)) {
            if (x > 0) {
                return newS;
            } else {
                return 1.0 / newS;
            }
        }
        return myexp(x, newS, newE, s, k + 1);
    }
}

double mycosine(double x, double s, double e, double d, int k) {
    if (k == 200) {
        return 9999.0;
    } else {
        double newE = - e * x * x / (k * (k + 1));
        double newS = s + newE;
        if (fabs(newS - d) < EPS * fabs(d)) {
            return newS;
        }
        return mycosine(x, newS, newE, s, k + 2);
    }
}
