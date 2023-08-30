class Employee {
    private int empID;
    private String empName;
    private String empDesignation;
    private double empSalary;

    // default Constructor
    Employee() {

    }

    Employee(int ID, String Name, String Designation, double Salary) {
        this.empID = ID;
        this.empName = Name;
        this.empDesignation = Designation;
        this.empSalary = Salary;
    }
    public void setDetails(int ID, String Name, String Designation, double Salary) {
        this.empID = ID;
        this.empName = Name;
        this.empDesignation = Designation;
        this.empSalary = Salary;
    }
    public void displayDetails() {
        System.out.println("ID\t\t:" + this.empID);
        System.out.println("Name\t\t:" + this.empName);
        System.out.println("Designation\t:" + this.empDesignation);
        System.out.println("Salary\t\t:" + this.empSalary);
    }

    public static int searchEmployeeByID(Employee[] emp, int ID) {
        for (int i = 0; i < emp.length; i++) {
            if (emp[i].empID == ID) {
                return i;
            }
        }
        return -1;
    }

    public Boolean isIDEqual(int ID) {
        if (this.empID == ID) {
            return true;
        }
        return false;
    }

    public void incrementSalary(double percent) {
        this.empSalary = this.empSalary * (1 + (percent / 100));
    }
}
