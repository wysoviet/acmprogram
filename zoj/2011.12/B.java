import java.util.*;
import java.math.*;

public class B{
 	static BigInteger a1, a2, r1, r2, x, y, d, m;
	static int n;
	static boolean flag;

	static BigInteger exgcd(BigInteger a, BigInteger b) {
		if (b.equals(BigInteger.ZERO) == true) {
			x = BigInteger.ONE;
			y = BigInteger.ZERO;
			return a;
		}
		BigInteger t;
		t = y; y = x; x = t;
		BigInteger r = exgcd(b, a.mod(b));
		t = y; y = x; x = t;
		y = y.subtract(x.multiply(a.divide(b)));
		return r;
	}

	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		BigInteger a[] = new BigInteger[110];
		BigInteger r[] = new BigInteger[110];
		BigInteger num, ll, rr, lcm, gcd;

		while (cin.hasNext()){
			n = cin.nextInt();
			for (int i = 0; i < n; i++) 
				a[i] = cin.nextBigInteger();
			for (int i = 0; i < n; i++)
				r[i] = cin.nextBigInteger();
			ll = cin.nextBigInteger(); 
			rr = cin.nextBigInteger();
			a1 = a[0]; r1 = r[0].mod(a[0]);lcm = a1;
			flag = true;
			for (int i = 1; i < n; i++){
			      a2 = a[i]; r2 = r[i];
			      gcd = exgcd(lcm, a2);
			      lcm = lcm.divide(gcd).multiply(a2);
			      d = exgcd(a1, a2);
			      if (r1.subtract(r2).mod(d).equals(BigInteger.ZERO) == false) {
				      flag = false;
				      continue;
			      }
			      x = x.multiply(r2.subtract(r1).divide(d));
			      a2 = a2.divide(d);
			      x = x.mod(a2);
			      r1 = r1.add(a1.multiply(x));
			      a1 = a1.multiply(a2);
			      r1 = r1.mod(a1);
			 }
			 if (flag == false || r1.compareTo(rr) > 0) { System.out.println(0); continue;} 
			 r2 = r1;
			 if (r1.compareTo(ll) < 0) r1 = r1.add(ll.subtract(r1).divide(lcm).multiply(lcm));
			 if (r1.compareTo(ll) < 0) r1 = r1.add(lcm);
			 r2 = r2.add(rr.subtract(r2).divide(lcm).multiply(lcm)); 
			 num = r2.subtract(r1).divide(lcm).add(BigInteger.ONE);
			 if (num.compareTo(BigInteger.ZERO) <= 0) { System.out.println(0); continue;}
			 System.out.println(num);
			 System.out.print(r1);
			 for (int i = 1; i < 100; i++){
				num = num.subtract(BigInteger.ONE);
				if (num.equals(BigInteger.ZERO) == true) break;
			 	r1 = r1.add(lcm);
			 	System.out.print(" "+r1);
			 }
			 System.out.println();
		 }
	}
}

