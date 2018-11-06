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
public class Item {

    private ReentrantLock lock;
    private Condition isEmpty;
    private Condition isFull;
    private int quantity;

    public Item() {

        this.quantity = 0;
        this.lock= new ReentrantLock();
        this.isEmpty = this.lock.newCondition();
        this.isFull = this.lock.newCondition();
    }
    
    public void supply(int q) {
        
        this.lock.lock();
        
        this.quantity += q;
        
        // acordar threads que estejam à espera de items. SignalAll em vez de signal pq se a quantidade é maior que 1, queremos
        // notificar várias threads para consumirem
        
        System.out.println("Foi acrescentada quantidade. Consumidores notificados!");
        
        this.isEmpty.signalAll();
        
        this.lock.unlock();
        
    }
    
    public void consume() {
        
        this.lock.lock();
        
        try {
            
            while (this.quantity == 0) {
                System.out.println("Estou no Consume do Item: Não há cenas pra consumir");
                this.isEmpty.await();
            }
        
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
        // consumir uma unidade
        this.quantity--;
        
        System.out.println("Consumido 1 item.");
        
        this.lock.unlock();
        
    }

}
