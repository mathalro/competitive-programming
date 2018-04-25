#include <bits/stdc++.h>

using namespace std;

int main () {

	int n; 

	while (scanf("%d", &n) != EOF) {
		stack<long long> s;
		queue<long long> q;
		bool e1 = true, e2 = true, e3 = true;
		priority_queue<long long> pq;
		for (int i = 0; i < n; i++) {
			unsigned long long a, b; scanf("%llu %llu", &a, &b);
			if (a == 1) {
				s.push(b);
				q.push(b);
				pq.push(b);
			} else {
				unsigned long long t1 = s.top(); s.pop();
				unsigned long long t2 = q.front(); q.pop();
				unsigned long long t3 = pq.top(); pq.pop();
				if (t1 != b) e1 = false;
				if (t2 != b) e2 = false;
				if (t3 != b) e3 = false;
			}
		}

		if (e1 && !e2 && !e3) {
			printf("stack\n");
		} else if (!e1 && e2 && !e3) {
			printf("queue\n");
		} else if (!e1 && !e2 && e3) {
			printf("priority queue\n");
		} else if (!e1 && !e2 && !e3) {
			printf("impossible\n");
		} else {
			printf("not sure\n");
		}
	}

	return 0;
}
