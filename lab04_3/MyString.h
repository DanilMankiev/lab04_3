#pragma once

class MyString
{
private:
	char* m_pStr;		// ������� ������ ������ (����� ������)
public:
	MyString();
	MyString(const char* s);
	MyString(char* s);	// ���������� ������������
	MyString(const MyString& tmp);
	~MyString();		// ���������� �����������

	void Copy(char* s);
	char* GetString();	// ���������� ������ (accessor)
	int GetLength();	// ���������� ������ (����� ������)

	MyString& operator=(const MyString& tmp);
	bool operator==(const MyString& tmp);

};
