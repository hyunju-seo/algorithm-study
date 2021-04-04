
public class Q4 {
	public static void solution(int n) {
		int space=n/2;
		for(int i=1;i<=n;i+=2) {
			for(int j=0;j<space;j++) {
				System.out.print(' ');

			}				space-=1;

			for(int j=0;j<i;j++) {
				System.out.print('*');
			}System.out.println();
		}
		space+=2;
		for(int i=n-2;i>=1;i-=2) {
			for(int j=0;j<space;j++) {
				System.out.print(' ');

			}				space+=1;

			for(int j=0;j<i;j++) {
				System.out.print('*');
			}System.out.println();
		}
	}

	public static void main(String[] args) {
		int n=9;
		solution(n);
	}

}
