import java.util.*;
import java.math.*;
public class main {

	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		BigInteger sum=BigInteger.ZERO;
		for(;;)
		{
			BigInteger a,z;
			BigInteger b=BigInteger.ZERO;
			
			a=input.nextBigInteger();
			sum=sum.add(a);
			if(a.compareTo(b)==0)
			{
				System.out.println(sum);
				System.exit(0);
			}
			
		}

	}

}
