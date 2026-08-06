#include <iostream>
#include <vector>
#include <cfloat>
#include <windows.h>

using namespace std;

// Функция для ввода массива
vector<double> inputArray(const string& name) {
	int n;
	cout << "Введите размер массива " << name << ": ";
	cin >> n;
	vector<double> arr(n);
	cout << "Введите элементы массива " << name << ": ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	return arr;
}

// Решение задачи 7
string solveTask7(const vector<double>& A, const vector<double>& B, const vector<double>& C) {
	string result = " ";
	double maxProd = -DBL_MAX;

	// Массив A
	double prodA = 1.0;
	bool hasNonZeroA = false;
	for (double val : A) {
		if (val != 0.0) {
			prodA *= val;
			hasNonZeroA = true;
		}
	}
	if (hasNonZeroA && prodA > maxProd) {
		maxProd = prodA;
		result = "A";
	}

	// Массив B
	double prodB = 1.0;
	bool hasNonZeroB = false;
	for (double val : B) {
		if (val != 0.0) {
			prodB *= val;
			hasNonZeroB = true;
		}
	}
	if (hasNonZeroB && prodB > maxProd) {
		maxProd = prodB;
		result = "B";
	}

	// Массив C
	double prodC = 1.0;
	bool hasNonZeroC = false;
	for (double val : C) {
		if (val != 0.0) {
			prodC *= val;
			hasNonZeroC = true;
		}
	}
	if (hasNonZeroC && prodC > maxProd) {
		maxProd = prodC;
		result = "C";
	}

	return result;
}

int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	vector<double> A = inputArray("A");
	vector<double> B = inputArray("B");
	vector<double> C = inputArray("C");

	string result = solveTask7(A, B, C);
	cout << "Ответ: массив " << result << endl;

	return 0;
}