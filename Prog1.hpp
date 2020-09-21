#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <tuple>

namespace Prog1
{
	template <class T>
	int getNum(T &a, std::istream &stream)
	{
		stream >> a;
		if (!stream.good()) // обнаружена ошибка ввода или конец файла
			return -1;
		return 1;
	}

	struct MatItem
	{
		int x;
		double val;
		MatItem(int _x, double _val) : x(_x), val(_val) {}
	
		// для сортировки нужен оператор сравнения (меньше)
		bool operator<(const MatItem &b) const { return (x < b.x); }
		// оператор отличия (не равно хотябы одно поле структуры) 
		bool operator!=(const MatItem &b) const { return x != b.x || val != b.val; }
		// для вывода через std::cout например
		friend std::ostream &operator<<(std::ostream &st, MatItem const &item) { return st << "(x=" << item.x << ",val=" << item.val << ")"; }
	};

	struct Matrix
	{
		int n, m;
		// вектор векторов для хранения элементов построчно
		std::vector<std::vector<MatItem>> lines;

		Matrix(int const &_m, int const &_n) : n{_n}, m{_m} {}
		void output(std::string const &msg = "Matrix:");
		// оператор стравнения для отладки и тестов
		bool operator==(Matrix const &mat);
	};

	// ввод матрицы из потока stream (по умолчанию std::cin)
	Matrix input(std::istream &stream = std::cin);
	// по заданию
	Matrix swapij(Matrix &mat);
} // namespace Prog1
