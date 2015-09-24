#include <iostream>
#include "sort.h"


void Sort::BruteForce(int * array, int k, int size)
{
	static bool SORTED = false;

	for (int i = k; i < size && !SORTED; i++)
	{
		// This for loop will create all permutations of the array,

		int temp = array[i];
		array[i] = array[k];
		array[k] = temp;

		BruteForce(array, k + 1, size);

		temp = array[k];
		array[k] = array[i];
		array[i] = temp;
	}
	if (k == size - 1)
	{
		// This if statement occurs once every different permutation
		// Checks to see if the permutation is sorted
		SORTED = true;

		for (int i = 0; i < size - 1 && SORTED; i++)
		{
			if (array[i] > array[i + 1])
				SORTED = false;
		}
				
		if (SORTED)
		{
			Sort::Print(array, size);
			return;
		}
			
	}		
}

void Sort::InsertionSort(int * array, int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = i;
		while (j > 0 && array[j] < array[j - 1])
		{
			Sort::Swap(array, j, j - 1);
			j--;
		}
	}

	Sort::Print(array, size);
}

void Sort::BubbleSort(int * array, int size)
{

	bool sorted = false;

	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				Sort::Swap(array, i, i + 1);
				sorted = false;
			}				
		}
	}

	Sort::Print(array, size);

}

void Sort::SelectionSort(int * array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = i;
		for (int j = i; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		Sort::Swap(array, i, min);
	}

	Sort::Print(array, size);
}

void Sort::Swap(int * array, int first, int second)
{
	int temp = array[first];
	array[first] = array[second];
	array[second] = temp;
}

//////////////////////////////////
/// For testing purposes only ///
void Sort::Print(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}