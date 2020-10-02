
public class Q4 {
	public static int solution(int n, int m) {
		int ans=Math.min(n, m);
		return (ans-1)*2;
	}
	public static void main(String[] args) {
		int n=5;
		int m=4;
		System.out.println(solution(n,m));

	}

}
