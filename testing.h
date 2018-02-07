/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   testing.h                                                                */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/12/09 01:08:19 by JianMing                                 */
/*   Updated: 2017/12/09 22:17:38 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTING_H
#define TESTING_H

#include "struct.h"

int		*getNum(int*, int);
void	LinearSort(int*, ofstream&, int, int&, int&);
void	QuickSort(int*, int, int, int&, int&);
void	Partition(int*, int&, int&, int&, int&);
void	MergeSort(int*, int, int, int&, int&);
void	Merge(int*, int, int, int, int&, int&);
#endif
