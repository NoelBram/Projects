package absBank;

public abstract class bankTest extends Bank{
	public static void main(String args[]) {
		Bank myBank = new sbi();
		Bank mySecondBank = new pnb();
		System.out.println(myBank.getRateOfInterest());
		System.out.println(mySecondBank.getRateOfInterest());
	}
}