
void push_row_back(int**& arr, int& m, const int n)
{
	//1. Создаем буферный массив:
	int** buffer = new int* [m + 1]{};
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
	arr[m] = new int [n] {};
	m++;
}
void push_row_front(int**& arr, int& m, const int n)
{
	//1. Создаем буферный массив указателей нужного размера:
	int** buffer = new int* [m + 1]{};

	//2. Копируем адреса строк в новый массив:
	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = arr[i];
	}

	//3. Удаляем старый массив указателей:
	delete[] arr;

	//4. Подменяем адрес на новый массив:
	arr = buffer;

	//5. Создаем новую строку:
	arr[0] = new int [n] {};
	//6. Увеличиаваем количество строк:
	m++;
}

void pop_row_back(int**& arr, int& m, const int n)
{
	//1. Создаем буферный массив указателей нужного размера:
	int** buffer = new int* [--m]{};

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
void pop_row_front(int**& arr, int& m, const int n)
{
	int** buffer = new int* [--m]{};
	for (int i = 0; i < m; i++)	buffer[i] = arr[i + 1];
	delete[] arr[0];
	delete[] arr;
	arr = buffer;
}
void push_col_back(int** arr, const int m, int& n)
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

void insert_row(int**& arr, int& m, const int n, int index)
{
	int** buffer = new int* [m + 1]{};
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < m + 1; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[index] = new int [n] {};
	m++;
}

void erase_row(int**& arr, int& m, int index)
{
	int** buffer = new int* [--m]{};
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < m; i++)
		buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
}