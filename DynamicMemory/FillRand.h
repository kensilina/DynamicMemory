#pragma once //чтобы содержимое этого файла было встроено один раз
//Прототипы функций выносятся в заголовочные файлы (*.h)
//FillRand
#include <stdlib.h>

void FillRand(int arr[], const int n);//Прототип функции - объявление функции(Function declaration)
void FillRand(int** arr, const int m, const int n);