/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author sergi
 */
public class Consumer extends Thread implements Runnable {
 
    private Warehouse buf;
    
    public Consumer(Warehouse b) {
        
        this.buf = b;
        
    }
    
    
    @Override
    public void run() {
        
        String[] items = {"Morangos","Bananas","Cerejas"};
        buf.consume(items);
    } 
    
}
