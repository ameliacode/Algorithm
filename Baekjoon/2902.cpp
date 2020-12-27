#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	string str;
	cin >> str;
	
	istringstream ss(str);
	string buffer;
	vector<string> algo;

	while (getline(ss, buffer, '-'))
	{
		algo.push_back(buffer);
	}

	for (int i = 0; i < algo.size(); i++)
	{
		cout << algo[i][0];
	}

	return 0;
}
