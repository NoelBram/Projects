/**
 * Create an abstract class called Bank with an abstract method called getRateOfInterest();
 * Create two subclasses called SBI - 7% and PNB - 5% as two banks that extend the abstract class Bank.
 * Implement different functionalities for the getRateOfInterest() method in the SBI and PNB classes 
 * through the concept of method overriding and print out the interest rate inside the main() 
 * method created separately in a test class called TestBank
 * 
 * @author NoelBrambila
 */

package absBank;

public abstract class Bank{
	public abstract float getRateOfInterest();
	
	public static class sbi extends Bank{
		public float getRateOfInterest() {
			return (float)(0.07);
		}
	}
	public static class pnb extends Bank{
		public float getRateOfInterest() {
			return (float)(0.05);
		}
	}
}
