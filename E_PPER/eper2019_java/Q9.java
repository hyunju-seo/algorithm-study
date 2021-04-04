
import java.util.*;
public class Q9 {
	public static int solution(int n, int tri[][]) {
		int cache[][]=new int[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				cache[i][j]=-1;
			}	
		}
		cache[0][0]=tri[0][0];
		
		for(int i=1;i<n;i++) {
			for(int j=0;j<=i;j++) {
				cache[i][j]=tri[i][j]+cache[i-1][j];
				if(j-1>=0) {
					cache[i][j]=tri[i][j]+Math.max(cache[i-1][j], cache[i-1][j-1]);

				}
			}	
		}
		int ans=0;
		for(int i=0;i<n;i++) {
			ans=Math.max(ans, cache[n-1][i]);
		}
		return ans;
	}

	public static void main(String[] args) {
		Scanner s =new Scanner(System.in);
		int n = s.nextInt();
		int tri[][]= new int[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<=i;j++) {
				tri[i][j]=s.nextInt();
			}
		}
		System.out.println(solution(n,tri));
	}

}