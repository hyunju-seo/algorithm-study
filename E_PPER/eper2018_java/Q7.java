import java.util.*;
public class Q7 {
	public static int[] solution(int[] inp) {
		int sum=0;
		for(int i:inp) {
			sum+=i;
		}
		boolean isans[]=new boolean[9];
		for(int i=0;i<9;i++) {
			isans[i]=true;
		}
		int answer[]=new int[7];
		for(int i=0;i<inp.length;i++) {
			for(int j=i+1;j<inp.length;j++) {
				if(sum-inp[i]-inp[j]==100) {
					isans[i]=false;
					isans[j]=false;
				}
			}
		}
		int id=0;
		for(int i=0;i<9;i++) {
			if(isans[i]) {
				answer[id]=inp[i];
				id+=1;
			}
		}
		return answer;
	}

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int inp[]=new int[9];
		for(int i=0;i<9;i++) {
			inp[i]=sc.nextInt();
		}
		int ans[]=solution(inp);
		for(int a: ans) {
			System.out.print(a);
			System.out.print(' ');
		}
	}

}
