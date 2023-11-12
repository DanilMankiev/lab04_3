#pragma once

class MyString
{
private:
	char* m_pStr;		// Ёлемент данных класса (адрес строки)
public:
	MyString();
	MyString(const char* s);
	MyString(char* s);	// ќбъ€вление конструктора
	MyString(const MyString& tmp);
	~MyString();		// ќбъ€вление деструктора

	void Copy(char* s);
	char* GetString();	// ќбъ€вление метода (accessor)
	int GetLength();	// ќбъ€вление метода (длина строки)

	MyString& operator=(const MyString& tmp);
	bool operator==(const MyString& tmp);

};
