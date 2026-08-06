#include <iostream>
#include <vector>
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

// Решение задачи 3
string solveTask3(const vector<double>& A, const vector<double>& B, const vector<double>& C) {
	string result = " ";
	int maxPos = -1;

	// Массив A
	if (!A.empty()) {
		double minVal = A[0];
		for (size_t i = 1; i < A.size(); i++) {
			if (A[i] < minVal) minVal = A[i];
		}
		int lastPos = A.size();
		for (int i = A.size() - 1; i >= 0; i--) {
			if (A[i] == minVal) {
				lastPos = i + 1;
				break;
			}
		}
		if (lastPos > maxPos) {
			maxPos = lastPos;
			result = "A";
		}
	}

	// Массив B
	if (!B.empty()) {
		double minVal = B[0];
		for (size_t i = 1; i < B.size(); i++) {
			if (B[i] < minVal) minVal = B[i];
		}
		int lastPos = B.size();
		for (int i = B.size() - 1; i >= 0; i--) {
			if (B[i] == minVal) {
				lastPos = i + 1;
				break;
			}
		}
		if (lastPos > maxPos) {
			maxPos = lastPos;
			result = "B";
		}
	}

	// Массив C
	if (!C.empty()) {
		double minVal = C[0];
		for (size_t i = 1; i < C.size(); i++) {
			if (C[i] < minVal) minVal = C[i];
		}
		int lastPos = C.size();
		for (int i = C.size() - 1; i >= 0; i--) {
			if (C[i] == minVal) {
				lastPos = i + 1;
				break;
			}
		}
		if (lastPos > maxPos) {
			maxPos = lastPos;
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

	string result = solveTask3(A, B, C);
	cout << "Ответ: массив " << result << endl;

	return 0;
}