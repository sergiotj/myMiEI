/**
 *
 * @author sergi
 */
public class Main implements Runnable {
    
    int n;
    
    public Main(){
         
    }
    
    @Override
    public void run() {
        
        System.out.println("Thread started.");
        
        n = 0;
        
        int i = 0;
        while (i < 100) {
            
            i++;
            n++;
            System.out.println(n);
        }
        
    }

    public static void main(String[] args) {
       
        System.out.println("Starting Main Thread...");
        
        Main n1 = new Main();
        Main n2 = new Main();
        
        Thread th1 = new Thread(n1);
        Thread th2 = new Thread(n2);
        
        th1.start();
        th2.start();
        
        try {
            
            th1.join();
            th2.join();
            
        } catch (InterruptedException iex){
            
            System.out.println("Exception in main thread");
            
        }
        
        System.out.println("End of Main Thread...");
    }        
}
    
