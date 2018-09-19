package aula1criarnthreads;

/**
 *
 * @author sergi
 */
public class Aula1CriarNThreads implements Runnable {
    
    private int incrementN;
    private Counter c;
    
    public Aula1CriarNThreads(int incrementN, Counter c){
        
         this.incrementN = incrementN;
         this.c = c;
    }
    
    @Override
    public void run() {
        
        System.out.println("Thread started.");
        
        int j = 0;
        while (j < incrementN) {
            
            j++;
            c.increment();
        }
        
    }

    public static void main(String[] args) {
        
        int startValue = 0;
        
        // número de vezes incrementado por cada thread
        int I = 1000;
        
        // número de threads
        int N = 10;
        
        System.out.println("Starting Main Thread...");
        
        Counter c = new Counter(startValue);
        
        Thread[] threads = new Thread[N];
        
        for (int i = 0; i < N; i++) {
            threads[i] = new Thread(new Aula1CriarNThreads(I, c));
            
        }
        
        for (int i = 0; i < N; i++) {
            threads[i].start();
        }
        
        try {
            
            for (int i = 0; i < N; i++) {
                threads[i].join();
            }
            
        } catch (InterruptedException iex){
            
            System.out.println("Exception in main thread");
            
        }
        
        System.out.println("O valor final é " + c.getValue() + ".");
        
        System.out.println("End of Main Thread...");
    }        
}
    
