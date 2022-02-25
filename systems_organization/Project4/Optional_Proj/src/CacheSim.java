import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class CacheSim {
    public static void main(String[] args) throws FileNotFoundException {
        int lineCount = 0;
        boolean er = false;
        File inFile = new File("input.txt");
        if(inFile == null) {
            System.out.print("File error");
            return;
        }
        Scanner scanner = new Scanner(inFile);
        while(scanner.hasNextLine()) {
            scanner.nextLine();
            lineCount++;
        }

        scanner = new Scanner(inFile);
        String[] data = new String[lineCount];
        int i = 0;
        while (scanner.hasNextLine()) {
            data[i] = scanner.nextLine();
            i++;
        }

        int sets = extractInt(data[0]);
        int setsSize = extractInt(data[1]);
        int lineSize = extractInt(data[2]);

        if(sets % 2 == 1) {
            System.out.println("Sets must be a power of two");
            er = true;
        }
        if(setsSize % 2 == 1) {
            System.out.println("Set size must be a power of two");
            er = true;
        }
        if(lineSize % 2 == 1) {
            System.out.println("Line size must be a power of two");
            er = true;
        }
        if(sets > 8192) {
            System.out.println("Number of sets 2^13 at most");
            er = true;
        }
        if(er) {
            System.exit(0);
        }

        int indexMask = 0, offMask = 0, initialAddress = 0, tag = 0, index = 0, offset = 0;
        int offsetBits = base2(lineSize);
        int indexBits = base2(sets);

        for(i = 0; i < offsetBits; i++){
            offMask = offsetBits ^ i;
        }for(int k = 0; k < indexBits; k++){
            indexMask += indexBits ^ k;
        }

        System.out.println(indexBits);
        System.out.println("Access" +"\t\tAddress" +"  \tTag" + "  \tIndex" + "\tOffset" + "\tStatus" + "\tMemRefs");
        System.out.println("-------------------------------------------------------------------");

        for(i = 3; i < data.length; i++) {
            String acc = access(data[i]);
            String address = data[i].substring(data[i].lastIndexOf(":")+1);

            initialAddress = extractAddr(data[i]);
            tag = initialAddress >> (indexBits + offsetBits);
            index = ((initialAddress >> offsetBits) & indexMask);
            offset = initialAddress & offMask;

            String hitmiss = "miss";
            int memref = 1;
            if(i == data.length-1){
                hitmiss = "hit ";
                memref = 0;
            }
            System.out.println(acc + "\t\t" + address +"\t\t"+ tag + "\t\t" + index + "\t\t" + offset + "\t\t" + hitmiss + "\t\t" + memref);
        }
        scanner.close();
    }

    static int extractInt(String str){
        str = str.replaceAll("[^\\d]","");
        str = str.trim();
        return Integer.parseInt(str);
    }
    static int extractAddr(String str){
        str = str.substring(str.lastIndexOf(":") + 1 );
        return  Integer.decode(str);
    }

    static String access(String s){
        char c = s.charAt(0);
        String retStr = "";
        if (c == 'W'){
            retStr = "write";
        }
        else if (c == 'R'){
            retStr = "read";
        }
        return retStr;
    }

    static int base2(int n){
        return (int)(Math.log(n)/Math.log(2));
    }
}