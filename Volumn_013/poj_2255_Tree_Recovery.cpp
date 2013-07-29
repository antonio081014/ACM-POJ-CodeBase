//Sun May  2 20:25:12 CDT 2010
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

class Node
{
public:
	char data;
	Node *left;
	Node *right;

	Node(char str)
	{
		data = str;
		left = NULL;
		right = NULL;
	}
};

void reconstruction(Node *&root, string preorder, string inorder)
{
	if (preorder.size() == 0)
		return;

	char tmp = preorder[0];
	root = new Node(tmp);
//	root->data = tmp;
	if (preorder.size() == 1 && inorder.size() == 1)
	{
		root->left = NULL;
		root->right = NULL;
		return;
	}

	size_t pos = inorder.find(tmp);
	string inorderA = inorder.substr(0, pos);
	string inorderB = inorder.substr(pos + 1);
	string preorderA = preorder.substr(1, pos);
	string preorderB = preorder.substr(pos + 1);

	reconstruction(root->left, preorderA, inorderA);
	reconstruction(root->right, preorderB, inorderB);

	return;
}

void postorder(Node *root)
{
	if (root->left != NULL)
		postorder(root->left);
	if (root->right != NULL)
		postorder(root->right);
	cout << root->data;
	return;
}

int main(int argc, const char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	//preorder, inorder;
	string str1, str2;
	while (cin >> str1 >> str2)
	{
//		cout << str1 << ", " << str2 << endl;
		Node *root;
		root = NULL;
		reconstruction(root, str1, str2);
		postorder(root);
		cout << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
