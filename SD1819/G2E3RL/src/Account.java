/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.concurrent.locks.ReentrantLock;

/**
 *
 * @author sergi
 */
public class Account {

    private float balance;
    
    private ReentrantLock lock = new ReentrantLock();

    public Account(int initialBalance) {

        this.balance = initialBalance;
    }

    public float getBalance() {
        
        float actualBalance;
        
        lock.lock();
        actualBalance = this.balance;
        lock.unlock();
        
        return actualBalance;
    }
    
    public void setBalance(float newBalance) {
        
        this.balance = newBalance;
    }
    
    public void depositMoney(float money) {

        lock.lock();
        this.balance += money;
        lock.unlock();
    }

    public void drawMoney(float money) {

        lock.lock();
        this.balance -= money;
        lock.unlock();
    }

}
