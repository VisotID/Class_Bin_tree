// Автор:Высоцкая И.Д.
#pragma once
#include "../Tree_bin/Tree_bin/Binary_tree.h"

template <typename T>
class Binary_Tree
{
private:
	Tree_Node<T>* root; // указатель на корень дерева
	size_t size; // количество узлов в дереве
public:

	/// Конструктор по умолчанию
	Binary_Tree()
	{
		size = 0;
		root = nullptr;
	}

	/// Конструктор с параметрами
	/// T data - данные узла
	Binary_Tree(T data)
	{
		size = 1;
		root = new Tree_Node<T>(data);
	}

	/// Конструктор копирования
	/// other - другое бинарное дерево поиска
	BinaryTree(const BinaryTree& other)
	{
		root = copyNodes(other.root);
	}

	/// Оператор присваивания копированием
	/// other - другое бинарное дерево поиска
	BinaryTree& operator=(const BinaryTree& other)
	{
		return BinaryTree(other);
	}

	/// Вставка в дерево
	/// Сложность: O(n) - несбалансированное, O(logn) - сбалансированное
	/// T data - данные узла
	void insert(T data)
	{
		root = Add_Bin_Tree<T>(data, root); // создание нового узла
		size = size + 1; // увеличиваем количество узлов на 1
	}

	/// Удаление узла из дерева
	/// Сложность: O(n) - несбалансированное, O(log n) - сбалансированное
	/// Бросаем исключение если 
	/// T data - данные узла
	void remove(T data)
	{
		try
		{
			find_tree(data);
			remove<T>(root, data);
			size = size - 1;
			if (size == 0)
			{
				root = nullptr;
			}
		}
		catch (out_of_range)
		{
			return;
		}
	}

	/// Поиск данных в дереве
	/// Сложность: O(n) - несбалансированное, O(logn) - сбалансированное
	T find_tree(T data)
	{
		return find<T>(data, root);
	}

	/// Получение минимального узла дерева
	/// Сложность: O(log n) - у сбалансированнного, O(n) - вырожденное
	Tree_Node<T>* Tree_min()
	{
		return Find_min(root);
	}

	/// Получение максимального узла дерева
	/// Сложность: O(log n) - у сбалансированнного, O(n) - вырожденное
	Tree_Node<T>* Tree_max()
	{
		return Find_max(root);
	}

	/// Получение количества узлов дерева
	/// Сложность: O(n)
	size_t Size()
	{
		return size;
	}

	/// Получение глубины дерева
	/// Сложность: O(n)
	int Depth()
	{
		return depth(root);
	}

	/// Очистка дерева
	void clear()
	{
		Del_Tree<T>(root);
		root = nullptr;
	}

	/// Проверка на пустое дерево
	/// Сложность O(1)
	/// Возвращает 1 - если дерево пустое, 0 - если дерево непустое
	bool empty()
	{
		if (root == nullptr)
		{
			return 1;
		}
		return 0;
	}

	/// Получение корня дерева
	/// Сложность O(1)
	Tree_Node<T>* get_root()
	{
		return root;
	}

	/// Обходы в глубину
	/// vector<T>& arr - массив типа вектор
	void nlr(vector<T>& arr)
	{
		NLR(root, arr);
	}

	void nrl(vector<T>& arr)
	{
		NRL(root, arr);
	}

	void lnr(vector<T>& arr)
	{
		LNR(root, arr);
	}

	void rnl(vector<T>& arr)
	{
		RNL(root, arr);
	}

	void rln(vector<T>& arr)
	{
		RNL(root, arr);
	}

	void lrn(vector<T>& arr)
	{
		LRN(root, arr);
	}
	 
	void stack_nlr(vector<T>& arr)
	{
		Stack_NLR(root);
	}

	/// Деструктор
	~Binary_Tree()
	{
		Del_Tree<T>(root);
	}
};