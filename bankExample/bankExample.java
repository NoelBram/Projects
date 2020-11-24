/** 
 * Differeny bank types example. 
 * This is an example that uses method overriting, which is an example of run time polymorphism. 
 * 
 * Created 			2020 November, 23, 22:00
 * Last modified 	2020 November, 24, 00:03
 * 
 *  @author NoelBrambila
 */
package Bank;
public class bank{
	float getRateOfInterest() {
		return (float) (0.00);
	}
	public static class sbi extends bank {
		float getRateOfInterest() {
			return (float) (0.08);
		}
	}
	public static class icici extends bank {
		float getRateOfInterest() {
			return (float) (0.07);
		}
	}
	public static class axis extends bank {
		float getRateOfInterest() {
			return (float) (0.09);
		}
	}
}
