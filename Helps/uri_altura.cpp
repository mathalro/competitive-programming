#include <bits/stdc++.h>

using namespace std;

int main(){
	//ios_base::sync_with_stdio(false);
	int nc;
	scanf("%d", &nc);
	while(nc--){
		int n;
		scanf("%d", &n);		
		vector<int> v;
		while(n--){
			int x;
			scanf("%d", &x);
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		int i = 0;
		for(i = 0; i < v.size()-1; i++){
			printf("%d ", v[i]); 
		}
		printf("%d\n", v[i]);
	}
	return 0;
}
