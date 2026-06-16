// ConsoleApplication5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<vector>
#include <windows.h>

using namespace std;

//Структура для представления информации о студенте

struct Student {
	string group;
	string name;
	string surname;
	string patronymic;
	int birthYear;
	string gender;
	int physicsScore;
	int mathematicsScore;
	int informaticsScore;
	int stipend;//в копейках



	Student(string _group,
		string _name,
		string _surname,
		string _patronymic,
		int _birthYear,
		string _gender,
		int _physicsScore,
		int _mathematicsScore,
		int _informaticsScore,
		int _stipend) {
		name = _name;
		surname = _surname;
		patronymic = _patronymic;
		birthYear = _birthYear;
		gender = _gender;
		physicsScore = _physicsScore;
		mathematicsScore = _mathematicsScore;
		informaticsScore = _informaticsScore;
		stipend = _stipend;
		group = _group;

	}
	void printStudent() const {
		cout << "Группа:" << group << endl;
		cout << "Фамилия:" << surname << endl;
		cout << "Имя:" << name << endl;
		cout << "Отчество:" << patronymic << endl;
		cout << "Год рождения:" << birthYear << endl;
		cout << "Пол:" << gender << endl;
		cout << "Оценка по физике:" << physicsScore << endl;
		cout << "Оценка по математике:" << mathematicsScore << endl;
		cout << "Оценка по информатике:" << informaticsScore << endl;
		cout << "Стипендия:" << stipend / 100.0 << endl;
	};

	float calcAverageScore() const {
		return (mathematicsScore + physicsScore + informaticsScore) / 3.0f;

	}

	int calcSkippedExams() const {
		int c = 0;
		if (informaticsScore == 0)c++;
		if (mathematicsScore == 0)c++;
		if (physicsScore == 0)c++;
		return c;
	}

	bool checkPositiveScore() const {
		return (mathematicsScore >= 3 && physicsScore >= 3 && informaticsScore >= 3);
	}

	int calcPositiveScore() const {
		return (mathematicsScore >= 3 ? 1 : 0) + (physicsScore >= 3 ? 1 : 0) + (informaticsScore >= 3 ? 1 : 0);
	}

	int calcNegativeScore() const {
		return (mathematicsScore >= 3 ? 0 : 1) + (physicsScore >= 3 ? 0 : 1) + (informaticsScore >= 3 ? 0 : 1);
	}


	string getincials() const {
		string inicial = name.substr(0, 1);
		inicial = inicial + ". ";
		inicial = inicial + patronymic.substr(0, 1);
		inicial = inicial + ". ";
		return inicial;
	}
	int calcAge(int currentyear = 2026) const {
		return (currentyear - birthYear);
	}
};

int main() {

	SetConsoleOutputCP(1251);
	SetConsoleCP(CP_UTF8);

	//вектор студентов
	vector<Student>students = {
		Student("Фуа-202б", "Иван", "Иванов", "Иванович", 2008, "мужской", 4, 5, 5, 0),
		Student("Фуа-202б", "Марина", "Иванова", "Александровна", 2008, "женский", 4, 5, 4, 900),
		Student("Фуа-202б", "Вероника", "Степанова", "Александровна", 2007, "женский", 4, 5, 4, 900),
		Student("Фуа-202б", "Ирина", "Тухваттулина", "Александровна", 2008, "женский", 4, 5, 4, 900),
		Student("Фуа-202б", "Наталья", "Богатырева", "Александровна", 2007, "женский", 5, 4, 4, 0),
		Student("Фуа-202б", "Анастасия", "Цветкова", "Александровна", 2007, "женский", 4, 5, 4, 300),
		Student("Фуа-202б", "Аркадий", "Тарасов", "Иванович", 2008, "мужской", 0, 0, 0, 0),
		Student("Фуа-202б", "Самира", "Ханова", "Александровна", 2007, "женский", 4, 5, 4, 300),
		Student("Фуа-202б", "Софья", "Ипполитова", "Ивановна", 2008, "женский", 0, 0, 0, 0)

	};
	cout << "*** Список студентов:***" << endl;
	for (auto& s : students) {
		s.printStudent();
		cout << endl;


	}
	cout << "***" << endl;
	cout << "Задача 9" << endl;
	for (auto& s : students) {
		if (s.informaticsScore == 5) {
			cout << "Фамилия:" << s.surname << endl;
			cout << "Средний балл:" << s.calcAverageScore() << endl;
		}
		cout << endl;
	}
	cout << "Задача 10:" << endl;
	for (auto& s : students) {
		if (s.checkPositiveScore() && s.stipend == 0) {
			cout << "Фамилия:" << s.surname << endl;
		}
	}
	cout << endl;
	cout << "Задача 11:" << endl;
	for (auto& s : students) {
		if (s.stipend == 0) {
			cout << "Фамилия:" << s.surname << endl;
			cout << "Имя:" << s.name << endl;
			cout << "Отчество:" << s.patronymic << endl;
			cout << "Средний балл:" << s.calcAverageScore() << endl;
			cout << endl;
		}
	}
	cout << endl;
	cout << "Задача 12:" << endl;
	int S = 0;
	for (auto& s : students) {
		S = S + s.stipend;
	}
	float Averagestipend = 1.0f * S / (students.size());
	cout << "Средняя стипендия равна:" << Averagestipend << endl;
	for (auto& s : students) {
		if (s.stipend < Averagestipend) {
			if ((s.stipend / Averagestipend) * 100 < 80) {
				cout << "Фамилия:" << s.surname << endl;
				cout << "Имя:" << s.name << endl;
				cout << "Отчество:" << s.patronymic << endl;
				cout << endl;
			}
		}
	}
	cout << endl;
	cout << "Задача 13:" << endl;
	for (auto& s : students) {
		if (s.calcSkippedExams() > 2) {
			cout << s.surname << " " << s.getincials() << endl;

		}
	}

	cout << endl;
	cout << "Задача 14:" << endl;
	float M = 0;

	for (auto& s : students) {
		M = M + s.calcAverageScore();
	}
	float AverageScore = 1.0f * M / (students.size());
	cout << "Средний балл:" << AverageScore << endl;

	for (auto& s : students) {
		if (s.calcAverageScore() > AverageScore) {
			cout << "Фамилия:" << s.surname << endl;
			cout << "Имя:" << s.name << endl;
		}
	}

	cout << endl;
	cout << "Задача 16:" << endl;
	string groupname = "Фуа-202б";
	for (auto& s : students) {
		if (s.gender == "мужской" && s.calcAge() > 18) {
			cout << "Фамилия:" << s.surname << endl;
		}
	}

	cout << endl;
	cout << "Задача 15:" << endl;
	for (auto& s : students) {
		if (s.checkPositiveScore() && s.stipend != 0) {
			cout << "Фамилия:" << s.surname << endl;
			cout << "Имя:" << s.name << endl;
			cout << "Отчество:" << s.patronymic << endl;
			cout << "Стипендия:" << s.stipend / 100.0 << endl;
		}
	}

	cout << endl;
	cout << "Задача 17:" << endl;
	for (auto& s : students) {
		if (s.calcNegativeScore() >= 3) {
			cout << "Фамилия:" << s.surname << endl;
			cout << "Имя:" << s.name << endl;
			cout << "Отчество:" << s.patronymic << endl;
		}
	}


	cout << endl;
	cout << "Задача 18:" << endl;
	for (auto& s : students) {
		if (s.physicsScore == 5 && s.group == "Фуа-202б") {
			s.stipend += 100;//увеличение стипендии на 100
			cout << "Фамилия:" << s.surname << endl;
			cout << "Имя:" << s.name << endl;
			cout << "Отчество:" << s.patronymic << endl;
			cout << "Оценка по математике:" << s.mathematicsScore << endl;
			cout << "Оценка по информатике:" << s.informaticsScore << endl;
			cout << "Стипендия:" << s.stipend / 100.0 << endl;
			cout << "Год рождения:" << s.birthYear << endl;
			
		}
	}
	return 0;
}










