#include <bits/stdc++.h>

using namespace std;

class GravityPuzzleEasy {
    public:
	vector <string> solve(vector <string> board);
};

vector<string> GravityPuzzleEasy::solve(vector<string> board) {
    vector<string> tmp;
    for (int j = 0; j < board[0].size(); j++) {
        string s;
        for (int i = 0; i < board.size(); i++) {
            if (board[i][j] == '.') {
                s = "." + s;
            } else {
            	s = s + "#";
            }
       	}
        tmp.push_back(s);
   	}
    vector<string> v(tmp[0].size());
    
		//for (int i = 0; i < tmp.size(); i++) cout << tmp[i] << endl;
		//cout << endl;
		for (int j = 0; j < tmp[0].size(); j++) {
			for (int i = 0; i < tmp.size(); i++) {
				v[j] += tmp[i][j];
			}
		}

		//for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
    
    return v;
}

int main () {

	vector<string> v;
	
	v.push_back("##");
  v.push_back(".#");
	v.push_back("#.");

	GravityPuzzleEasy g;
	
	vector<string> ans = g.solve(v);	

	return 0;
}
