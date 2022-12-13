package com.currencyconverter;

import java.util.Scanner;

public class Todollar {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the currency in ruppes : ");
        float dollar = input.nextInt() / 81.23f;
        System.out.println(dollar + "$");


    }
}
