// Автор:Высоцкая И.Д.
#include <cassert>
#include "Bin_class.h"

void test()
{
	Binary_Tree<int> root; // пустое дерево
	Binary_Tree<int> top_2(9); // дерево из одного элемента
	Binary_Tree<int> top(8); // дерево из четырёх элементов
	top.insert(5); // проверка метода вставки узла в дерево
	top.insert(9);
	top.insert(3);
	/*    8
	*   5   9
	* 3
	*/

	Binary_Tree<int> top_3(7); // вырожденное дерево
	top_3.insert(3);
	top_3.insert(2);
	top_3.insert(1);
	/*		  7
	*	   	 3
	*      2
	*    1
	*/

	Binary_Tree<int> top_4(7); // совершенное(полное) дерево
	top_4.insert(5);
	top_4.insert(9);
	top_4.insert(4);
	top_4.insert(6);
	top_4.insert(8);
	top_4.insert(10);
	/*       7
	*   5        9
	* 4  6     8   10
	*/

	/// Тесты проверки метода получения узла
	assert(root.get_root() == nullptr);
	assert(top.get_root()->date == 8);
	assert(top_2.get_root()->date == 9);
	assert(top_3.get_root()->date == 7);
	assert(top_4.get_root()->date == 7);

	/// Тесты проверки метода проверки на пустоту
	assert(root.empty() == 1);
	assert(top.empty() == 0);
	assert(top_2.empty() == 0);
	assert(top_3.empty() == 0);
	assert(top_4.empty() == 0);

	/// Тесты проверки метода определения глубины дерева
	assert(root.Depth() == -1);
	assert(top.Depth() == 2);
	assert(top_2.Depth() == 0);
	assert(top_3.Depth() == 3);
	assert(top_4.Depth() == 2);

	/// Тесты проверки метода подсчёта узлов
	assert(root.Size() == 0);
	assert(top.Size() == 4);
	assert(top_2.Size() == 1);
	assert(top_3.Size() == 4);
	assert(top_4.Size() == 7);

	/// Тесты проверки метода определения максимального узла дерева
	assert(root.Tree_max() == nullptr);
	assert(top.Tree_max()->date == 8);
	assert(top_2.Tree_max()->date == 9);
	assert(top_3.Tree_max()->date == 7);
	assert(top_4.Tree_max()->date == 10);

	/// Тесты проверки метода определения минимального узла дерева
	assert(root.Tree_min() == nullptr);
	assert(top.Tree_min()->date == 3);
	assert(top_2.Tree_min()->date == 9);
	assert(top_3.Tree_min()->date == 1);
	assert(top_4.Tree_min()->date == 4);

	/// Тесты проверки метода поиска узла дерева
	assert(top.find_tree(8) == 8);
	assert(top_2.find_tree(9) == 9);
	assert(top_3.find_tree(2) == 2);
	assert(top_4.find_tree(4) == 4);

	// пустое дерево
	try
	{
		root.find_tree(1);
		assert(false);
	}
	catch (const out_of_range&)
	{

	}

	/// Тесты проверки методов обходов
	// NLR рекурсивно и с помощью стека
	vector<int> arr;
	vector<int> arr_1;
	vector<int> test_1{ 8, 5, 3, 9 };
	top.nlr(arr);
	top.stack_nlr(arr_1);
	assert(arr == test_1);
	assert(arr_1 == test_1);
	arr.clear();
	arr_1.clear();

	// с одним элементом
	vector<int> test_2{ 9 };
	top_2.nlr(arr);
	top_2.stack_nlr(arr_1);
	assert(arr == test_2);
	assert(arr_1 == test_2);
	arr.clear();
	arr_1.clear();

	// вырожденное дерево
	vector<int> test_3{ 7, 3, 2, 1 };
	top_3.nlr(arr);
	top_3.stack_nlr(arr_1);
	assert(arr == test_3);
	assert(arr_1 == test_3);
	arr.clear();
	arr_1.clear();

	// совершенное(полное) дерево
	vector<int> test_4{ 7, 5, 4, 6, 9, 8, 10 };
	top_4.nlr(arr);
	top_4.stack_nlr(arr_1);
	assert(arr == test_4);
	assert(arr_1 == test_4);
	arr.clear();
	arr_1.clear();

	// NRL
	vector<int> test_5{ 8, 9, 5, 3 };
	top.nrl(arr);
	assert(arr == test_5);
	arr.clear();

	// с одним элементом
	vector<int> test_6{ 9 };
	top_2.nrl(arr);
	assert(arr == test_6);
	arr.clear();

	// вырожденное дерево
	vector<int> test_7{ 7, 3, 2, 1 };
	top_3.nrl(arr);
	assert(arr == test_7);
	arr.clear();

	// совершенное(полное) дерево
	vector<int> test_8{ 7, 9, 10, 8, 5, 6, 4 };
	top_4.nrl(arr);
	assert(arr == test_8);
	arr.clear();

	// LNR
	vector<int> test_9{ 3, 5, 8, 9 };
	top.lnr(arr);
	assert(arr == test_9);
	arr.clear();

	// с одним элементом
	vector<int> test_10{ 9 };
	top_2.lnr(arr);
	assert(arr == test_10);
	arr.clear();

	// вырожденное дерево
	vector<int> test_11{ 1, 2, 3, 7 };
	top_3.lnr(arr);
	assert(arr == test_11);
	arr.clear();

	// совершенное(полное) дерево
	vector<int> test_12{ 4, 5, 6, 7, 8, 9, 10 };
	top_4.lnr(arr);
	assert(arr == test_12);
	arr.clear();

	// RNL
	vector<int> test_13{ 9, 8, 5, 3 };
	top.rnl(arr);
	assert(arr == test_13);
	arr.clear();

	// с одним элементом
	vector<int> test_14{ 9 };
	top_2.rnl(arr);
	assert(arr == test_14);
	arr.clear();

	// вырожденное дерево
	vector<int> test_15{ 7, 3, 2, 1 };
	top_3.rnl(arr);
	assert(arr == test_15);
	arr.clear();

	// совершенное(полное) дерево
	vector<int> test_16{ 10, 9, 8, 7, 6, 5, 4 };
	top_4.rnl(arr);
	assert(arr == test_16);
	arr.clear();

	// LRN
	vector<int> test_17{ 3, 5, 9, 8 };
	top.lrn(arr);
	assert(arr == test_17);
	arr.clear();

	// с одним элементом
	vector<int> test_18{ 9 };
	top_2.lrn(arr);
	assert(arr == test_18);
	arr.clear();

	// вырожденное дерево
	vector<int> test_19{ 1, 2, 3, 7 };
	top_3.lrn(arr);
	assert(arr == test_19);
	arr.clear();

	// совершенное(полное) дерево
	vector<int> test_20{ 4, 6, 5, 8, 10, 9, 7 };
	top_4.lrn(arr);
	assert(arr == test_20);
	arr.clear();

	// RLN
	vector<int> test_21{ 9, 3, 5, 8 };
	top.rln(arr);
	assert(arr == test_21);
	arr.clear();

	// с одним элементом
	vector<int> test_22{ 9 };
	top_2.rln(arr);
	assert(arr == test_22);
	arr.clear();

	// вырожденное дерево
	vector<int> test_23{ 1, 2, 3, 7 };
	top_3.rln(arr);
	assert(arr == test_23);
	arr.clear();

	// совершенное(полное) дерево
	vector<int> test_24{ 10, 8, 9, 4, 6, 5, 7 };
	top_4.rln(arr);
	assert(arr == test_24);
	arr.clear();

	/// Тесты проверки метода удаления узла из дерева
	root.remove(1);
	top.remove(5);
	top_2.remove(9);
	top_3.remove(1);
	top_4.remove(5);
	assert(root.Size() == 0);
	assert(top.Size() == 3);
	assert(top_2.Size() == 0);
	assert(top_3.Size() == 3);
	assert(top_4.Size() == 6);

	/// Конструктор копирования
	Binary_Tree<int> top_6 = top;
	vector<int> arr2;
	top.nlr(arr);
	top_6.nlr(arr2);
	assert(arr == arr2);
	arr.clear();

}