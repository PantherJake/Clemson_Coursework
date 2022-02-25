package cpsc3300.project4.simulator;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class CacheSim {
    public static void main(String[] args) throws FileNotFoundException {
        File inFile = new File("input.txt");

        // Data collection
        int lineCount = 0;
        Scanner scanner = new Scanner(inFile);
        while (scanner.hasNextLine()) {
            String temp = scanner.nextLine();
            lineCount++;
        }

        scanner = new Scanner(inFile);
        String[] data = new String[lineCount];
        for(int i = 0; i < lineCount; ++i) data[i] = scanner.nextLine();

        int sets = getCacheInfo(data[0]);
        int setsSize = getCacheInfo(data[1]);
        int lineSize = getCacheInfo(data[2]);

        // Error eval
        if(sets % 2 == 1) {
            System.out.println("Sets must be a power of two");
            return;
        }
        else if(setsSize % 2 == 1) {
            System.out.println("Set size must be a power of two");
            return;
        }
        else if(lineSize % 2 == 1) {
            System.out.println("Line size must be a power of two");
            return;
        }
        else if(sets > 8192) {
            System.out.println("Number of sets 2^13 at most");
            return;
        }

        // Sim
        int indexMask = 0, offMask = 0, initialAddress = 0, tag = 0, index = 0, offset = 0;
        int offsetBits = (int)(Math.log(lineSize)/Math.log(2));
        int indexBits = (int)(Math.log(sets)/Math.log(2));

        for(int i = 0; i < offsetBits; i++){
            offMask = offsetBits ^ i;
        }for(int k = 0; k < indexBits; k++){
            indexMask += indexBits ^ k;
        }

        System.out.println("sets: " + sets);

        String access = "";
        int hitCount = 0;
        int missCount = 0;
        int accessCount = 0;

        for(int i = 3; i < data.length; i++) {

            if(data[i].charAt(0) == 'W') access = "write";
            else if(data[i].charAt(0) == 'R') access = "read";

            String address = data[i].substring(data[i].lastIndexOf(":")+1);
            initialAddress = getAddress(data[i]);
            tag = initialAddress >> (indexBits + offsetBits);
            index = ((initialAddress >> offsetBits) & indexMask);
            offset = initialAddress & offMask;

            int memref = 1;
            String status = "miss";
            accessCount++;
            if(i == (data.length-1)) {
                status = "hit";
                memref = 0;
                hitCount++;
            }
            else missCount++;

            System.out.println(access + "\t" + address +"\t"+ tag + "\t" + index + "\t" + offset + "\t" + status + "\t" + memref);
        }

        // Summary Stats Menu
        System.out.println("\nSimulation Summary Statistics");
        System.out.println("-----------------------------");
        System.out.println("Total hits:       " + hitCount);
        System.out.println("Total misses:     " + missCount);
        System.out.println("Total accesses:   " + accessCount);
        System.out.println("Hit ratio:        " + hitCount / missCount);
        System.out.println("Miss ratio:       " + missCount / hitCount);
    }

    static int getCacheInfo(String str) {
        str = str.replaceAll("[^\\d]","");
        str = str.trim();
        return Integer.parseInt(str);
    }

    static int getAddress(String str) {
        str = str.substring(str.lastIndexOf(":") + 1 );
        return Integer.decode(str);
    }
}
