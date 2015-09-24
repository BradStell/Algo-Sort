#ifndef SORT_H
#define SORT_H

class Sort
{
	private:
		
	public:
		static void BruteForce(int *array, int k, int size);
		static void InsertionSort(int *array, int size);
		static void BubbleSort(int *array, int size);
		static void SelectionSort(int *array, int size);
		static void Swap(int *array, int first, int second);
		static void Print(int *array, int size);
};

#endif