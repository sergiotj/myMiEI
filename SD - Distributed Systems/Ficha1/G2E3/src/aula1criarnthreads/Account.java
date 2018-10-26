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
public class Account {

    private float balance;

    public Account(int initialBalance) {

        this.balance = initialBalance;
    }

    public float getBalance() {

        return this.balance;

    }
    
    public void setBalance(float newBalance) {
        
        this.balance = newBalance;
    }

}
