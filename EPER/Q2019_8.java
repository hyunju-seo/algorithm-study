//import java.util.*;
//
//class Pair {
//    int x;
//    int y;
//    Pair(int x, int y) {
//        this.x = x;
//        this.y = y;
//    }
//}
//
//public class Main {
//    public static final int[] dx = {0, 0, 1, -1};
//    public static final int[] dy = {1, -1, 0, 0};
//    public static void main(String args[]) {
//        Scanner sc = new Scanner(System.in);
//        int m = sc.nextInt();
//        int n = sc.nextInt();
//        int[][] a = new int[n][m];
//        int[][] dist = new int[n][m];
//        Queue<Pair> q = new LinkedList<Pair>();
//        for (int i=0; i<n; i++) {
//            for (int j=0; j<m; j++) {
//                a[i][j] = sc.nextInt();
//                dist[i][j] = -1;
//                if (a[i][j] == 1) {
//                    q.add(new Pair(i, j));
//                    dist[i][j] = 0;
//                }
//            }
//        }
//        while (!q.isEmpty()) {
//            Pair p = q.remove();
//            int x = p.x;
//            int y = p.y;
//            for (int k=0; k<4; k++) {
//                int nx = x+dx[k];
//                int ny = y+dy[k];
//                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
//                    if (a[nx][ny] == 0 && dist[nx][ny] == -1) {
//                        q.add(new Pair(nx, ny));
//                        dist[nx][ny] = dist[x][y] + 1;
//                    }
//                }
//            }
//        }
//        int ans = 0;
//        for (int i=0; i<n; i++) {
//            for (int j=0; j<m; j++) {
//                if (ans < dist[i][j]) {
//                    ans = dist[i][j];
//                }
//            }
//        }
//        for (int i=0; i<n; i++) {
//            for (int j=0; j<m; j++) {
//                if (a[i][j] == 0 && dist[i][j] == -1) {
//                    ans = -1;
//                }
//            }
//        }
//        System.out.println(ans);
//    }
//}




import java.util.*;
class Pair{
	int x;
	int y;
	public Pair(int x, int y) {
		this.x=x;
		this.y=y;
	}
}
public class Q2019_8 {

	public static int solution(int n, int m ,int tomato[][]) {
		LinkedList<Pair> queue= new LinkedList<>();
		int dx[]= {0,1,-1,0};
		int dy[]= {1,0,0,-1};
		
		int days[][]=new int[n][m];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				days[i][j]=-1;
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(tomato[i][j]==1) {
					queue.add(new Pair(i,j));
					days[i][j]=0;
				}
			}
		}

		while(!queue.isEmpty()) {
			Pair p= queue.poll();
			int x= p.x;
			int y=p.y;

			for(int i=0;i<4;i++) {
				int nextx=x+dx[i];
				int nexty=y+dy[i];
				if(nextx<0 || nexty<0 || nextx>=n|| nexty>=m) continue;
				if(tomato[nextx][nexty]==-1) continue;
				if(days[nextx][nexty]==-1) {
					queue.add(new Pair(nextx, nexty));
					days[nextx][nexty]=days[x][y]+1;
				}
			}
		}
		boolean canans=true;
		int ans=-1;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(days[i][j]==-1 && tomato[i][j]==0) canans=false;
				ans=Math.max(ans, days[i][j]);
			}
		}	
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				System.out.print(days[i][j]);
			}System.out.println();
		}
		if(!canans) return -1;
		return ans;
	}
	public static void main(String args[]) {
		int n=5,m=5;
		//int tomato[][]= {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,1}};
		//int tomato[][]= {{0,-1,0,0,0,0},{-1,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,1}};
		int tomato[][]= {{-1,1,0,0,0},{0,-1,-1,-1,0},{0,-1,-1,-1,0},{0,-1,-1,-1,0},{0,0,0,0,0}};
		System.out.println(solution(n,m,tomato));
	}
}
