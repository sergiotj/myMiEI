package aula1criarnthreads;

/**
 *
 * @author sergi
 */
public class Aula1CriarNThreads {
    

    public static void main(String[] args) {
        
        System.out.println("Starting Main Thread...");
        
        int nAccounts = 10; 
        
        Bank c = new Bank(nAccounts);

        Thread t1 = new Thread(new Runnable() {
                
            @Override
            public void run() {

                // método para o cliente 1 depositar 20 paus
                System.out.println("Thread started.");
                c.depositMoney(1, 20);
            }
        });
        
        Thread t2 = new Thread(new Runnable() {
                
            @Override
            public void run() {

                // método para o cliente 1 levantar 20 paus
                System.out.println("Thread started.");
                c.drawMoney(1, 20);
            }
        });
        
        t1.start();
        t2.start();
        
        try {
            
            t1.join();
            t2.join();
            
        } catch (InterruptedException iex){
            
            System.out.println("Exception in main thread");
            
        }
        
        c.listOfValues();
        
        System.out.println("End of Main Thread...");
    }        
}
    
