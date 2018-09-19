/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula1criarnthreads;

import java.util.Arrays;

/**
 *
 * @author sergi
 */
public class Bank {

    private float[] values;
    
    public Bank(int nAccounts) {
        
        this.values = new float[nAccounts];
        
        for (int i = 0; i < nAccounts-1; i++) {
            values[i] = 0;
        }
    }
    
    public synchronized void depositMoney(int i, float money) {
        
        values[i] = values[i] + money;
        
    }
    
    public synchronized void drawMoney(int i, float money) {
        
        if (values[i] >= money) {
        
            values[i] = values[i] - money;
        }
        
    }
    
    public synchronized void listOfValues() {
        
        System.out.println(Arrays.toString(values));
        
    }
    
    public synchronized float getBalance(int id) {
        
        return values[id];
        
    }
    
    public synchronized void transfer(float value, int source, int destiny) {
        
        this.depositMoney(destiny, value);
        
        this.drawMoney(source, value);
        
    }
    
}


