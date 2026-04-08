// 트리순회(백준, 이진트리순회)
// https://www.acmicpc.net/problem/1991
// 전위 순회, 중위 순회, 후위 순회

#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<char, pair<char, char>> tree;

// preorder  traersal, root -> left subtree -> right subtree
void preorder(char node)
{
	if (node != '.')	// 노드가 null이 아니라면
	{
		cout << node;
		preorder(tree[node].first);	// left subtree 순회
		preorder(tree[node].second);	// right subtree 순회
	}
}

// inorder traversal, left subtree -> root -> right subtree
void inorder(char node)
{
	if (node != '.')	// 노드가 null이 아니라면
	{
		inorder(tree[node].first);		// left subtree 순회
		cout << node;
		inorder(tree[node].second);		// right subtree 순회
	}
}

void postorder(char node)
{
	if (node != '.')	// 노드가 null이 아니라면
	{
		postorder(tree[node].first);		// left subtree 순회
		postorder(tree[node].second);		// right subtree 순회
		cout << node;
	}
}

int main(void)
{
	int N;

	// 노드의 개수 입력
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		char node, left, right;
		cin >> node >> left >> right;

		tree[node] = { left, right };
	}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
}