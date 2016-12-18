#include<stdio.h>
#include<map>
#include<vector>

#define ym2int(a,b) (a*12+b)

using namespace std;

vector<map<string, int> > counts;

int main()
{

	int st, ed, y, m, d, cnt, count;
	char content[105] = { 0, };

	scanf_s("%d-%d, ", &y, &m); st = ym2int(y, m);
	scanf_s("%d-%d", &y, &m);  ed = ym2int(y, m);

	cnt = ed - st + 1;
	counts.resize(cnt);

	while (scanf_s("%d-%d-%d ,", &y, &m, &d) != EOF)
	{
		char contents[1005];
		int val = ym2int(y, m);
		int len;

		fgets(contents, 1005, stdin);
		len = strlen(contents);
		count = 0;

		if (val < st || ed < val) continue;

		int i = 0;
		while (contents[i] == ' ') i++; // trim
		for (int j = 0; i < len; i++, j++) {
			if (contents[i] == ' ' || contents[i] == ',') break;
			content[j] = contents[i];
		}

		i = len - 1;
		while (contents[i] == ' ' || contents[i] == '\n') i--;
		for (int j = 1; i >= 0; i--, j *= 10) {
			if (contents[i] == ' ' || contents[i] == ',') break;
			count += (contents[i] - '0')*j;
		}

		if (count == 0) continue;

		string tmp = string(content);
		counts[val - st][tmp] += count;
	}

	for (int i = cnt - 1; i >= 0; i--)
	{
		if (counts[i].size() == 0) continue;

		int y = (i + st - 1) / 12, m = (i + st) % 12;
		if (m == 0) m = 12;

		printf("%d-%02d,", y, m);
		for (auto it : counts[i])
			printf(" %s, %d", it.first.c_str(), it.second);
		printf("\n");
	}

	return 0;
}