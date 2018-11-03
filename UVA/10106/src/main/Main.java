package main;

import java.util.*;
import java.math.*;
public class Main {

	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		BigInteger a,b,c;
		while(input.hasNext()==true)
		{
			a=input.nextBigInteger();
			b=input.nextBigInteger();
			c=a.multiply(b);
			System.out.println(c);
		}

	}

}
