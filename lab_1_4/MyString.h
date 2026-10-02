#pragma once
#include <string>

class MyString
{
private:
	std::string str;
public:
	MyString();

	std::string GetStr() const { return str; }
	void SetStr(const std::string& value);

	bool Init(const std::string& value);
	void Read();
	void Display() const;
	std::string toString() const;

	void Assign(const MyString& other); // Присвоєння
	MyString Concat(const MyString& other) const; // Конкатенація
	int Compare(const MyString& other) const; // Порівняння

	int ToInt() const; // Перетворення рядка в int
	double ToDouble() const; // Перетворення рядка в double 

	void FromInt(int value); // Перетворення int у рядок
	void FromDouble(double value); // Перетворення double у рядок

	void FormattedDisplay(int width, bool leftAlign) const;

};

