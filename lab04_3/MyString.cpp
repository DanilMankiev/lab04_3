#include <iostream>
#include "MyString.h"
using namespace std;

void MyString::Copy(char* s)
{
	delete[] m_pStr;
	// Динамически выделяем требуемое количество памяти.
	int len = strlen(s) + 1;
	m_pStr = new char[len];
	// + 1, так как нулевой байт тоже нужно скопировать
	// Если память выделена, копируем строку-аргумент в строку-член класса
	if (m_pStr)
		strcpy_s(m_pStr, len, s);
}

// Определение конструктора.
MyString::MyString(char* s)
{
	m_pStr = 0;
	Copy(s);
}
MyString::MyString()
{
	m_pStr = new char[1];
	strcpy_s(m_pStr, 1, "");

}
MyString::MyString(const char* s)
{
	m_pStr = new char[strlen(s) + 1];
	strcpy_s(m_pStr, strlen(s) + 1, s);
}

MyString::MyString(const MyString& tmp)
{
	m_pStr = 0;
	Copy(tmp.m_pStr);
}
// Определение деструктора.
MyString::~MyString()
{
	// Освобождение памяти, занятой в конструкторе для строки-члена класса
	delete[] m_pStr;
}


// Метод класса
char* MyString::GetString()
{
	return m_pStr;
}

int MyString::GetLength()
{
	return strlen(m_pStr) + 1;
}

MyString& MyString::operator=(const MyString& tmp)
{
	if (*this == tmp) {
		return *this;
	}
	else {
		m_pStr = new char[strlen(tmp.m_pStr) + 1];
		strcpy_s(m_pStr, strlen(tmp.m_pStr) + 1, tmp.m_pStr);
	}
}

bool MyString::operator==(const MyString& tmp)
{
	return m_pStr == tmp.m_pStr;
}
