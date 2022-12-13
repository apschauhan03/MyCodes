package com.principleInterest;

import java.util.Scanner;

public class PrincipleInterest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the value of principle : ");
        int principle = input.nextInt();
        System.out.print("Enter the value of Rate : ");
        float rate = input.nextFloat();
        System.out.print("Enter the value of time in years : ");
        int time = input.nextInt();

        float sI = (principle*rate*time)/100;
        System.out.println(sI);
    }
}
