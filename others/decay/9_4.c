int strcmp(char *s, char *t){
	int ns = strlen(s), nt = strlen(t);
	if (ns > nt) return 1;
	if (ns < nt) return -1;
	for (;*s == *t && *s; s++, t++) ;
	if (*s > *t) return 1;
	if (*s < *t) return -1;
	return 0;
}

