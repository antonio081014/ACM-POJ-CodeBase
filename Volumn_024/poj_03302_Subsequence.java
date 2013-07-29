import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * POJ: http://poj.org/problem?id=3302
 * 
 * Solution: Longest Common Subsequence.
 */

/**
 * @author antonio081014
 * @time: Apr 3, 2012, 9:15:16 AM
 */
public class Main {

    public static void main(String[] args) throws Exception {
	Main main = new Main();
	main.run();
	System.exit(0);
    }

    public void run() throws Exception {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int T = Integer.parseInt(br.readLine());
	while (T-- > 0) {
	    String[] str = br.readLine().split("\\s");
	    String c = new StringBuilder(str[1]).reverse().toString();
	    if (isSubsequence(str[0], str[1]) || isSubsequence(str[0], c))
		System.out.println("YES");
	    else
		System.out.println("NO");
	}
    }

    public boolean isSubsequence(String a, String b) {
	int N = a.length();
	int M = b.length();
	int[][] cost = new int[N + 1][M + 1];
	for (int i = 1; i <= N; i++)
	    for (int j = 1; j <= M; j++) {
		if (a.charAt(i - 1) == b.charAt(j - 1))
		    cost[i][j] = cost[i - 1][j - 1] + 1;
		else {
		    cost[i][j] = Math.max(cost[i - 1][j], cost[i][j - 1]);
		}
	    }
	return M == cost[N][M];
    }

}

