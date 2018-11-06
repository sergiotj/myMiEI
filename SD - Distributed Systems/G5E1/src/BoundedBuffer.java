/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.Arrays;
import java.util.HashMap;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;


/**
 *
 * @author sergi
 */
public class BoundedBuffer {

    private int[] values;
    private int poswrite;
    private ReentrantLock lock;
    private Condition isEmpty;
    private Condition isFull;

    public BoundedBuffer(int n) {

        this.values = new int[n];
        this.poswrite = 0;
        this.lock= new ReentrantLock();
        this.isEmpty = this.lock.newCondition();
        this.isFull = this.lock.newCondition();
        
    }
    
    
    public void put(int v) {
        
        this.lock.lock();
        
        try {
            
            while (this.poswrite == this.values.length) {
                System.out.println("Estou no PUT: buffer está cheio, esperando até que tenha espaço");
                this.isFull.await();
            }
        
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
        this.values[poswrite] = v;
        this.poswrite++;
        
        // acordar threads que estejam à espera de items no buffer
        this.isEmpty.signal();
        
        this.lock.unlock();
        
    }
    
    public int get() {
        
        this.lock.lock();
        
        try {
            
            while (this.poswrite == 0) {
                System.out.println("Estou no GET: buffer está vazio, esperando até que tenha valores");
                this.isEmpty.await();
            }
        
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
        int value = this.values[poswrite-1];
        this.poswrite--;
        System.out.println("Estou no GET: notificar que um valor foi retirado do buffer");
        
        // acordar threads que estejam à espera que buffer tenha espaço pra fazer put
        this.isFull.signal();
        
        this.lock.unlock();
        
        return value;
        
    }

}
