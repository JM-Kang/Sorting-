/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   testing.cc                                                               */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/12/08 22:43:14 by JianMing                                 */
/*   Updated: 2017/12/11 18:32:56 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "testing.h"
#include "ft_print.h"

//copy original data 
int		*getNum(int *num, int n)
{
	int i = 0;
	int *temp;
	temp = new int[n];
	while(i < n)
	{
		temp[i] = num[i];
		i++;
	}
	return (temp);
}
		
//uses linear sort to sort a set of data
void	LinearSort(int *num, ofstream &os, int n, int &countC, int &countI)
{
	for(int pos = 0; pos < n - 1; pos++)
	{
		for(int cond = pos + 1; cond < n; cond++)
		{
			countC++;                     //times of comparisons
			if(num[cond] < num[pos])
			{
				int temp = num[cond];
				num[cond] = num[pos];
				num[pos] = temp;
				countI++;				//times of interchanges
			}
		}
	}
}

//uses quick sort to sort a set of data
void	QuickSort(int *num, int low,  int high, int &countC, int &countI)
{
	int i = low;
	int j = high;
	
	Partition(num, i, j, countC, countI);
	if(j > low)                        //if j has not reach lowest side, go to recursion
		QuickSort(num, low, j, countC, countI);
	if(i < high)					   //if i has not reach highest side, go to recursion
		QuickSort(num, i, high, countC, countI);
}

void	Partition(int *num, int &i, int &j, int &countC, int &countI)
{
	int temp = 0;
	int pivot = num[(i + j) / 2];

	while(i <= j)
	{
		while(num[i] < pivot)     //compare pivot to every number from left 
		{
			i++;
			countC++;            //comparisons counter up
		}
		while(num[j] > pivot)	//compare pivot and to every number from right
		{
			j--;
			countC++;			//comparisons counter up
		}
		if(i <= j)				//check if pivot still in between number arrays of i and j
		{
			temp = num[i];
			num[i] = num[j];
			num[j] = temp;
			countI++;			//interchanges counter up
			i++;
			j--;
		}
	}
}

//uses merge sort to sort a set of data
void	MergeSort(int *num, int low, int high, int &countC, int &countI)
{
	int mid = 0;
	if(low < high)			//only if low less than high
	{
		mid = (low + high) / 2;    //devide a set number into two sub sets for the recursion
		MergeSort(num, low, mid, countC, countI);
		MergeSort(num, mid + 1, high, countC, countI);
		Merge(num, low, mid, high, countC, countI);
	}
}

//
void	Merge(int *num, int low, int mid, int high, int &countC, int &countI)
{
	int i = low;
	int j = mid + 1;
	int k = 0;
	int temp[high - low + 1];

	//sort the order and copy the elements to temp[]
	while(i <= mid && j <= high)    
	{
		if(num[i] < num[j])			//compare two sub set data
		{
			temp[k] = num[i];
			countC++;				//comparisons counter up
			countI++;				//interchanges counter up
			i++;
		}
		else
		{
			temp[k] = num[j];
			countC += 2;		//comparisons counter double up because previous comparison false
			countI++;			//interchanges counter up
			j++;
		}
		k++;
	}
	while(i <= mid)			//Copy the remaining elements to temp[]
	{
		temp[k] = num[i];
		countC++;
		countI++;
		k++;
		i++;
	}
	while(j <= high)		//Copy the remaining elements to temp[]
	{
		temp[k] = num[j];
		countC += 2;
		countI++;
		k++;
		j++;
	}
	for(i = low; i <= high; i++)  //copy the elements of temp[] back to num[]
		num[i] = temp[i - low];
}
