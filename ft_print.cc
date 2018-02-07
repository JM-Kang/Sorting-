/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_print.cc                                                              */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/12/09 01:10:35 by JianMing                                 */
/*   Updated: 2017/12/11 18:41:21 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include "testing.h"

//print the set of data the has been sorted
void	PrintSort(int num[], int n, ofstream& os, int numComp, int numInter)
{
	int i = 0;
	while(n > i)
	{
		os << num[i] << "\t";
			i++;
		if(i % 10 == 0) 	//ten number per line
			os << endl;
	}
	os << "The number of comparisons: " << numComp <<endl;
	os << "Inerchanged times: " << numInter << endl;
	return;
}

//print the sort info
void	PrintInfo(int i, ofstream &os)
{
	if(i == 0)
		os << endl << "Linear Sort: " << endl;
	else if(i == 1)
		os << endl << "Quick Sort: " << endl;
	else
		os << endl << "Merge Sort: " << endl;
}

//print the order of comprisons
void	PrintComp(int *count, ofstream &os, string comp)
{
	int num = 0;
	string str;
	int *temp;
	temp = new int[3];
	temp = count;		//copy the count address
	
	MergeSort(temp, 0, 2, num, num);   //uses merge sort to sort the counters
	for(int i = 0; i < 3; i++)		   //uses for loop to match the approach of sorting
	{
		if(temp[i] == count[0])        //0 is linear sort
			str = "linear Sort";
		else if(temp[i] == count[1])   //1 is quick sort
			str = "Quick Sort";
		else						   //2 is merge sort
			str = "Merge Sort";

		if(i == 0)				       //each i corespond to order
			os << str << " used most " << comp << endl;
		else if(i == 1)
			os << str << " used " << comp << " was in the middle" << endl;
		else
			os << str << " used least " <<  comp << endl;
	}
	os << endl;
}
