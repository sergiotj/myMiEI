/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author sergi
 */
public class Produtor extends Thread implements Runnable {
 
    private Warehouse buf;
    
    public Produtor(Warehouse b) {
        
        this.buf = b;
        
    }
    
    @Override
    public void run() {

        System.out.println("Produtor started.");

        System.out.println("Producer: adicionei uma unidade de Morangos");
        this.buf.supply("Morangos", 1);

        try {
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Producer: adicionei uma unidade de Bananas");
        this.buf.supply("Bananas", 1);

        try {
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Producer: adicionei uma unidade de Cerejas");
        this.buf.supply("Cerejas", 1);	

    }     
    
}
