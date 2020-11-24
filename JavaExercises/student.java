package ClassRoom;

class student {
	private String className;
	private String studentName;
	private String studentId; 
	private String collegeName; 
	private String address; 
	
	public void setClassName(String s) {
		className = s;
	}
	public void setStudentName(String s) {
		studentName = s;
	}
	public void setStudentId(String s) {
		studentId = s;
	}
	public void setCollegeName(String s) {
		collegeName = s;
	}
	public void setAddress(String s) {
		address = s;
	}
	
	public String getClassName() {
		return className;
	}
	public String getStudentName() {
		return studentName;
	}
	public String getStudentId() {
		return studentId;
	}
	public String getCollegeName() {
		return collegeName;
	}
	public String getAddress() {
		return address;
	}
}