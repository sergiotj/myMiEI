package aula1criarnthreads;

/**
 *
 * @author sergi
 */
public class Aula1CriarNThreads {

    public static void main(String[] args) {

        System.out.println("Starting Main Thread...");

        BoundedBuffer buf = new BoundedBuffer(10);
        
        Thread t1 = new Thread(new Runnable() {

            // PRODUTOR
            
            @Override
            public void run() {

                System.out.println("Thread started.");
                
                for(int i = 0; i < 20; i++) {
                    System.out.println("Metendo o valor " + i);
                    buf.put(i);
                }
                
            }       
        });   
        

        Thread t2 = new Thread(new Runnable() {

            @Override
            public void run() {

                System.out.println("Thread started.");
             
                for(int i = 0; i < 20; i++) {
                    
                    buf.get();
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
