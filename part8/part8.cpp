#include <iostream>
#include <vector>
#include <climits>
#include <cfloat>
#include <windows.h>

using namespace std;

// Функция для ввода массива
vector<double> inputArray(const string& name) {
    int n;
    cout << "Введите размер массива " << name << ": ";
    cin >> n;
    vector<double> arr(n);
    cout << "Введите элементы массива " << name << " через пробел: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}

// ============ Задача 3 ============
// Функция для одного массива: возвращает номер последнего минимального элемента (1-индексация)
int getLastMinPosition(const vector<double>& arr) {
    if (arr.empty()) return -1;

    // Находим минимальный элемент
    double minVal = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }

    // Находим последнее вхождение минимального элемента
    int lastPos = arr.size();
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (arr[i] == minVal) {
            lastPos = i + 1; // +1 для 1-индексации
            break;
        }
    }

    return lastPos;
}

// Основная функция для задачи 3
string solveTask3(const vector<double>& A, const vector<double>& B, const vector<double>& C) {
    int posA = getLastMinPosition(A);
    int posB = getLastMinPosition(B);
    int posC = getLastMinPosition(C);

    // Находим массив с наибольшим номером минимального элемента
    int maxPos = -1;
    string result = " ";

    if (posA > maxPos) {
        maxPos = posA;
        result = "A";
    }
    if (posB > maxPos) {
        maxPos = posB;
        result = "B";
    }
    if (posC > maxPos) {
        maxPos = posC;
        result = "C";
    }

    return result;
}

// ============ Задача 4 ============
// Функция для одного массива: возвращает сумму квадратов элементов <= limit
double sumSquaresNotExceeding(const vector<double>& arr, double limit) {
    double sum = 0.0;
    for (double val : arr) {
        if (val <= limit) {
            sum += val * val;
        }
    }
    return sum;
}

// Основная функция для задачи 4
string solveTask4(const vector<double>& A, const vector<double>& B, const vector<double>& C, double limit) {
    double sumA = sumSquaresNotExceeding(A, limit);
    double sumB = sumSquaresNotExceeding(B, limit);
    double sumC = sumSquaresNotExceeding(C, limit);

    // Находим массив с наименьшей суммой
    double minSum = DBL_MAX;
    string result = " ";

    if (sumA < minSum) {
        minSum = sumA;
        result = "A";
    }
    if (sumB < minSum) {
        minSum = sumB;
        result = "B";
    }
    if (sumC < minSum) {
        minSum = sumC;
        result = "C";
    }

    return result;
}

// ============ Задача 5 ============
// Функция для одного массива: возвращает сумму элементов в интервале [left, right]
double sumInInterval(const vector<double>& arr, double left, double right) {
    double sum = 0.0;
    for (double val : arr) {
        if (val >= left && val <= right) {
            sum += val;
        }
    }
    return sum;
}

// Основная функция для задачи 5
string solveTask5(const vector<double>& A, const vector<double>& B, const vector<double>& C,
    double left, double right) {
    double sumA = sumInInterval(A, left, right);
    double sumB = sumInInterval(B, left, right);
    double sumC = sumInInterval(C, left, right);

    // Находим массив с наибольшей суммой
    double maxSum = -DBL_MAX;
    string result = " ";

    if (sumA > maxSum) {
        maxSum = sumA;
        result = "A";
    }
    if (sumB > maxSum) {
        maxSum = sumB;
        result = "B";
    }
    if (sumC > maxSum) {
        maxSum = sumC;
        result = "C";
    }

    return result;
}

// ============ Задача 6 ============
// Функция для одного массива: возвращает среднее арифметическое отрицательных элементов
double averageNegative(const vector<double>& arr) {
    double sum = 0.0;
    int count = 0;

    for (double val : arr) {
        if (val < 0) {
            sum += val;
            count++;
        }
    }

    if (count == 0) return 0.0; // Если нет отрицательных элементов
    return sum / count;
}

// Основная функция для задачи 6
string solveTask6(const vector<double>& A, const vector<double>& B, const vector<double>& C) {
    double avgA = averageNegative(A);
    double avgB = averageNegative(B);
    double avgC = averageNegative(C);

    // Находим массив с наибольшим средним арифметическим отрицательных элементов
    double maxAvg = -DBL_MAX;
    string result = " ";

    // Проверяем, есть ли отрицательные элементы в массивах
    bool hasNegA = false, hasNegB = false, hasNegC = false;
    for (double val : A) if (val < 0) hasNegA = true;
    for (double val : B) if (val < 0) hasNegB = true;
    for (double val : C) if (val < 0) hasNegC = true;

    if (hasNegA && avgA > maxAvg) {
        maxAvg = avgA;
        result = "A";
    }
    if (hasNegB && avgB > maxAvg) {
        maxAvg = avgB;
        result = "B";
    }
    if (hasNegC && avgC > maxAvg) {
        maxAvg = avgC;
        result = "C";
    }

    return result;
}

// ============ Задача 7 ============
// Функция для одного массива: возвращает произведение ненулевых элементов
double productNonZero(const vector<double>& arr) {
    double product = 1.0;
    bool hasNonZero = false;

    for (double val : arr) {
        if (val != 0.0) {
            product *= val;
            hasNonZero = true;
        }
    }

    if (!hasNonZero) return 0.0; // Если все элементы нулевые
    return product;
}

// Основная функция для задачи 7
string solveTask7(const vector<double>& A, const vector<double>& B, const vector<double>& C) {
    double prodA = productNonZero(A);
    double prodB = productNonZero(B);
    double prodC = productNonZero(C);

    // Находим массив с наибольшим произведением ненулевых элементов
    double maxProd = -DBL_MAX;
    string result = " ";

    // Проверяем, есть ли ненулевые элементы в массивах
    bool hasNonZeroA = false, hasNonZeroB = false, hasNonZeroC = false;
    for (double val : A) if (val != 0.0) hasNonZeroA = true;
    for (double val : B) if (val != 0.0) hasNonZeroB = true;
    for (double val : C) if (val != 0.0) hasNonZeroC = true;

    if (hasNonZeroA && prodA > maxProd) {
        maxProd = prodA;
        result = "A";
    }
    if (hasNonZeroB && prodB > maxProd) {
        maxProd = prodB;
        result = "B";
    }
    if (hasNonZeroC && prodC > maxProd) {
        maxProd = prodC;
        result = "C";
    }

    return result;
}

// ============ Дополнительная функция для вывода массива ============
void printArray(const vector<double>& arr, const string& name) {
    cout << name << " = [";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // Ввод трех массивов
    cout << "=== Ввод массива A ===" << endl;
    vector<double> A = inputArray("A");

    cout << "\n=== Ввод массива B ===" << endl;
    vector<double> B = inputArray("B");

    cout << "\n=== Ввод массива C ===" << endl;
    vector<double> C = inputArray("C");

    // Вывод введенных массивов
    cout << "\n=== Введенные массивы ===" << endl;
    printArray(A, "A");
    printArray(B, "B");
    printArray(C, "C");

    // ========== Задача 3 ==========
    cout << "\n=== Задача 3 ===" << endl;
    cout << "Какой из массивов имеет наибольший номер минимального элемента?" << endl;
    string result3 = solveTask3(A, B, C);
    if (result3 != " ") {
        cout << "Ответ: массив " << result3 << endl;

        // Дополнительная информация
        int posA = getLastMinPosition(A);
        int posB = getLastMinPosition(B);
        int posC = getLastMinPosition(C);
        cout << "  Позиции последних минимальных элементов: A=" << posA
            << ", B=" << posB << ", C=" << posC << endl;
    }
    else {
        cout << "Все массивы пусты" << endl;
    }

    // ========== Задача 4 ==========
    double limit;
    cout << "\n=== Задача 4 ===" << endl;
    cout << "Какой из массивов имеет наименьшую сумму квадратов элементов, не превышающих заданного числа?" << endl;
    cout << "Введите заданное число: ";
    cin >> limit;

    string result4 = solveTask4(A, B, C, limit);
    if (result4 != " ") {
        cout << "Ответ: массив " << result4 << endl;

        // Дополнительная информация
        double sumA = sumSquaresNotExceeding(A, limit);
        double sumB = sumSquaresNotExceeding(B, limit);
        double sumC = sumSquaresNotExceeding(C, limit);
        cout << "  Суммы квадратов: A=" << sumA << ", B=" << sumB << ", C=" << sumC << endl;
    }
    else {
        cout << "Все массивы пусты" << endl;
    }

    // ========== Задача 5 ==========
    double left, right;
    cout << "\n=== Задача 5 ===" << endl;
    cout << "Какой из массивов имеет наибольшую сумму элементов, лежащих в заданном интервале?" << endl;
    cout << "Введите левую границу интервала: ";
    cin >> left;
    cout << "Введите правую границу интервала: ";
    cin >> right;

    string result5 = solveTask5(A, B, C, left, right);
    if (result5 != " ") {
        cout << "Ответ: массив " << result5 << endl;

        // Дополнительная информация
        double sumA = sumInInterval(A, left, right);
        double sumB = sumInInterval(B, left, right);
        double sumC = sumInInterval(C, left, right);
        cout << "  Суммы в интервале: A=" << sumA << ", B=" << sumB << ", C=" << sumC << endl;
    }
    else {
        cout << "Все массивы пусты" << endl;
    }

    // ========== Задача 6 ==========
    cout << "\n=== Задача 6 ===" << endl;
    cout << "Какой из массивов имеет наибольшее среднее арифметическое отрицательных элементов?" << endl;

    string result6 = solveTask6(A, B, C);
    if (result6 != " ") {
        cout << "Ответ: массив " << result6 << endl;

        // Дополнительная информация
        double avgA = averageNegative(A);
        double avgB = averageNegative(B);
        double avgC = averageNegative(C);
        cout << "  Средние арифметические отрицательных элементов: A=" << avgA
            << ", B=" << avgB << ", C=" << avgC << endl;
    }
    else {
        cout << "Нет отрицательных элементов ни в одном массиве" << endl;
    }

    // ========== Задача 7 ==========
    cout << "\n=== Задача 7 ===" << endl;
    cout << "Какой из массивов имеет наибольшее произведение ненулевых элементов?" << endl;

    string result7 = solveTask7(A, B, C);
    if (result7 != " ") {
        cout << "Ответ: массив " << result7 << endl;

        // Дополнительная информация
        double prodA = productNonZero(A);
        double prodB = productNonZero(B);
        double prodC = productNonZero(C);
        cout << "  Произведения ненулевых элементов: A=" << prodA
            << ", B=" << prodB << ", C=" << prodC << endl;
    }
    else {
        cout << "Все элементы во всех массивах нулевые" << endl;
    }

    return 0;
}