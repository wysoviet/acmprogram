void sort(int *a, int n){
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1]) 
			a[j] ^= a[j + 1] ^= a[j] ^= a[j + 1];
}

