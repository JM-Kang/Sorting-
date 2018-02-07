/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   struct.cc                                                                */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/12/06 11:54:54 by JianMing                                 */
/*   Updated: 2017/12/10 00:38:45 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

Set::Set(void)
{
	str = " ";
	num[0] = 0;
	size = 0;
	n = 1;
}

Set::Set(ifstream &cin, ofstream &os)
{ 
	int i = 0;
	char type = ' ';
	cin >> n;
	cin.get(type);
	cin >> size;
	getline(cin, str);
	if(n)
	{
		os << "*******************************************************";
		os << endl << n << type << " " << size << str << endl;
	}
	while(i < size)
	{
		cin >> num[i];
		os << num[i] << "\t";
		i++;
		if(i % 10 == 0 && i < size - 1)
			os << endl;
	}
	os << endl;
}

