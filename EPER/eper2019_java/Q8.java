import java.util.*;
class Position{
	int x;
	int y;
	Position(int x, int y){
		this.x=x;
		this.y=y;
	}
}

public class Q8 {
	public static int solution(int m , int n , int tomato[][]) {
		int visited[][]=new int[n][m];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				visited[i][j]=-1;
			}
		}
		LinkedList<Position> queue= new LinkedList<Position>();
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(tomato[i][j]==1) {
					queue.add(new Position(i,j));
					visited[i][j]=0;
				}
			}
		}
		int dx[]= {0,1,-1,0};
		int dy[]= {1,0,0,-1};
		while(!queue.isEmpty()) {
			Position p = queue.poll();
			int x=p.x;
			int y=p.y;
			for(int i=0;i<4;i++) {
				int nextx= x+dx[i];
				int nexty= y+dy[i];
				if(nextx<0 || nextx>=n||nexty<0||nexty>=m) continue;
				if(tomato[nextx][nexty]==0 && visited[nextx][nexty]==-1) {
					queue.add(new Position(nextx, nexty));
					visited[nextx][nexty]=visited[x][y]+1;
				}
			}
			
		}
		int ans=0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(tomato[i][j]==0) {
					if(visited[i][j]==-1) return -1;
					else {
						ans=Math.max(ans, visited[i][j]);
					}
				}
			}
		}
		return ans;
		
		
	}
	public static void main(String args[]) {
		int m,n;
		Scanner sc= new Scanner(System.in);
		m=sc.nextInt();
		n=sc.nextInt();
		int tomato[][]=new int[n][m];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				tomato[i][j]=sc.nextInt();
			}
		}
		System.out.println(solution(m,n,tomato));
	}

}
