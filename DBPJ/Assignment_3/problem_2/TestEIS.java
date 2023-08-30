import java.util.Scanner;

class TestEIS {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Number of Employees");
        int size = sc.nextInt();
        Employee employees[] = new Employee[size];
        for (int i = 0; i < employees.length; i++) {
            System.out.println("Enter " + (i + 1) + " Employee ID");
            int id = sc.nextInt();
            System.out.println("Enter " + (i + 1) + " Employee Name");
            String name = sc.next();
            System.out.println("Enter " + (i + 1) + " Employee Designation");
            String Designation = sc.next();
            System.out.println("Enter " + (i + 1) + " Employee Salary");
            double salary = sc.nextDouble();
            employees[i] = new Employee(id, name, Designation, salary);
        }

        for (int i = 0; i < employees.length; i++) {
            System.out.println("Employee " + (i + 1) + " Details:");
            employees[i].displayDetails();
        }
        int task = 4;
        do {
            System.out.println("Enter the following function");
            System.out.println("1. Search Employee");
            System.out.println("2. Hike Salary");
            System.out.println("3. Display");
            System.out.println("4. Exit");
            task = sc.nextInt();
            switch (task) {
                case 1:
                    System.out.println("Enter Employee ID to search");
                    int searchid = sc.nextInt();
                    System.out.print("Employee with ID " + searchid);
                    int emp_id = Employee.searchEmployeeByID(employees, searchid);
                    if (emp_id >= 0) {
                        System.out.println(" exist");
                        employees[emp_id].displayDetails();
                    } else {
                        System.out.println(" does not exist");
                    }
                    break;
                case 2:
                    System.out.println("Enter Employee ID to hike");
                    int empid = sc.nextInt();
                    if (Employee.searchEmployeeByID(employees, empid) >= 0) {
                        System.out.println("Enter percentage of hike");
                        int percent = sc.nextInt();
                        for (int i = 0; i < employees.length; i++) {
                            if (employees[i].isIDEqual(empid)) {
                                employees[i].incrementSalary(percent);
                            }
                        }
                    } else {
                        System.out.println("Entered employee Does not exist");
                    }
                    break;
                case 3:
                    System.out.println("Enter Employee ID to Display");
                    int tempid = sc.nextInt();
                    tempid =Employee.searchEmployeeByID(employees, tempid);
                    if (tempid>=0) {
                        employees[tempid].displayDetails();
                    } else {
                        System.out.println("Entered employee Does not exist");
                    }
                    break;
                case 4:
                    System.out.println("Exiting Application");
                    break;
                    default:
                    
                    System.out.println("Invalid Input");
                    break;

            }
        } while (task != 4);
    }
}