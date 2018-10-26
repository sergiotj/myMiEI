package aula1criarnthreads;

/**
 *
 * @author sergi
 */
public class Aula1CriarNThreads {

    public static void main(String[] args) {

        System.out.println("Starting Main Thread...");

        Bank bank = new Bank();
        
        // cria conta 0 com 10
        bank.createAccount(10);
        
        // cria conta 1 com 10
        bank.createAccount(10);
        

        Thread t1 = new Thread(new Runnable() {

            @Override
            public void run() {

                System.out.println("Thread started.");
                
                try {
                    
                    bank.createAccount(0);
                    bank.transfer(5, 0, 2);
                    
                    int[] myArray = {0,1,2};
                    bank.getAllBalance(myArray);
                    
                } catch (InvalidAccount ex) {

                } catch (InsufficientBalance ey) {

                }
            }
            
        });

        Thread t2 = new Thread(new Runnable() {

            @Override
            public void run() {

                System.out.println("Thread started.");
                
                try {
                    
                    bank.transfer(10, 0, 1);
                    bank.closeAccount(1);
                    bank.getBalance(0);
                    
                } catch (InvalidAccount ex) {

                } catch (InsufficientBalance ey) {

                }
            }
        });

        t1.start();
        t2.start();

        try {

            t1.join();
            t2.join();

        } catch (InterruptedException iex) {

            System.out.println("Exception in main thread");

        }

        System.out.println("End of Main Thread...");
    }
}
