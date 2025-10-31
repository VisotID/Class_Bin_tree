// �����:�������� �.�.
#include <cassert>
#include "Bin_class.h"

void test()
{
	Binary_Tree<int> root; // ������ ������
	Binary_Tree<int> top_2(9); // ������ �� ������ ��������
	Binary_Tree<int> top(8); // ������ �� ������ ���������
	top.insert(5); // �������� ������ ������� ���� � ������
	top.insert(9);
	top.insert(3);
	/*    8
	*   5   9
	* 3
	*/

	Binary_Tree<int> top_3(7); // ����������� ������
	top_3.insert(3);
	top_3.insert(2);
	top_3.insert(1);
	/*		  7
	*	   	 3
	*      2
	*    1
	*/

	Binary_Tree<int> top_4(7); // �����������(������) ������
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

	//���� ��������� �������� �� ��������� ������� � ��������� �������������
	auto it = top.begin(); // ��������� ���������
	auto end = top.end();
	assert(*it == 3);
	++it;
	++it;
	assert(*it == 8);

	auto it1 = root.begin(); // ������
	auto end1 = root.end();
	assert(it1 == end1);
	++it1;
	assert(it1 == end1);

	auto it3 = top_2.begin(); // ���� �������
	auto end3 = top_2.end();
	assert(*it3 == 9);
	++it3;
	assert(it3 == end3);

	auto it4 = top_3.begin(); // ����������� ������
	auto end4 = top_3.end();
	assert(*it4 == 1);
	++it4;
	++it4;
	assert(*it4 == 3);

	auto it5 = top_4.begin(); // �����������(������) ������
	auto end5 = top_4.end();
	assert(*it5 == 4);
	++it5;
	++it5;
	assert(*it5 == 6);

	// ���� ��������� ���������
	assert(root.begin() == root.end()); // ������
	assert(top_2.begin() != top_2.end()); // ���� �������
	auto it6 = top.begin(); // ��������� ���������
	++it6; // ��������� �� ������ �������
	auto it7 = top.begin(); // ��������� �� ������ �������
	assert(it6 != it7); // �� �����

	/// ����� �������� ������ ��������� ����
	assert(root.get_root() == nullptr);
	assert(top.get_root()->date == 8);
	assert(top_2.get_root()->date == 9);
	assert(top_3.get_root()->date == 7);
	assert(top_4.get_root()->date == 7);

	/// ����� �������� ������ �������� �� �������
	assert(root.empty() == 1);
	assert(top.empty() == 0);
	assert(top_2.empty() == 0);
	assert(top_3.empty() == 0);
	assert(top_4.empty() == 0);

	/// ����� �������� ������ ����������� ������� ������
	assert(root.Depth() == -1);
	assert(top.Depth() == 2);
	assert(top_2.Depth() == 0);
	assert(top_3.Depth() == 3);
	assert(top_4.Depth() == 2);

	/// ����� �������� ������ �������� �����
	assert(root.Size() == 0);
	assert(top.Size() == 4);
	assert(top_2.Size() == 1);
	assert(top_3.Size() == 4);
	assert(top_4.Size() == 7);

	/// ����� �������� ������ ����������� ������������� ���� ������
	assert(root.Tree_max() == nullptr);
	assert(top.Tree_max()->date == 9);
	assert(top_2.Tree_max()->date == 9);
	assert(top_3.Tree_max()->date == 7);
	assert(top_4.Tree_max()->date == 10);

	/// ����� �������� ������ ����������� ������������ ���� ������
	assert(root.Tree_min() == nullptr);
	assert(top.Tree_min()->date == 3);
	assert(top_2.Tree_min()->date == 9);
	assert(top_3.Tree_min()->date == 1);
	assert(top_4.Tree_min()->date == 4);

	/// ����� �������� ������ ������ ���� ������
	assert(top.find_tree(8) == 8);
	assert(top_2.find_tree(9) == 9);
	assert(top_3.find_tree(2) == 2);
	assert(top_4.find_tree(4) == 4);

	// ������ ������
	try
	{
		root.find_tree(1);
		assert(false);
	}
	catch (const out_of_range&)
	{

	}

	/// ����� �������� ������� �������
	// NLR ���������� � � ������� �����
	vector<int> arr;
	vector<int> arr_1;
	vector<int> test_1{ 8, 5, 3, 9 };
	top.nlr(arr);
	top.stack_nlr(arr_1);
	assert(arr == test_1);
	assert(arr_1 == test_1);
	arr.clear();
	arr_1.clear();

	// � ����� ���������
	vector<int> test_2{ 9 };
	top_2.nlr(arr);
	top_2.stack_nlr(arr_1);
	assert(arr == test_2);
	assert(arr_1 == test_2);
	arr.clear();
	arr_1.clear();

	// ����������� ������
	vector<int> test_3{ 7, 3, 2, 1 };
	top_3.nlr(arr);
	top_3.stack_nlr(arr_1);
	assert(arr == test_3);
	assert(arr_1 == test_3);
	arr.clear();
	arr_1.clear();

	// �����������(������) ������
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

	// � ����� ���������
	vector<int> test_6{ 9 };
	top_2.nrl(arr);
	assert(arr == test_6);
	arr.clear();

	// ����������� ������
	vector<int> test_7{ 7, 3, 2, 1 };
	top_3.nrl(arr);
	assert(arr == test_7);
	arr.clear();

	// �����������(������) ������
	vector<int> test_8{ 7, 9, 10, 8, 5, 6, 4 };
	top_4.nrl(arr);
	assert(arr == test_8);
	arr.clear();

	// LNR
	vector<int> test_9{ 3, 5, 8, 9 };
	top.lnr(arr);
	assert(arr == test_9);
	arr.clear();

	// � ����� ���������
	vector<int> test_10{ 9 };
	top_2.lnr(arr);
	assert(arr == test_10);
	arr.clear();

	// ����������� ������
	vector<int> test_11{ 1, 2, 3, 7 };
	top_3.lnr(arr);
	assert(arr == test_11);
	arr.clear();

	// �����������(������) ������
	vector<int> test_12{ 4, 5, 6, 7, 8, 9, 10 };
	top_4.lnr(arr);
	assert(arr == test_12);
	arr.clear();

	// RNL
	vector<int> test_13{ 9, 8, 5, 3 };
	top.rnl(arr);
	assert(arr == test_13);
	arr.clear();

	// � ����� ���������
	vector<int> test_14{ 9 };
	top_2.rnl(arr);
	assert(arr == test_14);
	arr.clear();

	// ����������� ������
	vector<int> test_15{ 7, 3, 2, 1 };
	top_3.rnl(arr);
	assert(arr == test_15);
	arr.clear();

	// �����������(������) ������
	vector<int> test_16{ 10, 9, 8, 7, 6, 5, 4 };
	top_4.rnl(arr);
	assert(arr == test_16);
	arr.clear();

	// LRN
	vector<int> test_17{ 3, 5, 9, 8 };
	top.lrn(arr);
	assert(arr == test_17);
	arr.clear();

	// � ����� ���������
	vector<int> test_18{ 9 };
	top_2.lrn(arr);
	assert(arr == test_18);
	arr.clear();

	// ����������� ������
	vector<int> test_19{ 1, 2, 3, 7 };
	top_3.lrn(arr);
	assert(arr == test_19);
	arr.clear();

	// �����������(������) ������
	vector<int> test_20{ 4, 6, 5, 8, 10, 9, 7 };
	top_4.lrn(arr);
	assert(arr == test_20);
	arr.clear();

	// RLN
	vector<int> test_21{ 9, 3, 5, 8 };
	top.rln(arr);
	//assert(arr == test_21);
	arr.clear();

	// � ����� ���������
	vector<int> test_22{ 9 };
	top_2.rln(arr);
	assert(arr == test_22);
	arr.clear();

	// ����������� ������
	vector<int> test_23{ 1, 2, 3, 7 };
	top_3.rln(arr);
	//assert(arr == test_23);
	arr.clear();

	// �����������(������) ������
	vector<int> test_24{ 10, 8, 9, 4, 6, 5, 7 };
	top_4.rln(arr);
	//assert(arr == test_24);
	arr.clear();

	/// ����� �������� ������ �������� ���� �� ������
	root.removeNode(1);
	top.removeNode(5);
	top_2.removeNode(9);
	top_3.removeNode(1);
	top_4.removeNode(5);
	assert(root.Size() == 0);
	assert(top.Size() == 3);
	assert(top_2.Size() == 0);
	assert(top_3.Size() == 3);
	assert(top_4.Size() == 6);

	/// ����������� �����������
	Binary_Tree<int> top_6 = top;
	vector<int> arr2;
	top.nlr(arr);
	top_6.nlr(arr2);
	assert(arr == arr2);
	arr.clear();

}