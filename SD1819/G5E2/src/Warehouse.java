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
public class Warehouse {

    private HashMap<String, Item> items;
    private ReentrantLock lock;

    public Warehouse() {

        this.items = new HashMap<String, Item>();
        this.lock= new ReentrantLock();
        
    }
    
    
    public void supply(String item, int quantity){

        // syncronize para o HashMap
        synchronized(this){
        
            if (!(items.containsKey(item))) {

                Item prod = new Item();
                prod.supply(quantity);

                items.put(item, prod);

            }
            
            else items.get(item).supply(quantity);
        }
        
    }
    
    public void consume(String[] items1) {
        
        for(int i = 0; i < items1.length; i++){
            
            if(this.items.containsKey(items1[i])) {
                
                this.items.get(items1[i]).consume();
            }
        }
        
    }

}
