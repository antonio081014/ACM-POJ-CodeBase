//Initially I tried to use dp to implement this problem. But it keep reporting runtime error, where I can
//hardly find any breakthrough, even debug were used.
//Finally, an easy simulation was used to implement this.

//Wed Mar 10 15:31:27 CST 2010
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

//To get the problem in good time you must create an array with size 1000000.
//Then using recursion with memorization try to not compute any value more than once.

//vector<unsigned int> v(10000001, 0);
//To calculate the length of the circle for the number idx.

unsigned int generate(unsigned int idx)
{
 if (idx == 1)
 {
  return v[idx] = 1;
 }
 // When the value have been calculated, access it directly.
 if (v[idx] > 0)
  return v[idx];
 // v[idx] = 1 + generate(idx % 2 == 0 ? idx / 2 : 3 * idx + 1);
 if (idx % 2 == 0)
 {
  return (v[idx] = 1 + generate(idx / 2));
 }
 else
 {
  return (v[idx] = 1 + generate(3 * idx + 1));
 }
 // return v[idx];
}

// unsigned long : 32 bits integer.
// long long : 64 bits integer.
int main(int argc, char* argv[])
{
 freopen("input.in", "r", stdin);
 freopen("output.out", "w", stdout);
 // for (i = 0; i < (int) v.size(); i++)
 //  v[i] = 0;
 // for (i = 1; i < 1000000; i++)
 // {
 //  v[i] = generate(i);
 //  cout << i << ", " << v[i] << endl;
 // }
 int a, b;
 while (cin >> a >> b)
 {
  int mmax = 0;
  int start = min(a, b);
  int end = max(a, b);
  for (int i = start; i <= end; i++)
  {
   int count = 1;
   int n = i;
   while (n != 1)
   {
    count++;
    if (n % 2 == 0)
     n /= 2;
    else
     n = 3 * n + 1;
   }
   mmax = max(mmax, count);
  }
  cout << a << " " << b << " " << mmax << endl;
 }
 fclose(stdin);
 fclose(stdout);
 return 0;
}
