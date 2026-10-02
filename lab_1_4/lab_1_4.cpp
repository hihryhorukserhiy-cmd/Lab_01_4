#include <iostream>
#include <Windows.h>
#include "MyString.h"

using namespace std;

MyString makeMyString(const string& val)
{
	MyString s;
	s.Init(val);
	return s;
}

void ShowMenu()
{
	cout << "\n========== МЕНЮ ============\n";
	cout << "1. Ввести поточний рядок (Read) \n";
	cout << "2. Вивести поточний рядок (Display)\n";
	cout << "3. Присвоєння рядка (Assign)\n";
	cout << "4. Конкатенація рядків (Concat)\n";
	cout << "5. Порівняти рядки (Compare)\n";
	cout << "6. Отримати число з рядка (ToInt / ToDouble)\n";
	cout << "7. Записати число в рядок (FromInt / FromDouble)\n";
	cout << "8. Форматний вивід (FormattedDisplay)\n";
	cout << "9. Демонстрація покажчика (->) та масиву об'єктів\n";
	cout << "0. Вихід\n";
	cout << "Ваш вибір: ";
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	MyString current = makeMyString("Початковий рядок");
	int choice;

	do
	{
		ShowMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			current.Read();
			break;
		case 2:
			cout << "Поточний рядок: ";
			current.Display();
			break;
		case 3:
		{
			MyString temp;
			temp.Read();
			current.Assign(temp);
			cout << "Після присвоєння: ";
			current.Display();
			break;
		}
		case 4:
		{
			MyString second;
			second.Read();
			MyString res = current.Concat(second);
			cout << "Результат конкатенації: ";
			res.Display();
			break;
		}
		case 5:
		{
			MyString second;
			second.Read();
			int cmp = current.Compare(second);
			if (cmp == 0) cout << "Рядки ідентичні (0). \n";
			else if (cmp < 0) cout << "Поточний рядок менший (-1). \n";
			else cout << "Поточний рядок більший (1). \n";
			break;
		}
		case 6:
		{
			cout << "Ціле значення (ToInt): " << current.ToInt() << endl;
			cout << "Дійсне значення (ToDouble): " << current.ToDouble() << endl;
			break;
		}
		case 7:
		{
			int t;
			cout << "1 - ціле, 2 - дійсне: ";
			cin >> t;
			if (t == 1)
			{
				int val;
				cout << "Введіть ціле число: "; cin >> val;
				current.FromInt(val);
			}
			else
			{
				double val;
				cout << "Введіть дійсне число: "; cin >> val;
				current.FromDouble(val);
			}
			cout << "Оновлений рядок: ";
			current.Display();
			break;
		}
		case 8:
			cout << "Вирівнювання по лівому краю (ширина 25):\n";
			current.FormattedDisplay(25, true);
			cout << "Вирівнювання по правому краю (ширина 25):\n";
			current.FormattedDisplay(25, false);
			break;
		case 9:
		{
			cout << "\n---Демонстрація покажчика на об'єкт (->) ---\n";
			MyString* ptr = new MyString();
			ptr->Init("Динамічний рядок через вказівник");
			cout << "Значення: ";
			ptr->Display();
			delete ptr;

			cout << "\n--- Демонстрація динамічного масиву об'єктів ---\n";
			int n = 3;
			MyString* arr = new MyString[n];
			arr[0].Init("Рядок Alpha");
			arr[1].Init("Рядок Beta");
			arr[2].Init("Рядок Gamma");

			for (int i = 0; i < n; i++)
			{
				cout << "arr[" << i << "] = ";
				arr[i].Display();
			}
			delete[] arr;
			break;
		}

		case 0:
			cout << "Програму завершено. \n";
			break;
		default:
			cout << "Невірний пункт меню!\n";

		}
	} while (choice != 0);
		return 0;
	}