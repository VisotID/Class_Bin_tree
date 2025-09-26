// �����:�������� �.�.
#pragma once
#include "../Tree_bin/Tree_bin/Binary_tree.h"

template <typename T>
class Binary_Tree
{
private:
	Tree_Node<T>* root; // ��������� �� ������ ������
	size_t size; // ���������� ����� � ������
public:

	/// ����������� �� ���������
	Binary_Tree()
	{
		size = 0;
		root = nullptr;
	}

	/// ����������� � �����������
	/// T data - ������ ����
	Binary_Tree(T data)
	{
		size = 1;
		root = new Tree_Node<T>(data);
	}

	/// ����������� �����������
	/// other - ������ �������� ������ ������
	BinaryTree(const BinaryTree& other)
	{
		root = copyNodes(other.root);
	}

	/// �������� ������������ ������������
	/// other - ������ �������� ������ ������
	BinaryTree& operator=(const BinaryTree& other)
	{
		return BinaryTree(other);
	}

	/// ������� � ������
	/// ���������: O(n) - ������������������, O(logn) - ����������������
	/// T data - ������ ����
	void insert(T data)
	{
		root = Add_Bin_Tree<T>(data, root); // �������� ������ ����
		size = size + 1; // ����������� ���������� ����� �� 1
	}

	/// �������� ���� �� ������
	/// ���������: O(n) - ������������������, O(log n) - ����������������
	/// ������� ���������� ���� 
	/// T data - ������ ����
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

	/// ����� ������ � ������
	/// ���������: O(n) - ������������������, O(logn) - ����������������
	T find_tree(T data)
	{
		return find<T>(data, root);
	}

	/// ��������� ������������ ���� ������
	/// ���������: O(log n) - � ������������������, O(n) - �����������
	Tree_Node<T>* Tree_min()
	{
		return Find_min(root);
	}

	/// ��������� ������������� ���� ������
	/// ���������: O(log n) - � ������������������, O(n) - �����������
	Tree_Node<T>* Tree_max()
	{
		return Find_max(root);
	}

	/// ��������� ���������� ����� ������
	/// ���������: O(n)
	size_t Size()
	{
		return size;
	}

	/// ��������� ������� ������
	/// ���������: O(n)
	int Depth()
	{
		return depth(root);
	}

	/// ������� ������
	void clear()
	{
		Del_Tree<T>(root);
		root = nullptr;
	}

	/// �������� �� ������ ������
	/// ��������� O(1)
	/// ���������� 1 - ���� ������ ������, 0 - ���� ������ ��������
	bool empty()
	{
		if (root == nullptr)
		{
			return 1;
		}
		return 0;
	}

	/// ��������� ����� ������
	/// ��������� O(1)
	Tree_Node<T>* get_root()
	{
		return root;
	}

	/// ������ � �������
	/// vector<T>& arr - ������ ���� ������
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

	/// ����������
	~Binary_Tree()
	{
		Del_Tree<T>(root);
	}
};