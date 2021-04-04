import java.util.*;
public class Q10 {


	public static int solution(int n, int goal,int times[], boolean rel[][], int frontnum[]) {
		LinkedList<Integer> queue= new LinkedList<Integer>();
		int answers[]=new int[101];
		for(int i=1;i<=n;i++) {
			if(frontnum[i]==0) {
				queue.add(i);
				answers[i]=times[i];
			}
		}
		
		while(!queue.isEmpty()) {
			int f=queue.poll();
			for(int i=1;i<=n;i++) {
				if(rel[f][i]) {
					frontnum[i]-=1;
					answers[i]=Math.max(answers[i], times[i]+answers[f]);
					if(frontnum[i]==0) {
						queue.add(i);
					}
				}
			}
		}
		return answers[goal];
		
	}
	public static void main(String[] args) {
		int times[]=new int[101];
		int frontnum[]=new int[101];

		boolean rel[][]=new boolean[101][101];
		Scanner sc= new Scanner(System.in);
		int n, r;
		n=sc.nextInt();
		r=sc.nextInt();
		for(int i=1;i<=n;i++) {
			times[i]=sc.nextInt();
		}
		for(int i=0;i<r;i++) {
			int from=sc.nextInt();
			int to= sc.nextInt();
			rel[from][to]=true;
			frontnum[to]+=1;
		}
		int goal=sc.nextInt();
		System.out.println(solution(n,goal,times,rel,frontnum));
	}
		

}
