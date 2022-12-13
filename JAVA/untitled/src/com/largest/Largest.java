package com.largest;

import java.util.Scanner;

public class Largest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int b = input.nextInt();
        if(a>b){
            System.out.println(a + " is the larger integer");
        }
        else {
            System.out.println(b + " is the larger integer");
        }
    }
}
