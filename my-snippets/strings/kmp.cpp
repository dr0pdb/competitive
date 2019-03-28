#define MAX_N 100010

char T[MAX_N], P[MAX_N];
int prefix[MAX_N], n, m; // n = size of text, m = size of pattern.

void kmpPreprocess() {
	int i = 0, j = -1; prefix[0] = -1;

	while (i < m) {
		while (j >= 0 && P[i] != P[j]) j = prefix[j];
		i++; j++;
		prefix[i] = j;
	} 
}

void kmpSearch() {
	int i = 0, j = 0; 

	while (i < n) {
		while (j >= 0 && T[i] != P[j]) j = prefix[j];
		i++; j++;
		if (j == m) {
			// printf("P is found at index %d in T\n", i - j);
			j = prefix[j]; // prepare j for the next possible match
		}
	}
}