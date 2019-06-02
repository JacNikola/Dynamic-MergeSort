#include<iostream>
#include<cmath> //for ceil()
using namespace std;


void SplitList(int* , int* , int* , int , int );
int* MergeLists(int* , int* , int );
int* MergeSort(int* , int )

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
	arr = MergeSort(arr, size);

	cout<< "THE SORTED ARRAY IS: \n";
	for(int i = 0; i < size; i++)
	{
		cout<< arr[i] << "\t";
	}
	return 0;
}

//FUNCTION TO MERGE_SORT
int* MergeSort(int* arr, int size)
{
	if (size - 1 == 0) //i.e. if only one item in the array
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

//FUNCTION TO SPLIT AN ARRAY INTO TWO SUB ARRAYS
void SplitList(int* arr, int* arrL, int* arrR, int size, int mid)
{
	for (int i = 0; i < mid; i++)
	{
		arrL[i] = *arr; //populating the left sub array
		arr++;
	}
	
	for (int i = 0; i < size - mid; i++)
	{
		arrR[i] = *arr; //populating the right sub array
		arr++;
	} 
}

//FUNCTION TO MERGE THE LEFT AND RIGHT SUB ARRAYS IN A SORTED MANNER
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













