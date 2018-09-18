package sd.primeira.aula;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author sergio
 */
public class SDPrimeiraAula {

    public static void main(String[] args) {

        BufferedReader reader = new BufferedReader (new InputStreamReader(System.in));

        while (true) {
            
            System.out.println("Escreve uma linha!!");
            
            try {
                
                String result = reader.readLine();
                
                System.out.println("Escreveste: " + result);
                System.out.println("---------------///////--------------");
                
            } catch (IOException e) {
                
                System.out.println("ERRO!!");}
        }
    }
    
        
}
    
