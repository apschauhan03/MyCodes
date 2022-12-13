package com.lecture_2;

import java.util.Scanner;

public class CountingOccurances {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the integer");
        int num = input.nextInt();
        System.out.print("Enter the number which you want the occurrences of : ");
        int x = input.nextInt();
        int ans = 0;
        while(num!=0) {
            if(num%10==x)
                ans++;

            num = num/10;
        }
        System.out.println(ans);
    }
}
