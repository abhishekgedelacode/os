import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Ceaser {
    static Scanner sc = new Scanner(System.in);
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static String encrypt(String str, int key) {
        String es = "";
        for (int i = 0; i < str.length(); i++) {
            int c = str.charAt(i);
            if (Character.isUpperCase(c)) {
                c = c + (key % 26);
                if (c > 'Z')
                    c -= 26;
            } else if (Character.isLowerCase(c)) {
                c = c + (key % 26);
                if (c > 'z')
                    c -= 26;
            }
            es += (char) c;
        }
        return es;
    }

    public static String decrypt(String str, int key) {
        String ds = "";
        for (int i = 0; i < str.length(); i++) {
            int c = str.charAt(i);
            if (Character.isUpperCase(c)) {
                c = c - (key % 26);
                if (c < 'A')
                    c += 26;
            } else if (Character.isLowerCase(c)) {
                c = c - (key % 26);
                if (c < 'a')
                    c += 26;
            }
            ds += (char) c;
        }
        return ds;
    }

    public static void main(String[] args) throws IOException {
        System.out.print("Enter String: ");
        String str = br.readLine();
        System.out.print("Enter Key: ");
        int key = sc.nextInt();
        String enc = encrypt(str, key);
        System.out.println("\n Encrypted String: " + enc);
        String dec = decrypt(enc, key);
        System.out.println("\n Decrypted String: " + dec);
    }
}
