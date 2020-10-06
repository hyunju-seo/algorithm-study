import java.util.*;
public class Q9 {
	public static ArrayList<Integer> solution(int n,int m) {
		ArrayList<Integer> answers=new ArrayList<Integer>();
		int totalnum=n*m-(n-2)*(m-2);
		for(int p=1;p<=Math.min(n, m);p++) {
			if(totalnum%p!=0) continue;
			if(m%p==0) {
				if((n-2)%p==0) answers.add(p);
				
			}
			else if((m-1)%p==0) {
				if((n-2)%p==0 && n%p==0) answers.add(p);
				else if((n-1)%p==0)answers.add(p);
			}
			else if((m-2)%p==0) {
				if(n%p==0) answers.add(p);
				else if(m%p==0 && (n-1)%p==0) answers.add(p);
			}
		}
		return answers;
	}

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		ArrayList<Integer> answers=solution(n,m);
		for(int a:answers) {
			System.out.print(a+" ");
			
		}
	}

}
