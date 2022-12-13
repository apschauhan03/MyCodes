package com.add;

import java.util.Scanner;

public class Arithematic {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int b = input.nextInt();
        char operator = input.next().trim().charAt(0);
        int ans = 0;
        if(operator=='+')
            ans = a+b;
        else if(operator=='-')
            ans = a-b;
        else if(operator=='*')
            ans = a*b;
        else if(operator=='/'&&b!=0)
            ans = a/b;
        else
            System.out.println("The numbers are invalid");

        System.out.println(ans);
    }

}
