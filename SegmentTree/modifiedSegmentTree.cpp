#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	int value = 0;
	int pos_value = 0;
	int st;
	int end;
	TreeNode(int s, int e) : st(s), end(e) {}
};

TreeNode* build(vector<int> vec, int start, int end) {
	TreeNode* node = new TreeNode(start, end);

	if (start == end) {
		node->value = vec[start];
		node->pos_value = vec[start] > 0 ? vec[start] : 0;
	}
	else {
		int mid = (start + end) / 2;
		node->left = build(vec, start, mid);
		node->right = build(vec, mid + 1, end);
		node->value = node->left->value + node->right->value;
		node->pos_value = node->left->pos_value + node->right->pos_value;
	}
	return node;
}

void update1(TreeNode* head, int l, int r, int x) {
	if ((head->st == head->end) && (head->st <= r) && (head->st >= l)) {
		head->value += x;
		if (head->value > 0) head->pos_value = head->value;
	}
	else {
		int mid = (head->st + head->end) / 2;
		if (mid >= r) {
			update1(head->left, l, r, x);
		}
		else if (mid < l) {
			update1(head->right, l, r, x);
		}
		else {
			update1(head->left, l, r, x);
			update1(head->right, l, r, x);
		}
		head->value = head->left->value + head->right->value;
		head->pos_value = head->left->pos_value + head->right->pos_value;
	}
}

int CORR = 0;

void update2(TreeNode* head, int i, int x) {
	if (head->st != head->end) {
		int mid = (head->st + head->end) / 2;
		if (mid >= i) update2(head->left, i, x);
		else update2(head->right, i, x);
		head->pos_value -= CORR;
		head->value -= x;
	}
	else {
		if (head->value < x) {
			CORR = head->value;
			head->pos_value = 0;
		}
		else {
			CORR = x;
			head->pos_value -= x;
		}
		head->value -= x;
	}
}

int sum(TreeNode* head, int l, int r) {
	if (l <= head->st && head->end <= r)
		return head->pos_value;

	if (l > head->end || r < head->st)
		return 0;

	return sum(head->left, l, r) + sum(head->right, l, r);
}