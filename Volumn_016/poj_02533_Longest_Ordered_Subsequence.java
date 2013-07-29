import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * 
 */

/**
 * @author antonio081014
 * @time: Mar 29, 2012, 2:09:27 PM
 */
public class Main {

    private int N;
    private int[] number;
    private int[] cost;

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
	Main main = new Main();
	main.run();
	System.exit(0);
    }

    public void run() throws Exception {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String strLine;
	while ((strLine = br.readLine()) != null && strLine.length() > 0) {
	    N = Integer.parseInt(strLine);
	    if (N == 0) {
		System.out.println(1);
		continue;
	    }
	    number = new int[N];
	    cost = new int[N];
	    String[] str = br.readLine().split("\\s");
	    for (int i = 0; i < N; i++) {
		number[i] = Integer.parseInt(str[i]);
		cost[i] = 1;
	    }
	    int max = 0;
	    for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
		    if (number[i] > number[j] && cost[i] < cost[j] + 1) {
			cost[i] = cost[j] + 1;
		    }
		}
		max = Math.max(max, cost[i]);
	    }
	    // print();
	    System.out.println(max);
	}
    }

    public void print() {
	for (int i = 0; i <= N; i++)
	    System.out.print(" " + cost[i]);
	System.out.println();
    }
}
