/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula1criarnthreads;

import java.util.Arrays;


/**
 *
 * @author sergi
 */
public class Bank {

    private Account[] accounts;
    
    private int nAccounts;

    public Bank(int nAccounts) {

        this.accounts = new Account[nAccounts];

        for (int i = 0; i < nAccounts-1; i++) {
            accounts[i] = new Account(0); 
        }
        
        this.nAccounts = nAccounts;
    }

    public void depositMoney(int i, float money) {

        accounts[i].setBalance(accounts[i].getBalance() + money);

    }

    public void drawMoney(int i, float money) {

        if (accounts[i].getBalance() >= money) {

            accounts[i].setBalance(accounts[i].getBalance() - money);
        }

    }

    public void transfer(float value, int source, int destiny) {
        
        int min = Math.min(source, destiny);
        int max = Math.max(source, destiny);
        
        synchronized(this.accounts[min]){
            
            synchronized(this.accounts[max]){
                
                this.drawMoney(source, value);
                this.depositMoney(destiny, value);
            }

        }
    }
    
    public synchronized void listOfValues() {

        for (int i = 0; i < nAccounts-1; i++) {
            System.out.println(accounts[i].getBalance());
        }

    }

}
