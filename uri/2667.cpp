#include <bits/stdc++.h>
int main () {
	char s[101]; scanf("%s", s);
	int cont = 0;
	for (int i = 0; s[i] != '\0'; i++) cont += s[i]-'0';
	printf("%d\n", cont%3);
}
