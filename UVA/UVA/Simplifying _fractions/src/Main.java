import java.util.*;
import java.math.BigInteger;
public class Main {

	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		int test=input.nextInt();
		while(test-->0)
		{
			BigInteger a=input.nextBigInteger();
			char c=input.next().charAt(0);
			BigInteger b=input.nextBigInteger();
			BigInteger gcd=a.gcd(b);
			a=a.divide(gcd);
			b=b.divide(gcd);
			System.out.println(a+" / "+ b);
			System.gc();
		}
	}

}
