import java.util.*;
public class Q8 {
	public static int chess[][]= {{25,24,23,22,21},{10,11,12,13,20},{9,8,7,14,19},{2,3,6,15,18},{1,4,5,16,17}};



	public static int[] solution(int goal) {
		int ans[]=new int[2];
		for(int i=0;i<5;i++) {
			for(int j=0;j<5;j++) {
				if(chess[i][j]==goal) {
					int ga=j-0;
					int se=i-4;
					if(ga<0) ga=-1*ga;
					if(se<0) se=-1*se;
					ga+=1;
					se+=1;
					ans[0]=ga;
					ans[1]=se;
					

				}
			}
		}
		return ans;
		
	}

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
	
		for(int i=0;i<n;i++) {
			int goal=sc.nextInt();
			int ans[]=solution(goal);
			System.out.print(ans[0]);
			System.out.print(' ');

			System.out.println(ans[1]);


		}
		
	}

}
