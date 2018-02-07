/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.cc                                                                  */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/12/06 12:09:16 by JianMing                                 */
/*   Updated: 2017/12/11 18:07:01 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft_print.h"
#include "testing.h"

int	main(void)
{
	ifstream	c_cin;
	ofstream	os;
	Set			*ca;
	int			*temp;
	int			*countC;
	int			*countI;
	countC = new int[3];
	countI = new int[3];

	c_cin.open("data.txt");
	os.open("statemet.txt");

	while(c_cin)
	{
		ca = new Set(c_cin, os);

		//if no value in the array, out of while loop
		if(!ca->num[0])
			break;

		//using for loop to go through three sorts
		for(int i = 0; i < 3; i++)
		{
			int	countComp = 0;
			int countInter = 0;
			temp = getNum(ca->num, ca->size);        //copy the orginal data
			switch(i)
			{	
				case 0:	LinearSort(temp, os, ca->size, countComp, countInter);
				case 1:	QuickSort(temp, 0, ca->size - 1, countComp, countInter);
				case 2:	MergeSort(temp, 0, ca->size - 1, countComp, countInter);
				default: break;
			}
			PrintInfo(i, os);
			PrintSort(temp, ca->size, os, countComp, countInter);
			countC[i] = countComp;			 //put 3 counters of comparisons into an arrays
			countI[i] = countInter;			 //put 3 counters of interchanges into an arrays 
		}
		os << endl;
		PrintComp(countC, os, "comparisons");    //print the order of comparisons of the sorting
		PrintComp(countI, os, "interchanges");   //print the order of interchagees of the sorting
		ca = NULL;
		delete ca;	
	}
	c_cin.close();
	os.close();
	return (0);
}




