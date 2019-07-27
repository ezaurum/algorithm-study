#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& intValues);
void shakerSort(vector<int>& intValues);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> values{ 80, 41, 35, 90, 40, 20};
//    bubbleSort(values);
    shakerSort(values);

    return 0;
}

void echoValues(const vector<int>& intValues) {
    for (auto val : intValues) {
        cout << val << ", ";
    }
    cout << "\n";
}

void bubbleSort(vector<int>& intValues) {
    int size = intValues.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = size - 1; j > i; j--) {
            if (intValues[j] < intValues[j - 1]) {
                swap(intValues[j], intValues[j - 1]);
            }
        }
    }
    echoValues(intValues);
}

void shakerSort(vector<int>& intValues) {
    int left = 0;
    int right = static_cast<int>(intValues.size()) - 1;
    int shift = left; // 소팅된 배열이면 shift가 초기화 안 될 수 있음.

    while (left < right) {
        for (int i = left; i < right; i++) {
            if (intValues[i] > intValues[i + 1]) {
                swap(intValues[i], intValues[i + 1]);
                shift = i;
            }
        }
        right = shift;
        for (int i = right; i > left; i--) {
            if (intValues[i] < intValues[i - 1]) {
                swap(intValues[i], intValues[i - 1]);
                shift = i;
            }
        }
        left = shift;
    }
    echoValues(intValues);
}
