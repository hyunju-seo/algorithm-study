import java.util.*;
public class Q1 {
	public static int solution(int start, int end, int arr[]) {
		int sum=0;
		for(int i=start;i<=end;i++) {
			sum+=arr[i];
		}
		return sum;
	}

	public static void main(String[] args) {
		Scanner s= new Scanner(System.in);
		int n=s.nextInt();
		int arr[]=new int[n+3];
		for(int i=1;i<=n;i++) {
			arr[i]=s.nextInt();
		}
		int start=s.nextInt();
		int end=s.nextInt();
		System.out.println(solution(start, end, arr));

	}

}
