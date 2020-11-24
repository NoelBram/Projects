package Bank;

import java.io.*; 
import java.util.*; 
import Bank.bank.axis;
import Bank.bank.icici;
import Bank.bank.sbi;

public class bankTest{
	public static void main(String args[]) {
		bank obj = new bank();
		sbi obj1 = new bank.sbi();
		icici obj2 = new bank.icici();
		axis obj3 = new bank.axis();
		
		System.out.printf(" The interest rate of noBank is %f %n", obj.getRateOfInterest());
		System.out.printf(" The interest rate of SIB is %f %n", obj1.getRateOfInterest());
		System.out.printf(" The interest rate of ICICI is %f %n", obj2.getRateOfInterest());
		System.out.printf(" The interest rate of AXIS is %f %n", obj3.getRateOfInterest());
	}
}