//Fri 29 Jan 2010 01:11:33 AM CST 
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	while(str != "ENDOFINPUT")
	{
		if(str == "START")
		{
			string input = "";
			string output = "";
			getline(cin, input);
			while(input != "END")
			{
				int N = input.size();
				for(int i=0; i<N; i++)
				{
					if(isalpha(input[i]))
						output += (input[i] - 5 + 26 - 'A') % 26 + 'A';
					else
						output += input[i];
				}
				getline(cin, input);
			}
			cout << output << endl;
		}
		getline(cin, str);
	}
	return 0;
}
