/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula1criarnthreads;

import java.util.Arrays;
import java.util.HashMap;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.ReentrantLock;


/**
 *
 * @author sergi
 */
public class BoundedBuffer {

    private int[] values;
    private int poswrite;

    public BoundedBuffer(int n) {

        this.values = new int[n];
        this.poswrite = 0;
        
    }
    
    
    public synchronized void put(int v) {
        
        try {
            
            while (this.poswrite == this.values.length) {
                System.out.println("Estou no PUT: buffer está cheio, esperando até que tenha espaço");
                this.wait();
            }
        
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
        this.values[poswrite] = v;
        this.poswrite++;
        this.notifyAll();
        
    }
    
    public synchronized int get() {
        
        try {
            
            while (this.poswrite == 0) {
                System.out.println("Estou no GET: buffer está vazio, esperando até que tenha valores");
                this.wait();
            }
        
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
        int value = this.values[poswrite-1];
        this.poswrite--;
        System.out.println("GET: notificar que um valor foi retirado do buffer");
        this.notifyAll();
        
        return value;
        
    }

}
