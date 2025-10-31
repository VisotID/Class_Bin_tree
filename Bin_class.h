// Автор:Высоцкая И.Д.
#pragma once
#include "../Tree_bin/Tree_bin/Binary_tree.h"
#include "../Iterator/Iter.h"

template <typename T>
class Binary_Tree
{
private:
	Tree_Node<T>* root; // указатель на корень дерева
	size_t size; // количество узлов в дереве
public:

	/// Класс итератора для бинарного дерева
	/// Использует стек узлов для движения по дереву пошагово
	class Iterator : public Iterator_abstr<T>
	{
		stack<Tree_Node<T>*> nodes; // стек узлов
		Tree_Node<T>* curr; // текущий узел(узел, на который указывает итератор)
	private:
		
		/// Извлечение следующего элемента из стека
		void next()
		{
			if (nodes.empty()) // если стек пустой
			{
				curr = nullptr;
				return;
			}

			curr = nodes.top(); // берём элемент из стека
			nodes.pop();

			if (curr->right) // если переходим в правое поддерево
			{
				push_left(curr->right); // помещаем левых потомков этого поддерева в стек
			}

		}

	public:

		/// Конструктор итератора
		/// Tree_Node<T>* root - корень дерева
		/// Если корень не пустой, стек заполняется всеми левыми потомками до последнего уровня
		Iterator(Tree_Node<T>* root = nullptr)
		{
			curr = nullptr;
			push_left(root);
			next();
		}

		/// Помещение в стек всех левых узлов от данного узла
		/// Tree_Node<T>* node - узел
		void push_left(Tree_Node<T>* node)
		{
			while (node)
			{
				nodes.push(node);
				node = node->left;
			}
		}

		/// Переход к следующему элементу (префиксный инкремент)
		/// Если стек не пустой, берём верхний узел и добавляем в стек левых потомков его правого поддерева
		Iterator& operator ++() override
		{
			next();
			return *this;
		}

		/// Оператор разыменования
		/// Бросаем исключение если итератор указывает на несуществующий элемент или конец списка
		/// Возвращает ссылку на данные data текущего узла
		T& operator *() const override
		{
			if (!curr)
			{
				throw out_of_range("Элемент не существует");
			}
			return curr->date;
		}

		/// Оператор сравнения
		/// Используется, чтобы проверить, указывают ли два итератора на разные элементы
		/// const Iterator_abstr<T>& other - другой итератор для сравнения
		/// Возвращает true, если итераторы указывают на разные узлы, false, если они указывают на один и тот же узел
		bool operator !=(const Iterator_abstr<T>& other) const override
		{
			const Iterator* it = dynamic_cast<const Iterator*>(&other);
			if (!it)
			{
				return true;
			}
			return this->curr != it->curr;
		}

		/// Оператор сравнения
		/// Используется, чтобы проверить, указывают ли два итератора на разные элементы
		/// const Iterator_abstr<T>& other - другой итератор для сравнения
		/// Возвращает true, если итераторы указывают на один и тот же узел, false, если они указывают на разные узлы
		bool operator==(const Iterator_abstr<T>& other) const
		{
			const Iterator* it = dynamic_cast<const Iterator*>(&other); // пробуем привести ссылку к типу Iterator*
			return this->curr == it->curr;
		}
	};

	/// Возвращает итератор, указывающий на первый элемент
	Iterator begin() const
	{
		return Iterator(root);
	}

	/// Возвращает итератор, указывающий на элемент после последнего
	Iterator end() const
	{
		return Iterator(nullptr);
	}

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
	Binary_Tree(const Binary_Tree& other)
	{
		root = copy_tree(other.root);
	}

	/// Оператор присваивания копированием
	/// other - другое бинарное дерево поиска
	Binary_Tree& operator=(const Binary_Tree& other)
	{
		return Binary_Tree(other);
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
	void removeNode(T data)
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
		Stack_NLR(root, arr);
	}

	/// Деструктор
	~Binary_Tree()
	{
		Del_Tree<T>(root);
	}
};

void test();