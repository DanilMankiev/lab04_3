// ���������� STL: 
//deque, stack, queue, priority_queue
//set, multiset, map, multimap
//���������. ����������� ���������. ���������.

#include <iostream>
#include<vector>
#include<deque>
#include<queue>
#include<array>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<stack>
#include"MyString.h"
#include"Point.h"

using namespace std;
#define	  stop __asm nop


template<typename T> void StackOut(stack<T> &stack) {
	while(!stack.empty()) {
		cout << stack.top() << endl;        // 1 ������
		stack.pop();
	}
	//auto a = stack._Get_container();
	//for (int i = 0; i < a.size(); ++i) {  // 2 ������
	//	cout << a[i] << endl;
	//}
}
template<typename T> void QueueOut(queue<T>& queue) {
	while (!queue.empty()) {
		cout << queue.front() << endl;
		queue.pop();
	}
}
template<typename T> void PqueueOut(priority_queue<T>& pqueue) {
	while (!pqueue.empty()) {
		cout << pqueue.top() << endl;
		pqueue.pop();
	}
}
bool Pred1_1(Point& point) {
	return (point.getX() > -10 && point.getX() < 50 && point.getY() > -10 && point.getY() < 50);
}
char fuch(char ch) {
	if (int(ch) <= 90 && int(ch) >= 65) { return ch + 32; }
	else return ch;
}
string Trans(string& str1) {
	string str2 = str1;
	transform(str1.begin(), str1.end(),str2.begin(), fuch);
	str1 = str2;
	return str1;
}


void func() {
	cout << "---------------" << endl;
}
int main()
{
	int i = 10;
	printf(" == %d", i);
	setlocale(LC_ALL, "Russian");
	
	//������� � ����� ������� - ��������� deque

	//�������� ������ deque � ���������� ���� Point. � �������
	//assign ��������� deque ������� ��������� �������. � �������
	//�������������� ���� � ���������� ������� �������������� �������
	//�������� �������� ��������� �� ������
	deque<Point> deq;
	vector<Point> vec = { Point(1,2),Point(1,3),Point(4,5) };
	deq.assign(begin(vec), end(vec));
	for_each(begin(deq), end(deq), [](auto it) {cout << it; });


	//�������� deque � ���������� ���� MyString. ��������� ��� ����������
	//� ������� push_back(), push_front(), insert()
	//� ������� erase ������� �� deque ��� ��������, � ������� �������
	//���������� � 'A' ��� 'a'
	deque<MyString> str;
	MyString mas[3] = { "Exeption","Assert","ambitious" };
	str.push_back(mas[0]);
	str.push_front(mas[1]);
	str.insert(begin(str) + 2, mas[2]);


	////////////////////////////////////////////////////////////////////////////////////


	//�������� ������ ������� ��� ������ �������� stack, queue, priority_queue
	//���������, ��� "��������" ������ "� ��������"?
	//��� ���������� � ������������ ����� ������ ��������?
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	queue<int> q({ 11,22,33 });
	priority_queue<int> pq;
	pq.push(1);
	pq.push(2);
	pq.push(3);
	StackOut<int>(s);
	func();
	QueueOut<int>(q);
	func();
	PqueueOut<int>(pq);
	func();

	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//�������� ���� ����� �������, �����
	//�) �������� ����� ����� ������� ��������� �������
	vector<int> vec1 = { 2,22,3,33 };
	stack<int> stack1;
	for (auto i : vec1) {
		stack1.push(i);
	}
	StackOut<int>(stack1);
	func();
	//�) ��� ������ �������� ��� �������, ��� � ����� ������� �������� ��� ���������� 
	stack<int> stack2;
	for_each(vec1.rbegin(), vec1.rend(), [&stack2](auto i) {stack2.push(i); });
	StackOut<int>(stack2);
	func();

	//��������� � ����������� ������

	//�) �������� ���� � ����� �������� ������� �������� ���������

	stack<int> stack3;
	stack3.push(10);
	stack3.push(20);
	stack3.push(30);
	//�) �������� ����� ���� ����� �������, ����� �� ���� ������ �������
	stack<int> stack4(stack3);
	//�) �������� ����� �� ���������
	cout << bool(stack4 == stack3) << endl;
	func();
	//�) ������������� ����� �� ������ ����� ������� (push, pop, top)
	stack4.top() = 40;
	//�) ���������, ����� �� ������ ������ (���������, ����� ����� ������������ � ����� ���������)
	{
		cout << bool(stack4 > stack3) << endl;
		func();
	}


	////////////////////////////////////////////////////////////////////////////////////
	//queue
	// 
	//�������� �������, ������� �������� ��������� �� ������� ���� Point,
	//��� ���� ���� ������� ������� ���������.
	//�������� �������� ������� � ���������� ��������� ����������� front() � back()
	//���������, ��� ��������� ������� ��� ����������� ����� �������?
	{
		queue<Point*, deque<Point*>> que;
		que.push(new Point(1, 1));
		que.push(new Point(4, 4));
		que.push(new Point(5, 5));
		que.front() = new Point(2, 2);
		que.back() = new Point(3, 3);
		while (!que.empty()) {
			delete que.front();
			que.pop();
		}
	}
	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//�) �������� ������� � ������������, ������� ����� ������� ������ ��������� ��������� - const char*

	//�) ������������������ ������� ��� �������� � ������� ���������������� ������� � ���������� const char*
	const char* mas1[] = { "hello", "world�bb","meanrr","bxxq","a" };
	priority_queue<const char*> pq1(mas1, mas1 + 5);
	func();
	//�) ��������� "���������������" �������� (� ������� pop() ) - ���� ��� ����������� �� ��������������, ���������:
	//		��� ������������ ��� �������?

	{
		PqueueOut(pq1);
		// �������� ����� ��������� � �������, ������������ �������� ������, �� ������� ��������� ���������. �� ���� 

	
	}


	////////////////////////////////////////////////////////////////////////////////////
	//set



	//a) �������� ��������� � ���������� ���� Point - ���������, ��� ���������� ����������
	//		� ������ Point (� ����� �������)

	set<Point> set1 = { Point(3,2), Point(9,9) };
	set1.insert(Point(1, 1));
	set1.insert(Point(10, 12));
	set1.insert(Point(3, 4));
	//�) ������������ �������� ��������� � ������� �������, �������������� � ���������� ���. ������

	for_each(set1.begin(), set1.end(), [](auto i) {cout << i << endl; });
	//�) ���������� �������� ����� ��������...
	// ������
	//�) �������� ��� ���������, ������� ����� ��������� ���������� ��������
	//		���� int, �� ���������� � ������ �������
	set<int> set2({ 1,67,45,12,34,3 });
	set<int> set3({ 67,45,1,3,12,34 });
	//����������
	//�) �������� � ����� ��������� �������� ��������� �� ������ �������
	//	����������, ��������, ��������� �������	(��� ����������, ���� � ������� ������� �����?)
	// ����� ������������
	array<int, 10> arr = { 1,21,3,3,21,5 };
	set2.insert(arr.begin(), arr.end());


	////////////////////////////////////////////////////////////////////////////////////
	//multiset




	////////////////////////////////////////////////////////////////////////////////////
	//map	
	//�) �������� map, ������� ������ ���� "�������, ��������" - pair<const char*, int>,
	//	��� ���� ������ �������� ���������� ����������
	map<const char*, int> map1;
	//�) ��������� ��������� ���������� ����������� operator[] � insert()
	map1.insert(pair<const char*, int>("Terence", 1000));
	map1.insert(make_pair("Killian", 1111));
	map1.emplace("Freyne", 6666);
	map1["Levandovsky"] = 2000;
	//�) ������������ ����������
	for (const auto& p : map1) {
		cout << "Surname: " << p.first << "\nSalary: " << p.second << endl;
	}

	//�) �������� ���� �� ������ �� ����� (���� "�������", ����� ����� => ����� "�������")
	auto it = map1.find("Terence");
	map1.emplace("Gutaro", (*it).second);
	map1.erase("Terence");
	cout << "After swap key" << endl;
	for (const auto& p : map1) {
		cout << "Surname: " << p.first << "\nSalary: " << p.second << endl;
	}


	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//�) �������� "�����-�������" �������, ��� ������ � ���� �� ����� ����� ���������������
	//		��������� ������� �������� - pair<string,string>, ��������: strange: �����, ��������...
	//�) ��������� ������� ������ � ������� ������ insert ��� ������������������ � ������� 
	//		���������������� ������� ���� (���� ����� �������������� ��� ��������� � ������� ������� make_pair)
	//�) �������� ��� ���������� ������� �� �����
	//�) �������� �� ����� ������ �������� "���������" ��� ��������� �����. ���������: ��� ���������� ���������
	//		���������� ����� ������������ ������ lower_bound() � upper_bound()
	multimap<string, string> dict;
	dict.insert(make_pair("light", "����"));
	dict.insert(make_pair("light", "������"));
	dict.insert(make_pair("light", "�����"));
	dict.emplace("strange", "�����");
	dict.insert(make_pair("light", "��������"));
	dict.emplace("strange", "��������");
	for (const auto& p : map1) {
		cout << "Surname: " << p.first << "\nSalary: " << p.second << endl;
	}

	for (auto it = dict.lower_bound("light"); it != dict.upper_bound("light"); ++it) {
		cout << "Surname: " << (*it).first << "\nSalary: " << (*it).second << endl;
	}

	///////////////////////////////////////////////////////////////////

		//���������

		//����������� ���������. ����������� set<Point>. ���������, ���
		//����� ����������� � ������ Point. �������� ������, �������� �������� 
		//�������� ������� ��������� set, �� ����������� �� ��������
	set<Point> set4 = { Point(11,10),Point(1,4),Point(23,34) };
	vector<Point> vec4(set4.rbegin(), set4.rend());


	//��������� ���������. � ������� ostream_iterator �������� ����������
	//vector � set �� ����������� ������� �� �����.
	ostream_iterator<Point> out_it(cout, "\n");
	copy(begin(set4), end(set4), out_it);

	//��������� �������. � ������� ������������ ���������:
	//back_inserter()
	//front_inserter()
	//inserter()
	//���������� ������� �������� �������� � ����� �� ��������� �����������. ���������:
	//����� �� ���������� ������� ����� ������������ � ������ �����������.
	list<int> list_it;
	deque<int> deque_it;
	vector<int> vector_it = {10,11,121,34};
	auto back_it = back_inserter(list_it);
	auto front_it = front_inserter(deque_it); // �� ��������� � queue, ��� ��� ��� ����������� ������ push_front/back
	for (auto value : vector_it) {
		*front_it = value;
		*back_it = value;
	}


///////////////////////////////////////////////////////////////////

	//���������� ��������� (������������ ���� <algorithm>). ���������.

	// �������� for_each() - ����� �������� ������� ��� ������� �������� ����� ������������������
	//(������, vector, list...)
	//� ������� ��������� for_each � ����� ������������������ � ���������� ������ ����
	//������������ �������� ���������
	//��������� : ������� ���������� ������� ���������� ��� ������
	list<Point> list4 = { Point(12,11),Point(66,77) };
	for_each(begin(list4), end(list4), [](auto it) {cout << it; });


	//� ������� ��������� for_each � ����� ������������������ � ���������� ���� Point
	//�������� "����������" �� ��������� �������� (����� �������� ���� ����� ����������� 
	//��� ������) � �������� ��������� � ������� ����������� ���������
	Point value(10, 10);
	for_each(begin(list4), end(list4), [](auto& it) {it = Point(10, 10); });
	for_each(begin(list4), end(list4), [](auto it) {cout << it << endl; });





	//� ������� ��������� find() ������� � ����� ������������������ ��������� Point
	//��� ��������� �� ������� Point � ��������� ���������.
	list<Point> list5 = { Point(12,11),Point(44,13),Point(66,77),Point(44,13) };
	auto iter = list5.begin();
	while (find(iter, end(list5), Point(44, 13)) != end(list5)) {
		iter = find(iter, end(list5), Point(44, 13));
		cout << *iter << endl;
		iter++;

	}




	//� ������� ��������� sort() ������������ ����� ������������������ ��������� Point. 
	////�� ��������� �������� ��������� ������������������ �� �����������.
	//��� ������ ���� ���������� � ������ Point?
	// ���������: ���������� �������� sort �� �������� �� �������, ��� ���
	//��� ���� �� �� ���������� => ��� ������ ���������� ����������� ������� ������!!!
	vector<Point> vec6 = { Point(1,22),Point(14,3),Point(66,102),Point(77,33) };
	list<Point> list6 = { begin(vec6),end(vec6) };
	sort(vec6.begin(),vec6.end());
	list6.sort();


	func();

		//�������� ���������� ������� ����: bool Pred1_1(const Point& ), ������� ����� ����������
		//���������� find_if(), ��������� � �������� ��������� ��������� ������� ������������������.
		//� ������� ��������� find_if() ������� � ����� ������������������ ��������� Point
		//�������� �� ������� Point, ��������������� �������: ���������� x � y ����� � ����������
		//[-n, +m].
	vector<Point> vec7 = { Point(40,23),Point(-50,43),Point(-9,41),Point(-20,55) };
	cout<<*find_if(vec7.begin(), vec7.end(), Pred1_1);

	func();
		//� ������� ��������� sort() ������������ ����� ������������������ ��������� Rect,
		//���������� �������������� �� �������� ������ �� ������ ���������.
	vector<Rect> vec8 = { Rect(Point(13,10),Point(32,41)),Rect(Point(10,3),Point(2,23)),Rect(Point(10, 10), Point(4, 6)) };
	sort(begin(vec8),end(vec8));
	func();
	

	{//transform
		//�������� �������, ������� � ������� ��������� transform ��������� 
		//���������� ������� string � ������ �������.
		//���������: ����� string - ��� "�����" ���������, ������� ��� ����
		// ���������� ������ begin() � end()
		string str1 = "REstoRe Noone";
		Trans(str1);
		cout << str1 << endl;
		func();


		//��������� list ��������� string. � ������� ��������� transform ����������
		//�������� "�������" set, ����������� ������ � ������ �������
		list<string> list9 = { string("QwwErTY"),string("kilE"),string("RaCe") };
		set<string> set9;
		insert_iterator<set<string>> iter(set9, set9.begin());
		transform(list9.begin(), list9.end(), iter,  Trans );
		func();

			

		stop
	}
	{// map

		//����������� ����� �������� ������ � ���������� ���� string.
		//�������� (� ������������ ��� ��������) map<string, int>, ������� �����
		//��������� ������������� �� �������� ������ �
		//���������� ���������� ������ ������ � �������
		vector<string> vec10;
		vec10.push_back("abs");
		vec10.push_back("por");
		vec10.push_back("abs");
		vec10.push_back("qqq");
	
		
		map<string, int> map10;
		for (auto& s : vec10) {
			map10[s]++;
		}
		
		
		for (const auto& elem : map10) {
			cout << "index = " << elem.first << " value = " << elem.second << endl;
		}

	}




	return 0;
}

