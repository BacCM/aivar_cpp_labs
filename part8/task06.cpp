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

// Решение задачи 6
string solveTask6(const vector<double>& A, const vector<double>& B, const vector<double>& C) {
	string result = " ";
	double maxAvg = -DBL_MAX;

	// Массив A
	double sumA = 0.0;
	int countA = 0;
	for (double val : A) {
		if (val < 0) {
			sumA += val;
			countA++;
		}
	}
	if (countA > 0) {
		double avgA = sumA / countA;
		if (avgA > maxAvg) {
			maxAvg = avgA;
			result = "A";
		}
	}

	// Массив B
	double sumB = 0.0;
	int countB = 0;
	for (double val : B) {
		if (val < 0) {
			sumB += val;
			countB++;
		}
	}
	if (countB > 0) {
		double avgB = sumB / countB;
		if (avgB > maxAvg) {
			maxAvg = avgB;
			result = "B";
		}
	}

	// Массив C
	double sumC = 0.0;
	int countC = 0;
	for (double val : C) {
		if (val < 0) {
			sumC += val;
			countC++;
		}
	}
	if (countC > 0) {
		double avgC = sumC / countC;
		if (avgC > maxAvg) {
			maxAvg = avgC;
			result = "C";
		}
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

	string result = solveTask6(A, B, C);
	cout << "Ответ: массив " << result << endl;

	return 0;
}