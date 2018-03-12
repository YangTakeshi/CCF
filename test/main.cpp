#include<string>
#include<vector>
#include<iostream>
#include<map>


using namespace std;

void parser(vector<map<char, pair<int, string> > > &arr) {
	string args;
	cin >> args;
	string::iterator it;
	char per;
	map<char, pair<int, string> > m;
	for (it = args.begin(); it != args.end(); it++) {
		if (*it != ':'){
			m.insert(pair<char, pair<int, string> >(*it, pair<int, string>(0, "")));
		}
		else {
			m[per].first = 1;
		}
		per = *it;
	}
	int n,i;
	cin >> n;
	for (i = 0; i < n; i++) {
		map<char, pair<int, string> > cm = m;
		string line;
		vector<string> args;
		while(line.size()==0)
		getline(cin,line);
		int i,cur = 0;
		for (i = 0; i <= line.size(); i++) {
			if (line[i] == ' '|| i==line.size()) {
				args.push_back(line.substr(cur, i-cur));
				cur = i+1;
			}
		}
		vector<string>::iterator itS;
		bool flag = false, per = false;
		for(itS = args.begin();itS!=args.end();itS++) {
			string temp;
			map<char, pair<int, string> > ::iterator it;
			temp = *itS;
			it = cm.find(temp[1]);
			if (it != cm.end()&&(temp.size()<=2)) {
				if ((it->second).first == 1|| (it->second).first == 3) {
					string sub;
					sub = *(itS + 1);
					if (sub[0] == '-')continue;
					(it->second).first = 3;
					(it->second).second = sub;
					per = true;
				}
				else {
					(it->second).first = 2;
					per = false;
				}
			}
			else if ((flag&&!per)||(!flag&&per)) {
				break;
			}
			else {
				flag = true;
				per = false;
			}
		}
		arr.push_back(cm);
	}
}


void output(vector<map<char, pair<int, string> > > &arr) {
	vector<map<char, pair<int, string> > >::iterator itArr;
	int cur = 1;
	for (itArr = arr.begin(); itArr != arr.end(); itArr++,cur++) {
		cout << "Case " << cur<<":";
		map<char, pair<int, string> >::iterator itMap;
		for (itMap = itArr->begin(); itMap != itArr->end(); itMap++) {
			if (itMap->second.first == 2) {
				cout << " -" << itMap->first;
			}
			else if (itMap->second.first == 3) {
				cout << " -" << itMap->first << " " << itMap->second.second;
			}
		}
		cout << endl;
	}
}



int main()
{
	vector<map<char, pair<int, string> > > arr;
	parser(arr);
	output(arr);
    return 0;
}

