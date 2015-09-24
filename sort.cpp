#include <iostream>
#include "sort.h"


void Sort::BruteForce(int * array, int size)
{

}

void Sort::InsertionSort(int * array, int size)
{

}

void Sort::BubbleSort(int * array, int size)
{

	for (int i = 0; i < size; i++)
	{
		int min = array[i];
		for (int j = 1; j < size; j++)
		{
			if (array[j] < min)
			{
				int temp = array[j];
				array[j] = array[i];
				array[i] = temp;				
			}
		}
	}

	Sort::Print(array, size);

}

void Sort::SelectionSort(int * array, int size)
{

}

void Sort::Print(int * array, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
}
