package ClassRoom;

public class studentTest{
	public static void main(String args[]) {
		student newStudent = new student();
		newStudent.setClassName("CSE 455");
		newStudent.setStudentName("Noah Bram");
		newStudent.setCollegeName("CSUSB");
		newStudent.setAddress("San Bernardion, Ca");
		
		System.out.println(newStudent.getClassName());
		System.out.println(newStudent.getStudentName());
		System.out.println(newStudent.getCollegeName());
		System.out.println(newStudent.getAddress());
	}
}