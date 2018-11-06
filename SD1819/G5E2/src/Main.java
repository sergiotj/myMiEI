/**
 *
 * @author sergi
 */
public class Main {

    public static void main(String[] args) {

        System.out.println("Starting Main Thread...");

        Warehouse wh = new Warehouse();
        wh.supply("Morangos", 0);
        wh.supply("Bananas", 0);
        wh.supply("Cerejas", 0);
        
        Thread t1 = new Thread(new Produtor(wh));
        Thread t2 = new Thread(new Consumer(wh));

        t1.start();
        t2.start();

        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("End of Main Thread...");
    }
}
