class Stack {
    private int size;
    private int[] stack;

    // default Constructor
    Stack() {

    }

    Stack(int size) {
        this.size = size;
    }
    public void displayDetails() {
        for (int index = 0; index < stack.length; index++) {
            System.out.println("ID\t\t:" + this.empID);
            
        }
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
