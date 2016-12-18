#include<iostream>
#include<string>
#include<algorithm>

#define MAX_LEN 150

using namespace std;

int main()
{
	string strEmail, strPhone;
	char* ban = " ()";
	bool tmp = false;

	getline(cin, strEmail);
	getline(cin, strPhone);

	for (int i = 0; i < 3; i++) strEmail.erase(std::remove(strEmail.begin(), strEmail.end(), ban[i])),
		strPhone.erase(std::remove(strPhone.begin(), strPhone.end(), ban[i]));

	cout << "E:" << strEmail[2] << "*****";
	for (int i = 3; i < strEmail.size(); i++) {
		if (i != strEmail.size() - 1 && strEmail[i + 1] == '@') tmp = true;
		if (tmp) cout << strEmail[i];
	}
	cout << endl;

	if (strPhone.size() == 12) {
		cout << "P:***-***-";
		for (int i = 8; i < 12; i++) cout << strPhone[i];
		cout << endl;
	}
	else {
		cout << "P:+";
		int cnt = strPhone.size() - 3 - 10;
		for (int i = 0; i < cnt; i++) cout << "*";
		cout << "-***-***-";
		for (int i = 9 + cnt; i < 9 + cnt + 4; i++) cout << strPhone[i];
		cout << endl;
	}

}