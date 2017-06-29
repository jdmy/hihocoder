#include<cstdio>
#include<cstring>
#include <iomanip>
#include<iostream>
#include<algorithm>
#define MAXN 26
#define DEBUG
using namespace std;
int n, m;
char pat[10005], ori[1000005];
int rl[MAXN + 1];
//bool dp[MAXN+1][MAXN+1],tmp;
int nexts[10005];
void Next(char* str) {
	nexts[0] = 0; nexts[1] = 0;
	//cout << "-1\t";
	for(int i=1;i<strlen(str);i++) {
		int j = nexts[i];
		while (j&&str[j] != str[i]) {
			j = nexts[j];
		}
		nexts[i + 1] = (str[j] == str[i]) ? j + 1 : 0;
		//cout << nexts[i] << "\t";
		/*i++;*/
	}
	//cout << endl;
}
void Kmp(char *pattern, char *origin) {
	int i = 0, j = 0, cnt = 0;
	int ol = strlen(origin),pl= strlen(pattern);
	Next(pattern);
	for (i = 0; i < ol;i++) {

		while (j && origin[i] != pattern[j]) {
			j = nexts[j];
			
		}
		if (origin[i] == pattern[j]) {
			j++;
		}
		if (j == pl) {
			//cout << "finded:" << i - j + 1 << endl;
			//i = i - nexts[j] - 1;
			j = nexts[j];
			cnt++;
		}
		//i++;
	}
	/*printf("%d\n", cnt);*/
	cout << cnt << endl;
}
int  main() {
#ifdef DEBUG
	freopen("in.txt", "r", stdin);

	freopen("out.txt", "w", stdout);
#endif // DEBUG
	cin >> n;
	while (n--) {
		scanf("%s", pat);
		scanf("%s", ori);
		Kmp(pat, ori);
	}
#ifdef DEBUG
	fclose(stdin);

	fclose(stdout);
#endif // DEBUG


}