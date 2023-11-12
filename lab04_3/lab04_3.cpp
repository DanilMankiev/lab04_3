// Контейнеры STL: 
//deque, stack, queue, priority_queue
//set, multiset, map, multimap
//Итераторы. Стандартные алгоритмы. Предикаты.

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
		cout << stack.top() << endl;        // 1 способ
		stack.pop();
	}
	//auto a = stack._Get_container();
	//for (int i = 0; i < a.size(); ++i) {  // 2 способ
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
	
	//Очередь с двумя концами - контейнер deque

	//Создайте пустой deque с элементами типа Point. С помощью
	//assign заполните deque копиями элементов вектора. С помощью
	//разработанного Вами в предыдущем задании универсального шаблона
	//выведите значения элементов на печать
	deque<Point> deq;
	vector<Point> vec = { Point(1,2),Point(1,3),Point(4,5) };
	deq.assign(begin(vec), end(vec));
	for_each(begin(deq), end(deq), [](auto it) {cout << it; });


	//Создайте deque с элементами типа MyString. Заполните его значениями
	//с помощью push_back(), push_front(), insert()
	//С помощью erase удалите из deque все элементы, в которых строчки
	//начинаются с 'A' или 'a'
	deque<MyString> str;
	MyString mas[3] = { "Exeption","Assert","ambitious" };
	str.push_back(mas[0]);
	str.push_front(mas[1]);
	str.insert(begin(str) + 2, mas[2]);


	////////////////////////////////////////////////////////////////////////////////////


	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//Подумайте, как "получать" данное "с верхушки"?
	//Что происходит с контейнерами после вывода значений?
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

	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	vector<int> vec1 = { 2,22,3,33 };
	stack<int> stack1;
	for (auto i : vec1) {
		stack1.push(i);
	}
	StackOut<int>(stack1);
	func();
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 
	stack<int> stack2;
	for_each(vec1.rbegin(), vec1.rend(), [&stack2](auto i) {stack2.push(i); });
	StackOut<int>(stack2);
	func();

	//Сравнение и копирование стеков

	//а) создайте стек и любым способом задайте значения элементов

	stack<int> stack3;
	stack3.push(10);
	stack3.push(20);
	stack3.push(30);
	//б) создайте новый стек таким образом, чтобы он стал копией первого
	stack<int> stack4(stack3);
	//в) сравните стеки на равенство
	cout << bool(stack4 == stack3) << endl;
	func();
	//г) модифицируйте любой из стеком любым образом (push, pop, top)
	stack4.top() = 40;
	//д) проверьте, какой из стеков больше (подумайте, какой смысл вкладывается в такое сравнение)
	{
		cout << bool(stack4 > stack3) << endl;
		func();
	}


	////////////////////////////////////////////////////////////////////////////////////
	//queue
	// 
	//Создайте очередь, которая содержит указатели на объекты типа Point,
	//при этом явно задайте базовый контейнер.
	//Измените значения первого и последнего элементов посредством front() и back()
	//Подумайте, что требуется сделать при уничтожении такой очереди?
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
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*

	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	const char* mas1[] = { "hello", "worldуbb","meanrr","bxxq","a" };
	priority_queue<const char*> pq1(mas1, mas1 + 5);
	func();
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке?

	{
		PqueueOut(pq1);
		// элементы будут храниться в порядке, определенном адресами памяти, на которые указывают указатели. То есть 

	
	}


	////////////////////////////////////////////////////////////////////////////////////
	//set



	//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
	//		в классе Point (и каким образом)

	set<Point> set1 = { Point(3,2), Point(9,9) };
	set1.insert(Point(1, 1));
	set1.insert(Point(10, 12));
	set1.insert(Point(3, 4));
	//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе

	for_each(set1.begin(), set1.end(), [](auto i) {cout << i << endl; });
	//в) попробуйте изменить любое значение...
	// нельзя
	//г) Создайте два множества, которые будут содержать одинаковые значения
	//		типа int, но занесенные в разном порядке
	set<int> set2({ 1,67,45,12,34,3 });
	set<int> set3({ 67,45,1,3,12,34 });
	//одинаковые
	//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)
	// дубли уничтожаются
	array<int, 10> arr = { 1,21,3,3,21,5 };
	set2.insert(arr.begin(), arr.end());


	////////////////////////////////////////////////////////////////////////////////////
	//multiset




	////////////////////////////////////////////////////////////////////////////////////
	//map	
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
	map<const char*, int> map1;
	//б) заполните контейнер значениями посредством operator[] и insert()
	map1.insert(pair<const char*, int>("Terence", 1000));
	map1.insert(make_pair("Killian", 1111));
	map1.emplace("Freyne", 6666);
	map1["Levandovsky"] = 2000;
	//в) распечатайте содержимое
	for (const auto& p : map1) {
		cout << "Surname: " << p.first << "\nSalary: " << p.second << endl;
	}

	//е) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")
	auto it = map1.find("Terence");
	map1.emplace("Gutaro", (*it).second);
	map1.erase("Terence");
	cout << "After swap key" << endl;
	for (const auto& p : map1) {
		cout << "Surname: " << p.first << "\nSalary: " << p.second << endl;
	}


	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	//в) Выведите все содержимое словаря на экран
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()
	multimap<string, string> dict;
	dict.insert(make_pair("light", "свет"));
	dict.insert(make_pair("light", "легкий"));
	dict.insert(make_pair("light", "огонь"));
	dict.emplace("strange", "чужой");
	dict.insert(make_pair("light", "зажигать"));
	dict.emplace("strange", "странный");
	for (const auto& p : map1) {
		cout << "Surname: " << p.first << "\nSalary: " << p.second << endl;
	}

	for (auto it = dict.lower_bound("light"); it != dict.upper_bound("light"); ++it) {
		cout << "Surname: " << (*it).first << "\nSalary: " << (*it).second << endl;
	}

	///////////////////////////////////////////////////////////////////

		//Итераторы

		//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
		//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
		//являются копиями элементов set, но упорядочены по убыванию
	set<Point> set4 = { Point(11,10),Point(1,4),Point(23,34) };
	vector<Point> vec4(set4.rbegin(), set4.rend());


	//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
	//vector и set из предыдущего задания на экран.
	ostream_iterator<Point> out_it(cout, "\n");
	copy(begin(set4), end(set4), out_it);

	//Итераторы вставки. С помощью возвращаемых функциями:
	//back_inserter()
	//front_inserter()
	//inserter()
	//итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
	//какие из итераторов вставки можно использовать с каждым контейнером.
	list<int> list_it;
	deque<int> deque_it;
	vector<int> vector_it = {10,11,121,34};
	auto back_it = back_inserter(list_it);
	auto front_it = front_inserter(deque_it); // не применимо к queue, так как там отсутствуют методы push_front/back
	for (auto value : vector_it) {
		*front_it = value;
		*back_it = value;
	}


///////////////////////////////////////////////////////////////////

	//Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

	// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
	//(массив, vector, list...)
	//С помощью алгоритма for_each в любой последовательности с элементами любого типа
	//распечатайте значения элементов
	//Подсказка : неплохо вызываемую функцию определить как шаблон
	list<Point> list4 = { Point(12,11),Point(66,77) };
	for_each(begin(list4), end(list4), [](auto it) {cout << it; });


	//С помощью алгоритма for_each в любой последовательности с элементами типа Point
	//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
	//как шаблон) и выведите результат с помощью предыдущего предиката
	Point value(10, 10);
	for_each(begin(list4), end(list4), [](auto& it) {it = Point(10, 10); });
	for_each(begin(list4), end(list4), [](auto it) {cout << it << endl; });





	//С помощью алгоритма find() найдите в любой последовательности элементов Point
	//все итераторы на элемент Point с указанным значением.
	list<Point> list5 = { Point(12,11),Point(44,13),Point(66,77),Point(44,13) };
	auto iter = list5.begin();
	while (find(iter, end(list5), Point(44, 13)) != end(list5)) {
		iter = find(iter, end(list5), Point(44, 13));
		cout << *iter << endl;
		iter++;

	}




	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
	////По умолчанию алгоритм сортирует последовательность по возрастанию.
	//Что должно быть определено в классе Point?
	// Замечание: обобщенный алгоритм sort не работает со списком, так как
	//это было бы не эффективно => для списка сортировка реализована методом класса!!!
	vector<Point> vec6 = { Point(1,22),Point(14,3),Point(66,102),Point(77,33) };
	list<Point> list6 = { begin(vec6),end(vec6) };
	sort(vec6.begin(),vec6.end());
	list6.sort();


	func();

		//Создайте глобальную функцию вида: bool Pred1_1(const Point& ), которая будет вызываться
		//алгоритмом find_if(), передавая в качестве параметра очередной элемент последовательности.
		//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
		//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
		//[-n, +m].
	vector<Point> vec7 = { Point(40,23),Point(-50,43),Point(-9,41),Point(-20,55) };
	cout<<*find_if(vec7.begin(), vec7.end(), Pred1_1);

	func();
		//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
		//располагая прямоугольники по удалению центра от начала координат.
	vector<Rect> vec8 = { Rect(Point(13,10),Point(32,41)),Rect(Point(10,3),Point(2,23)),Rect(Point(10, 10), Point(4, 6)) };
	sort(begin(vec8),end(vec8));
	func();
	

	{//transform
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()
		string str1 = "REstoRe Noone";
		Trans(str1);
		cout << str1 << endl;
		func();


		//Заполните list объектами string. С помощью алгоритма transform сформируте
		//значения "пустого" set, конвертируя строки в нижний регистр
		list<string> list9 = { string("QwwErTY"),string("kilE"),string("RaCe") };
		set<string> set9;
		insert_iterator<set<string>> iter(set9, set9.begin());
		transform(list9.begin(), list9.end(), iter,  Trans );
		func();

			

		stop
	}
	{// map

		//Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе
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

