/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author sergi
 */
public class Counter {

    private int startValue;
    
    public Counter(int inicial) {
        
        this.startValue = inicial;
    }
    
    public void increment() {
        
        startValue++;
    }
    
    public int getValue() {
        
        return this.startValue;
    }

    
}


