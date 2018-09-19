/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula1criarnthreads;

/**
 *
 * @author sergi
 */
public class Counter {

    private int startValue;
    
    public Counter(int inicial) {
        
        this.startValue = inicial;
    }
    
    // Método Synchronized
    public synchronized void increment() {
        
        startValue++;
    }
    
    /*
    // BLOCO SYNCHRONIZED
    public void increment() {
        
        synchronized(this){
            startValue++;
        }
    }	
    */
    
    public int getValue() {
        
        return this.startValue;
    }

    
}


