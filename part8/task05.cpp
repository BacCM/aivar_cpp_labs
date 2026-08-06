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

// Решение задачи 5
string solveTask5(const vector<double>& A, const vector<double>& B, const vector<double>& C,
	double left, double right) {
	string result = " ";
	double maxSum = -DBL_MAX;

	// Массив A
	double sumA = 0.0;
	for (double val : A) {
		if (val >= left && val <= right) sumA += val;
	}
	if (sumA > maxSum) {
		maxSum = sumA;
		result = "A";
	}

	// Массив B
	double sumB = 0.0;
	for (double val : B) {
		if (val >= left && val <= right) sumB += val;
	}
	if (sumB > maxSum) {
		maxSum = sumB;
		result = "B";
	}

	// Массив C
	double sumC = 0.0;
	for (double val : C) {
		if (val >= left && val <= right) sumC += val;
	}
	if (sumC > maxSum) {
		maxSum = sumC;
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

	double left, right;
	cout << "Введите левую границу интервала: ";
	cin >> left;
	cout << "Введите правую границу интервала: ";
	cin >> right;

	string result = solveTask5(A, B, C, left, right);
	cout << "Ответ: массив " << result << endl;

	return 0;
}