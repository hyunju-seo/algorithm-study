////나
//import java.util.*;
//public class Q2018_10 {
//	static ArrayList<Integer> con[]= new ArrayList[102];
//	static int times[] = new int[102];
//
//	public static int func(int node) {
//		//System.out.println(node);
//		if(con[node].isEmpty()) {
//		//	System.out.println("node"+node+" "+times[node]);
//			return times[node];
//		}
//		int ans=-1;
//		for(int n_node : con[node]) {
//			ans=Math.max(ans, func(n_node));
//		}
//		int temp =ans+times[node];
//		//System.out.println("node"+node+" "+temp);
//
//		return ans+times[node];
//		
//	}
//	public static int solution(int[] n , int[][] r, int goal) {
//		for(int i=0;i<con.length;i++) {
//			con[i] =new ArrayList<Integer>();
//		}
//		for(int i=0;i<n.length;i++) {
//			times[i+1]=n[i];
//		}
//		for(int ints=0;ints<r.length;ints++) {
//			con[r[ints][1]].add(r[ints][0]);
//		}
//		return func(goal);
//
//	}
//	public static void main(String[] args) {
//		int n[] = {10, 20, 100 ,20};
//		int r[][]= {{1,2},{1,3},{2,4},{3,4}};
//		int goal = 4;
//		System.out.print(solution(n,r,goal));
//	}
//
//}
//pdf
import java.util.*;
public class Q2018_10 {
	

	public static int solution(int[] n , int[][] r, int goal) {
		int times[] =new int[n.length];
		System.arraycopy(n, 0, times, 0, n.length);
		int connection[][]=new int[n.length][n.length];
		int indegree[] = new int[n.length]; // 선행 공정의 개수
		for(int[] a : r) {
			int x= a[0]-1;
			int y= a[1]-1;
			connection[x][y]=1;
			indegree[y]+=1;
		}
		int answers[] = new int[n.length]; // 현재 공정까지 걸린 최소 시간
		LinkedList<Integer> que = new LinkedList<Integer>();
		for(int i=0;i<indegree.length;i++) {
			if(indegree[i]==0) {
				que.add(i);
				answers[i]=times[i];
			}
		}
		/*linkedlist poll : 첫번째 요소를 반환 & 삭제 , peek : 첫번쨰 요소를 반환*/
		while(!que.isEmpty()) {
			int q= que.poll();
			for(int i=0;i<n.length;i++) {
				if(connection[q][i]==1) {
					answers[i]= Math.max(answers[i], answers[q]+times[i]);
					indegree[i]-=1;
					if(indegree[i]==0) que.add(i);
				}
			}
		}
		return answers[goal-1];
 
	}
	public static void main(String[] args) {
		int n[] = {10, 20, 100 ,20};
		int r[][]= {{1,2},{1,3},{2,4},{3,4}};
		int goal = 4;
		System.out.print(solution(n,r,goal));
	}

}



