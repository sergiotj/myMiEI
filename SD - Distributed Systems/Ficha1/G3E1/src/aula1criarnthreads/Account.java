/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula1criarnthreads;

import java.util.concurrent.locks.ReentrantLock;

/**
 *
 * @author sergi
 */
public class Account {

    private double balance;
    
    public ReentrantLock lockAccount;

    public Account(double initialBalance) {

        this.balance = initialBalance;
        this.lockAccount = new ReentrantLock();
    }

    public double getBalance() {
        
        double actualBalance;
        
        lockAccount.lock();
        actualBalance = this.balance;
        lockAccount.unlock();
        
        return actualBalance;
    }
    
    public void setBalance(double newBalance) {
        
        this.balance = newBalance;
    }
    
    public void depositMoney(double money) {

        lockAccount.lock();
        this.balance += money;
        lockAccount.unlock();
    }

    public void drawMoney(double money) {

        lockAccount.lock();
        this.balance -= money;
        lockAccount.unlock();
    }

}
