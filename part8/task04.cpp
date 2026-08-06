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

// Решение задачи 4
string solveTask4(const vector<double>& A, const vector<double>& B, const vector<double>& C, double limit) {
	string result = " ";
	double minSum = DBL_MAX;

	// Массив A
	double sumA = 0.0;
	for (double val : A) {
		if (val <= limit) sumA += val * val;
	}
	if (sumA < minSum) {
		minSum = sumA;
		result = "A";
	}

	// Массив B
	double sumB = 0.0;
	for (double val : B) {
		if (val <= limit) sumB += val * val;
	}
	if (sumB < minSum) {
		minSum = sumB;
		result = "B";
	}

	// Массив C
	double sumC = 0.0;
	for (double val : C) {
		if (val <= limit) sumC += val * val;
	}
	if (sumC < minSum) {
		minSum = sumC;
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

	double limit;
	cout << "Введите заданное число: ";
	cin >> limit;

	string result = solveTask4(A, B, C, limit);
	cout << "Ответ: массив " << result << endl;

	return 0;
}