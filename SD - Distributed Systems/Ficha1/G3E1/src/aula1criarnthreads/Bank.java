/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula1criarnthreads;

import java.util.Arrays;
import java.util.HashMap;
import java.util.concurrent.locks.ReentrantLock;


/**
 *
 * @author sergi
 */
public class Bank {

    private HashMap<Integer, Account> accounts;
    
    private ReentrantLock lockBank;
    
    private int nAccounts;

    public Bank() {

        this.accounts = new HashMap<Integer, Account>();
        this.nAccounts = 0;
        this.lockBank = new ReentrantLock();
        
    }
    
    public int createAccount(double initialBalance) {
        
        this.lockBank.lock();
        
        Account newAccount = new Account(initialBalance);
        
        int newID = nAccounts + 1;
        
        accounts.put(newID, newAccount);
        
        this.lockBank.unlock();
        
        return newID;
    }
    
    public double closeAccount(int id) throws InvalidAccount {
        
        this.lockBank.lock();
        
        if (this.accounts.containsKey(id) == false) throw new InvalidAccount();
        
        Account c = this.accounts.get(id);
        
        c.lockAccount.lock();
        
        double money = this.accounts.get(id).getBalance();
        
        this.accounts.remove(id);
        
        c.lockAccount.unlock();
        
        this.lockBank.unlock();
        
        return money;
    }
    
    public double getAllBalance(int accountsArg[]) {
        
        double sum = 0;
        
        this.lockBank.lock();
        
        for (int i = 0; i < accountsArg.length; i++) {
            
            int accountToCheck = accountsArg[i];
            
            sum += this.accounts.get(accountToCheck).getBalance();
        }
        
        this.lockBank.unlock();
        
        return sum;
    }
    
    public double getBalance(int id) throws InvalidAccount {
        
        if (this.accounts.containsKey(id) == false) throw new InvalidAccount();
        
        return this.accounts.get(id).getBalance();
        
    }
    
    public void drawMoney(int id, double value) throws InvalidAccount, InsufficientBalance {
        
        if (this.accounts.containsKey(id) == false) throw new InvalidAccount();
        
        double actualBalance = this.accounts.get(id).getBalance();
        
        if (actualBalance - value <= 0) throw new InsufficientBalance();
        
        this.accounts.get(id).drawMoney(value);
        
    }
    
    public void depositMoney(int id, double value) throws InvalidAccount {
        
        if (this.accounts.containsKey(id) == false) throw new InvalidAccount();
        
        this.accounts.get(id).depositMoney(value);
        
    }
    
    // lock para bloquear conta
    // lock pra bloquear banco

    public void transfer(float value, int source, int destiny) throws InvalidAccount, InsufficientBalance {
        
        double sourceActualBalance = this.accounts.get(source).getBalance();
        if (sourceActualBalance - value <= 0) throw new InsufficientBalance();
        
        if (this.accounts.containsKey(source) == false) throw new InvalidAccount();
        if (this.accounts.containsKey(destiny) == false) throw new InvalidAccount();
        
        int min = Math.min(source, destiny);
        int max = Math.max(source, destiny);
        
        synchronized(this.accounts.get(min)){
            
            synchronized(this.accounts.get(max)){
                
                this.drawMoney(source, value);
                this.depositMoney(destiny, value);
                
            }

        }
    }

}
