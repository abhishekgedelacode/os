import java.io.*;
import java.util.*;

public class Substitution {
    static Scanner sc = new Scanner(System.in);
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        String a = "abcdefghijklmnopqrstuvwxyz";
        String b = "zyxwvutsrqponmlkjihgfedcba";
        System.out.print("Enter String: ");
        String str = br.readLine();
        String ds = "";
        char c;

        for (int i = 0; i < str.length(); i++) {
            c = str.charAt(i);
            int j = a.indexOf(c);
            ds = ds + b.charAt(j);
        }

        System.out.println("Encrypted String: " + ds);
    }
}