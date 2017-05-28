#include<cstdio>
#include<cstring>
#include <iomanip>
#include<iostream>
#include<algorithm>
#define MAXN 26
#define DEBUG
using namespace std;
int n, m;
char s[11];
int rl[MAXN + 1];
//bool dp[MAXN+1][MAXN+1],tmp;

struct node {
	int n; //通过该路径的词条数
	node * nd[MAXN];
};
node t[1000000+5];
int all = 0;
node * create() {
	node * tmp = &t[all++];
	tmp->n = 1;
	for (int i = 0; i < 26; i++) {
		tmp->nd[i] = NULL;
	}
	return tmp;
}
void insert(node ** proot,char* str) {
	node * tmp = *proot;
	int i = 0, k;
	while (str[i]) {
		k = str[i] - 'a';
		if (tmp->nd[k]) {
			tmp->nd[k]->n++;
		}
		else {
			tmp->nd[k] = create();
		}

		tmp = tmp->nd[k];
		i++;
	}
}
int search(node ** proot, char* str) {
	if (proot == NULL)
		return 0;
	node *tmp = *proot;
	int i = 0,k;
	while (str[i]) {
		k = str[i] - 'a';
		if (tmp->nd[k]) {
			tmp = tmp->nd[k];
		}
		else
			return 0;
		i++;
	}
	return tmp->n;
}
int  main() {
#ifdef DEBUG
	freopen("in.txt", "r", stdin);

	freopen("out.txt", "w", stdout);
#endif // DEBUG
	//char *st;
	while (scanf("%d", &n) != EOF) {
		node * tt = create();
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			insert(&tt, s);
		}
		cin >> n;
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			cout << search(&tt, s) << endl;
		}
	}
#ifdef DEBUG
	fclose(stdin);

	fclose(stdout);
#endif // DEBUG


}