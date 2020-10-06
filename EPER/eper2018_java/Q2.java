import java.util.*;
public class Q2 {

	public static int[] solution(int n) {
		int answer[]=new int[2];
		answer[0]=(n-1)/15+1;
		answer[1]=(n-1)%15+1;
		return answer;
	}
	public static void main(String[] args) {
		Scanner s= new Scanner(System.in);
		int n=s.nextInt();
		int answer[]=solution(n);
		System.out.println(answer[0]+" "+answer[1]);
		
		
		
		
		
		
		
	}

}
