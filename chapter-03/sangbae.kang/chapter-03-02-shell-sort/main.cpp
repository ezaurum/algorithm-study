#include <iostream>
#include <vector>

using namespace std;

void shellSort(vector<int>& intValues);
void insertionSort(vector<int>& intValues);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> values{ 51, 60, 80, 30, 45, 70, 55, 21 };
//    shellSort(values);
    insertionSort(values);
    return 0;
}

void echoValues(const vector<int>& intValues) {

    for (int val: intValues) {
        cout << val << ", ";
    }
    cout << "\n";
}

void shellSort(vector<int>& intValues) {
    int gap = static_cast<int>(intValues.size()) / 2;
    int n = intValues.size();

    while (gap > 0) {
        for (int i = 0; i < gap; i++) {
            // gap만큼 떨어진 element를 처리.
            for (int j = i + gap; j < n; j += gap) {
                for (int k = j - gap; k >= i; k -= gap) {
                    if (intValues[k] > intValues[k + gap]) {
                        swap(intValues[k + gap],intValues[k]);
                    } else {
                        break;
                    }
                }
            }
        }
        gap /= 2;
    }
    echoValues(intValues);
}

void insertionSort(vector<int>& intValues) {
    int size = static_cast<int>(intValues.size());

    for (int i = 0; i < size; i++) {
        for (int j = i; j > 0; j--) {
            if (intValues[j] < intValues[j - 1]) {
                swap(intValues[j], intValues[j - 1]);
            } else {
                break;
            }
        }
    }
    echoValues(intValues);
}