package com.test;

import java.util.Scanner;



public class StaticTest {

    private static void swap(Employee e1, Employee e2){
        Employee temp = e1;
        e1 = e2;
        e2 = temp;
    }
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        Employee[] staff = new Employee[3];

        for(int i=0;i<3;i++){
            System.out.println("name: ");
            String name = cin.next();
            System.out.println("Salary:");
            int salary = cin.nextInt();
            staff[i] = new Employee(name, salary);
            staff[i].setId();
        }

        swap(staff[0], staff[1]);

        for(Employee employee: staff){
            System.out.println("Id: " + employee.getId());
            System.out.println("name: " + employee.getName());
            System.out.println("Salary:" + employee.getSalary());
        }
        System.out.println("End");
    }
}
