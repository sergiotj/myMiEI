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
public class Consumer extends Thread implements Runnable {
 
    private BoundedBuffer buf;
    
    public Consumer(BoundedBuffer b) {
        
        this.buf = b;
        
    }
    
    
    @Override
    public void run() {

        System.out.println("Thread Consumer started.");

        for(int i = 0; i < 20; i++) {
            
            buf.get();
            Thread.sleep(500);
        }

    }     
    
}
