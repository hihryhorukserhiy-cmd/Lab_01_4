#include "MyString.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

MyString::MyString()
{
	str = "";
}

void MyString::SetStr(const std::string& value)
{
	str = value;
}

bool MyString::Init(const std::string& value)
{
	SetStr(value);
	return false;
}

void MyString::Read()
{
	string s;
	cout << "Введіть текст рядка: ";
	cin >> ws;
	getline(cin, s);
	Init(s);
}



string MyString::toString() const
{
	return str;
}



void MyString::Display() const
{
	cout << str << endl;
}

void MyString::Assign(const MyString& other)
{
	str = other.str;
}

MyString MyString::Concat(const MyString& other) const
{
	MyString res;
	res.Init(str + other.str);
	return res;
}

int MyString::Compare(const MyString& other) const
{
	if (str < other.str) return  -1;
	if (str < other.str) return 1;
	return 0;
}

int MyString::ToInt() const
{
	if (str.empty()) return 0;

	int result = 0;
	int sign = 1;
	size_t i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	else if (str[0] == '+')
	{
		i = 1;
	}

	for (; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
		}
		else
		{
			break;
		}
	}

	return result * sign;
}


double MyString::ToDouble() const
{
	if (str.empty()) return 0.0;

	double result = 0;
	double sign = 1;
	size_t i = 0;

	if (str[0] == '-')
	{
		sign = -1.0;
		i = 1;
	}
	else if (str[0] == '+')
	{
		i = 1;
	}

	// Ціла частина числа
	for (; i < str.length() && str[i] != '.' && str[i] != ','; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10.0 + (str[i] - '0');
		}
		else
		{
			return result * sign;
		}
	}

	// Дробова частина числа

	if (i < str.length() && (str[i] == '.' || str[i] == ','))
	{
		i++;
		double factor = 0.1;
		for (; str.length(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				result += (str[i] - '0') * factor;
				factor /= 10.0;
			}
			else
			{
				break;
			}
		}
	}
	
	return result * sign;
}

void MyString::FromInt(int value)
{
	str = to_string(value);
}

void MyString::FromDouble(double value)
{
	str = to_string(value);
}

void MyString::FormattedDisplay(int width, bool leftAlign) const
{
	if (leftAlign)
	{
		cout << "|" << left << setw(width) << str << "|\n";
	}
	else
	{
		cout << "|" << right << setw(width) << str << "|\n";
	}
}
