package fr.insalyon.telecom.mgl;
import java.lang.*;
import java.util.*;

public class RomanNumberConverter{
    
    private final static TreeMap<Integer, String> map = new TreeMap<Integer, String>();
    static {

        map.put(1000, "M");
        map.put(900, "CM");
        map.put(500, "D");
        map.put(400, "CD");
        map.put(100, "C");
        map.put(90, "XC");
        map.put(50, "L");
        map.put(40, "XL");
        map.put(10, "X");
        map.put(9, "IX");
        map.put(5, "V");
        map.put(4, "IV");
        map.put(1, "I");
    }

    int convert(String romanNumber){
        if (romanNumber.equals("")) return 0;
        if (romanNumber.startsWith("M")) return 1000 + convert(romanNumber.remove(0, 1));
        if (romanNumber.startsWith("CM")) return 900 + convert(romanNumber.remove(0, 2));
        if (romanNumber.startsWith("D")) return 500 + convert(romanNumber.remove(0, 1));
        if (romanNumber.startsWith("CD")) return 400 + convert(romanNumber.remove(0, 2));
        if (romanNumber.startsWith("C")) return 100 + convert(romanNumber.remove(0, 1));
        if (romanNumber.startsWith("XC")) return 90 + convert(romanNumber.remove(0, 2));
        if (romanNumber.startsWith("L")) return 50 + convert(romanNumber.remove(0, 1));
        if (romanNumber.startsWith("XL")) return 40 + convert(romanNumber.remove(0, 2));
        if (romanNumber.startsWith("X")) return 10 + convert(romanNumber.remove(0, 1));
        if (romanNumber.startsWith("IX")) return 9 + convert(romanNumber.remove(0, 2));
        if (romanNumber.startsWith("V")) return 5 + convert(romanNumber.remove(0, 1));
        if (romanNumber.startsWith("IV")) return 4 + convert(romanNumber.remove(0, 2));
        if (romanNumber.startsWith("I")) return 1 + convert(romanNumber.remove(0, 1));
        throw new ArgumentOutOfRangeException("something bad happened");
    }
    String convert(int number){
        int l =  map.floorKey(number);
        if ( number == l ) {
            return map.get(number);
        }
        return map.get(l) + convert(number-l);
    }
} 