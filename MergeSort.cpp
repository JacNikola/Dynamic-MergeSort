#include<iostream>
#include<cmath> //for ceil()
using namespace std;


void SplitList(int* arr, int* arrL, int* arrR, int size, int mid)
{
	for (int i = 0; i < mid; i++)
	{
		arrL[i] = *arr;
		arr++;
	}
	
	for (int i = 0; i < size - mid; i++)
	{
		arrR[i] = *arr;
		arr++;
	} 
	//after this function executes, *arr is pointing to NULL
}


int* MergeLists(int* arrL, int* arrR, int size)
{
	int* new_arr = new int[size];
	for(int i = 0; i < size; i++)
	{
		if (*arrL && *arrR)
		{
			if (*arrL > *arrR)
			{
				new_arr[i] = *arrR;
				arrR++;
			}
			else 
			{
				new_arr[i] = *arrL;
				arrL++;
			}
			continue;
		}
		else if (*arrR)
		{
			new_arr[i] = *arrR;
			arrR++;
		}
		else
		{
			new_arr[i] = *arrL;
			arrL++;
		}
	}
	return new_arr;
}


int* MergeSort(int* arr, int size)
{
	//int size;
	//size = Size(arr);
	if (size - 1 == 0)
	{
		return arr;
	}
	int mid = ceil(size/2.0);
		
	int* arrL = new int[mid];
	int* arrR = new int[size - mid];
	SplitList(arr, arrL, arrR, size, mid);
	arrL = MergeSort(arrL, mid);
	arrR = MergeSort(arrR, size-mid);
	
	return MergeLists(arrL, arrR, size);	 
	
}


int main()
{
	int size;
	cout<< "Enter the size of the array: ";
	cin>> size;
	int* arr = new int[size];
	cout<< "Enter the elements: \n";
	for (int i = 0; i < size; i++)
	{
		cout<< "[" << i << "]: ";
		cin>> arr[i];
	}
	//int* new_arr;
	arr = MergeSort(arr, size);

	cout<< "THE SORTED ARRAY IS: \n";
	for(int i = 0; i < size; i++)
	{
		cout<< arr[i] << "\t";
	}
	return 0;
}












