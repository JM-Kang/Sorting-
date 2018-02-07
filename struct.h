/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   struct.h                                                                 */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/12/06 11:51:07 by JianMing                                 */
/*   Updated: 2017/12/09 02:01:14 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Set
{
	string	str;;
	int		size;
	int		n;
	int		num[100];
	Set();
	Set(ifstream&, ofstream&);
};
#endif
