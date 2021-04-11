#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"
void FillRand(int arr[], const int n);
void FillRand(int** arr, const int m, const int n);

template<typename T> //T - шаблонный тип данных
void Print(T arr[], const int n);
template<typename T>
void Print(T** arr, const int m, const int n);

template<typename T>
void push_back(T*& arr, int& n, T value);
template<typename T>
void push_front(T*& arr, int& n, T value);
template<typename T>
void insert(T*& arr, int& n, T value, int index);

template<typename T>
void pop_back(T*& arr, int& n);	//Удаляет элемент с конца массива
template<typename T>
void pop_front(T*& arr, int& n);
template<typename T>
void erase(T*& arr, int& n, int index);

//Добавление строк
template<typename T>
void push_row_back(T**& arr, int& m, const int n);
template<typename T>
void push_row_front(T**& arr, int& m, const int n);
//Удаление строк
template<typename T>
void pop_row_back(T**& arr, int& m, const int n);
template<typename T>
void pop_row_front(T**& arr, int& m, const int n);

//Добавление столбцов
template<typename T>
void push_col_back(T** arr, const int m, int& n);


//Добавление строки по индексу
template<typename T>
void insert_row(T**& arr, int& m, const int n, int index);

//Удаление строки по индексу
template<typename T>
void erase_row(T**& arr, int& m, int index);

//#define PUSH_BACK
#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define DEBUG_ARRAYS

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};
	FillRand(arr, n);
	Print(arr, n);
	int value;	//Добвляемое значение
	cout << "Введите добавляемое значение: "; cin >> value;
#ifdef PUSH_BACK
	//1) Создаем буферный массив нужного размера:
	int* buffer = new int[n + 1]{};
	//2) Копируем все значения из исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) После того как данные скопированы, исходный массив можно удалить:
	delete[] arr;
	//4) Подменяем адрес в указателе на исходный массив:
	arr = buffer;
	//5) И только после всего этого можно записать новое значение в конец массива:
	arr[n] = value;
	n++;
#endif // PUSH_BACK
	push_back(arr, n, value);
	Print(arr, n);
	
	cout << "Введите добавляемое значение: "; cin >> value;
	push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	insert(arr, n, value, index);
	Print(arr, n);

	cout << "Удаление последнего элемента:\n";
	pop_back(arr, n);
	Print(arr, n);
	cout << "Введите индекс удавляемого элемента: "; cin >> index;
	erase(arr, n, index);
	Print(arr, n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	/////////////////////////////////////////////////////////////////////////////////////////////
///////////////////		ОБЪЯВЛЕНИЕ ДВУМЕРНОГО ДИНАМИЧЕСКОГО МАССИВА		/////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
	int r;	//Количество строк
	int c;	//Количество элементов cтроки
	cout << "Введите количество строк: "; cin >> r;
	cout << "Введите количество элементов строки: "; cin >> c;
	//1)Создаем массив указателей, и сохраняем его адрес в указатель на указатель:
	int** arr2 = new int* [r];
	//2)Выделяем память под строки двумерного массива:
	for (int i = 0; i < r; i++)
	{
		arr2[i] = new int[c] {};
	}

	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////		ИСПОЛЬЗОВАНИЕ ДВУМЕРНОГО ДИНАМИЧЕСКОГО МАССИВА		/////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	cout << "Память выделена" << endl;
	system("PAUSE");
	FillRand(arr2, r, c);
	Print(arr2, r, c);

	cout << "Добавление строки в конец массива:\n";
	push_row_back(arr2, r, c);
	Print(arr2, r, c);

	cout << "Добавление строки в начало массива:\n";
	push_row_front(arr2, r, c);
	Print(arr2, r, c);

	cout << "Удаление последней строки в конце массива:\n";
	pop_row_back(arr2, r, c);
	Print(arr2, r, c);

	cout << "Удаление первой строки в начале массива:\n";
	pop_row_front(arr2, r, c);
	Print(arr2, r, c);

	cout << "Добавление столбца в конец массива:\n";
	push_col_back(arr2, r, c);
	Print(arr2, r, c);

	//int index;
	cout << "Введите индекс:\n"; cin >> index;
	insert_row(arr2, r, c, index);
	cout << "Добавление строки по индексу:\n";
	Print(arr2, r, c);

	cout << "Введите индекс удаляемой строки:\n"; cin >> index;
	erase_row(arr2, r, index);
	cout << "Удаление строки по индексу:\n";
	Print(arr2, r, c);

	/*cout << "Строка добавлена" << endl;*/
	/////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////		УДАЛЕНИЕ ДВУМЕРНОГО ДИНАМИЧЕСКОГО МАССИВА		/////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	//1) Удаление строк:
	for (int i = 0; i < r; i++)
	{
		delete[] arr2[i];
	}
	//2) Удаление массива указателей:
	delete[] arr2;
#endif  DYNAMIC_MEMORY_2

#ifdef DEBUG_ARRAYS
	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	Print(arr, n);
#endif // DEBUG_ARRAYS

}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

template<typename T>
void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
template<typename T>
void Print(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}

template<typename T>
void push_back(T*& arr, int& n, T value)
{
	//1) Создаем буферный массив нужного размера:
	T* buffer = new T[n + 1]{};
	//2) Копируем все значения из исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];	//Копируем элементы СООТВЕТСТВЕННО
	}
	//3) После того как данные скопированы, исходный массив можно удалить:
	delete[] arr;
	//4) Подменяем адрес в указателе на исходный массив:
	arr = buffer;
	//5) И только после всего этого можно записать новое значение в конец массива:
	arr[n] = value;
	n++;
}
template<typename T>
void push_front(T*& arr, int& n, T value)
{
	T* buffer = new T[n + 1/*Сложить, суммировать*/]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];	//Копируем элементы СО СМЕЩЕНИЕМ НА ОДИН ЭЛЕМЕНТ ВПРАВО
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}
template<typename T>
void insert(T*& arr, int& n, T value, int index)
{
	T* buffer = new T[n + 1]{};
	/*for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < n; i++)
		buffer[i + 1] = arr[i];*/
	for (int i = 0; i < n; i++)
	{
		true;
		if (i < index)buffer[i] = arr[i]; else buffer[i + 1] = arr[i];
		//(i < index) ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
		//(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
		buffer[i < index ? i : i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
}

template<typename T>
void pop_back(T*& arr, int& n)
{
	T* buffer = new T[--n]{};	//Фигурные скобки заполняют выделяемую пать нулями
	//Для того чтобы удалить элемент из массива, 
	//в буферный массив нужно скопировать все элементы кроме удаляемого:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}
template<typename T>
void pop_front(T*& arr, int& n)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}
template<typename T>
void erase(T*& arr, int& n, int index)
{
	T* buffer = new T[--n]{};
	/*for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}*/
	for (int i = 0; i < n; i++)
	{
		//buffer[i] = i < index ? arr[i] : arr[i + 1];
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;
	arr = buffer;
}

template<typename T>
void push_row_back(T**& arr, int& m, const int n)
{
	//1. Создаем буферный массив:
	T** buffer = new T*[m + 1]{};
	/*for (int i = 0; i < m+1; i++)
	{
		buffer[i] = new int[n] {};
	}*/
	//2. Копируем все значения исходного массива в буферный:
	for (int i = 0; i < m; i++)
	{
		/*for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}*/
		buffer[i] = arr[i]; //В буферный массив просто переносим адрес соответсвующей строки.
	}
	//3. Удаляем исходный массив:
	/*for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}*/
	//Не нужно удалять строки, достаточно удалить старый массив указателей:
	delete[] arr;
	//4. Переопределяем новый массив:
	arr = buffer;
	//5. Создаем новую строку:
	arr[m] = new T [n] {};
	m++;
}
template<typename T>
void push_row_front(T**& arr, int& m, const int n)
{
	//1. Создаем буферный массив указателей нужного размера:
	T** buffer = new T* [m + 1]{};

	//2. Копируем адреса строк в новый массив:
	for (int i = 0; i < m; i++)
	{
		buffer[i+1] = arr[i];
	}

	//3. Удаляем старый массив указателей:
	delete[] arr;

	//4. Подменяем адрес на новый массив:
	arr = buffer;

	//5. Создаем новую строку:
	arr[0] = new T [n] {};
	//6. Увеличиаваем количество строк:
	m++;
}

template<typename T>
void pop_row_back(T**& arr, int& m, const int n)
{
	//1. Создаем буферный массив указателей нужного размера:
	T** buffer = new T* [--m]{};

	//2. Копируем строки в новый массив:
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}

	//3. Удаляем последнюю строку:
	delete[] arr[m];

	//4. Удаляем старый массив указателей:
	delete[] arr;

	//5. Сохраняем адрес нового массива:
	arr = buffer;
}
template<typename T>
void pop_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T* [--m]{};
	for (int i = 0; i < m; i++)	buffer[i] = arr[i+1];
	delete[] arr[0];
	delete[] arr;
	arr = buffer;
}
template<typename T>
void push_col_back(T** arr, const int m, int& n)
{
	//Проходим по строкам, и переопределяем каждую строку:
	for (int i = 0; i < m; i++)
	{
		//1. Создаем строку нужного размера:
		int* buffer = new int[n + 1]{};
		//2. Копируем исходную строку в новую строку:
		for (int j = 0; j < n; j++) buffer[j] = arr[i][j];
		//3. Удаляем исходную строку:
		delete[] arr[i];
		//4. Подменяем адрес старой строки адресом новой строки:
		arr[i] = buffer;
	}
	//5. После того, как мы переопределили каждую строку, увеличиваем количество строк на 1:
	n++;
}

template<typename T>
void insert_row(T**& arr, int& m, const int n, int index)
{
	T** buffer = new T* [m + 1]{};
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < m+1; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[index] = new T [n] {};
	m++;
}

template<typename T>
void erase_row(T**& arr, int& m, int index)
{
	T** buffer = new T* [--m]{};
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < m; i++)
		buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
}