
void push_row_back(int**& arr, int& m, const int n)
{
	//1. ������� �������� ������:
	int** buffer = new int* [m + 1]{};
	/*for (int i = 0; i < m+1; i++)
	{
		buffer[i] = new int[n] {};
	}*/
	//2. �������� ��� �������� ��������� ������� � ��������:
	for (int i = 0; i < m; i++)
	{
		/*for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}*/
		buffer[i] = arr[i]; //� �������� ������ ������ ��������� ����� �������������� ������.
	}
	//3. ������� �������� ������:
	/*for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}*/
	//�� ����� ������� ������, ���������� ������� ������ ������ ����������:
	delete[] arr;
	//4. �������������� ����� ������:
	arr = buffer;
	//5. ������� ����� ������:
	arr[m] = new int [n] {};
	m++;
}
void push_row_front(int**& arr, int& m, const int n)
{
	//1. ������� �������� ������ ���������� ������� �������:
	int** buffer = new int* [m + 1]{};

	//2. �������� ������ ����� � ����� ������:
	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = arr[i];
	}

	//3. ������� ������ ������ ����������:
	delete[] arr;

	//4. ��������� ����� �� ����� ������:
	arr = buffer;

	//5. ������� ����� ������:
	arr[0] = new int [n] {};
	//6. ������������ ���������� �����:
	m++;
}

void pop_row_back(int**& arr, int& m, const int n)
{
	//1. ������� �������� ������ ���������� ������� �������:
	int** buffer = new int* [--m]{};

	//2. �������� ������ � ����� ������:
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}

	//3. ������� ��������� ������:
	delete[] arr[m];

	//4. ������� ������ ������ ����������:
	delete[] arr;

	//5. ��������� ����� ������ �������:
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
	//�������� �� �������, � �������������� ������ ������:
	for (int i = 0; i < m; i++)
	{
		//1. ������� ������ ������� �������:
		int* buffer = new int[n + 1]{};
		//2. �������� �������� ������ � ����� ������:
		for (int j = 0; j < n; j++) buffer[j] = arr[i][j];
		//3. ������� �������� ������:
		delete[] arr[i];
		//4. ��������� ����� ������ ������ ������� ����� ������:
		arr[i] = buffer;
	}
	//5. ����� ����, ��� �� �������������� ������ ������, ����������� ���������� ����� �� 1:
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