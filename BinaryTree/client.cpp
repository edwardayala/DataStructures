#include "tree.h"

int main()
{
	Tree bst;
	
	int isbns[26];
	for (int i = 0; i < 26; i++)
	{
		isbns[i] = i + 1;
	}
	char alpha[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	for (int i = 0; i < 26; i++)
	{
		Node * bk = new Node(isbns[i]);
		bst.insert(bk);
	}

	bst.print();
	system("pause");
}
