// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "bitString.h"
using namespace std;

BitString operator "" _bits(const char* literalString) 
{
	ull left = 0;
	ull right = 0;
	string str = literalString;
	str.insert(0, 128 - strlen(literalString), '0');
	for (int i = 0; i < 64; i++)
	{
		left <<= 1;
		right <<= 1;
		left += (str[i] == '0') ? 0 : 1;
		right += (str[i + 64] == '0') ? 0 : 1;
	}
	return BitString(left, right);
}

int main()
{
	ull x, y;
	cin >> x >> y;
	BitString a = BitString(x, y);
	cin >> x >> y;
	BitString b = BitString(3, 5);
	BitString c = 10000001011111111111111111000000000010101_bits;

	cout << "a = ";
	a.Print();
	cout << "b = ";
	b.Print();

	c = a & b;
	cout << "a and b = ";
	c.Print();

	c = a | b;
	cout << "a or b = ";
	c.Print();

	c = a ^ b;
	cout << "a xor b = ";
	c.Print();

	c = ~a;
	cout << "not a = ";
	c.Print();

	cout << "a << 1 = ";
	c = a << 1;
	c.Print();

	cout << "b >> 2 = ";
	c = a >> 2;
	c.Print();

	cout << "literal is: ";
	c = 111010000000000000000000000001_bits;
	c.Print();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
