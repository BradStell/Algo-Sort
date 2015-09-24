//////////////////////////////////////////////////////////////////////////////////////////
//																						//
//	Author: Brad Stell																	//
//																						//
//	Date: 9/24/2015																		//
//																						//
//	Language: c++																		//
//																						//
//	Description:																		//
//		This class is composed of all static methods to be used without instantiating	//
//		an object of the class. It contains 4 sorting algorithms, each one different	//
//		and utilizing a different property for sorting.									//
//																						//
//////////////////////////////////////////////////////////////////////////////////////////


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