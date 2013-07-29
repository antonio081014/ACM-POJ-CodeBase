//Sat 30 Jan 2010 05:48:22 PM CST 
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	vector<string> v;
	v.clear();
	int N;
	string str;
	cin >> N;
	for(int i=0; i<N; i++)
	{
		cin >> str;
		v.push_back(str);
		str.clear();
	}
	int start;
	int loop;
	char c;
	cin >> start >> c >> loop;
//	cout << start << ", " <<loop << endl;
	start--;
	while(!v.empty())
	{
		int next = (start+loop-1) % v.size();
		cout << v[next] << endl;
		start = next==v.size()-1 ? 0 : next;
		v.erase(v.begin() + next);
	}
	return 0;
}
