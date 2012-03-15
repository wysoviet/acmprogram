/*
TASK:buylow
LANG:JAVA
ID:wysovie1
*/

import java.util.*;
import java.math.*;
import java.io.*;

public class buylow{
	public static void main(String[] args) throws IOException{
		BufferedReader f = new BufferedReader(new FileReader("buylow.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("buylow.out")));
		StringTokenizer st = new StringTokenizer(f.readLine());
		int l[] = new int[5010];
		int a[] = new int[5010];
		BigInteger s[] = new BigInteger[5010];
		int n, ml;
		BigInteger ans;

		n = Integer.parseInt(st.nextToken());
		for (int i = 1; i <= n; i++) 
			a[i] = Integer.parseInt(st.nextToken());

		a[0] = 0xf7777777;
		l[0] = 0; 
		s[0] = BigInteger.ONE;

		ans = BigInteger.ZERO;
		ml = 0;
		for (int i = 1; i <= n; i++) {
			int tl = 0;
			BigInteger ts = BigInteger.ZERO;
			for (int j = 0; j < i; j++) if (a[j] > a[i])
				if (l[j] + 1 > tl) {
					tl = l[j] + 1;
					ts = s[j];
				}else if (l[j] + 1 == tl)
					ts = ts.add(s[j]);
			for (int j = 0; j < i; j++)
				if (a[j] == a[i] && l[j] == l[i])
					ts = ts.subtract(s[j]);
			
			l[i] = tl;
			s[i] = ts;
			if (tl > ml) {
				ml = tl;
				ans = ts;
			}else if (tl == ml) ans = ans.add(ts);
		}

		out.println(ml);	
		out.close();
		System.exit(0);

	}
}

