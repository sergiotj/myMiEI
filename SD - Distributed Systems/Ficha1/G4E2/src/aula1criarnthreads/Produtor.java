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
public class Produtor extends Thread implements Runnable {
 
    private BoundedBuffer buf;
    
    public Produtor(BoundedBuffer b) {
        
        this.buf = b;
        
    }
    
    @Override
    public void run() {

        System.out.println("Produtor started.");

        for(int i = 0; i < 20; i++) {
            System.out.println("Metendo o valor " + i);
            buf.put(i);
            Thread.sleep(500);
        }

    }     
    
}
