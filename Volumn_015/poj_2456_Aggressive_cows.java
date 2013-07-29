import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 * 
 */

/**
 * @author antonio081014
 * @since Feb 25, 2012, 3:00:13 PM
 */
public class Main {

    public long[] stalls;

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.solve();
        // System.exit(0);
    }

    public boolean possible(long dist, int n, int c) {
        int cnt = 1;
        for (int b = 0, i = 1; i < n && cnt < c; ++i)
            if (stalls[i] - stalls[b] >= dist) {
                ++cnt;
                b = i;
            }
        return cnt == c;
    }

    public void solve() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // int T = Integer.parseInt(br.readLine());
        // while (T-- > 0) {
        String[] strs = br.readLine().split("\\s");
        int N = Integer.parseInt(strs[0]);
        int C = Integer.parseInt(strs[1]);
        stalls = new long[N];
        for (int i = 0; i < N; i++) {
            stalls[i] = Long.parseLong(br.readLine());
        }
        Arrays.sort(stalls);
        long left = 0L;
        long right = 1L + stalls[N - 1] - stalls[0];
        long mid = 0L;
        long ans = 0L;
        while (left <= right) {
            mid = (left + right) >> 1L;
            if (possible(mid, N, C)) {
                ans = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        // System.out.println(left);
        // System.out.println(mid);
        // System.out.println(right);
        System.out.println(ans);
        // }
    }
}

