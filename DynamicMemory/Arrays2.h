#pragma once

//Добавление строк
void push_row_back(int**& arr, int& m, const int n);
void push_row_front(int**& arr, int& m, const int n);
//Удаление строк
void pop_row_back(int**& arr, int& m, const int n);
void pop_row_front(int**& arr, int& m, const int n);

//Добавление столбцов
void push_col_back(int** arr, const int m, int& n);


//Добавление строки по индексу
void insert_row(int**& arr, int& m, const int n, int index);

//Удаление строки по индексу
void erase_row(int**& arr, int& m, int index);
