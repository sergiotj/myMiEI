package aula1criarnthreads;

/**
 *
 * @author sergi
 */
public class Aula1CriarNThreads {

    public static void main(String[] args) {

        System.out.println("Starting Main Thread...");

        BoundedBuffer buf = new BoundedBuffer(10);
        
        Produtor[] p = new Produtor[20];
        
        Consumer[] c = new Consumer[20];
        
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
