#include <bits/stdc++.h>
#define endl '\n'
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int N = 2e3+10;

struct node{
	node *left, *right;
	char c;
	node(char tmp){
		c = tmp;
		left = NULL;
		right = NULL;
	}
};

map<char,string> ans;
void dfs(node *root, string s){
	if(root== NULL){
		return;
	}
	if(root->c != '\0'){
		ans[root->c] = s;
	}
	dfs(root->left, s + "0");
	dfs(root->right, s + "1");
}

int main(){
	FIO;
	multiset <pair<int, node* > > m;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		char c;
		int val;
		cin >> c >> val;
		m.insert({val, new node(c)});
	}
	while(m.size() > 1){
		auto it1 = m.begin();
		auto it2 = ++m.begin();
		int f = (it1->first) + (it2->first);
		node *root = new node('\0');
		root->left = it1->second;
		root->right = it2->second;
		m.erase(it1);
		m.erase(it2);
		m.insert({f, root});
	}
	node *root = m.begin() -> second;
	dfs(root, "");
	for(auto it : ans){
		cout << it.first << " " << it.second << endl;
	}
	return 0;
}
