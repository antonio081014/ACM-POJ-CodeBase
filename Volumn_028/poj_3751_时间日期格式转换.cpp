//Fri 29 Jan 2010 01:44:27 AM CST 
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	string str;
	int T;
	cin >> T;
	for(int i=0; i<T; i++)
	{
		string output;
		cin >> str;
		output += str.substr(5,5);
		output += "/";
		output += str.substr(0,4);
		output += "-";
		//output += str.substr(11);
		int time = 10 * (str[11]-'0') + (str[12]-'0');
		if(time == 0)
		{
			output += "12";
			output += str.substr(13) + "am";
		}
		else if(time >0 && time <12)
		{
			output += str.substr(11) + "am";
		}
		else if(time == 12)
		{
			output += str.substr(11) + "pm";
		}
		else
		{
			time -= 12;
			int d = time / 12;
			int dd = time % 12;
			output += ('0' + d);
			output += ('0' + dd);
			output += str.substr(13) + "pm";
		}
		cout << output << endl;
	}
	return 0;
}
