
public class Q7 {
	public static void solution(int r, int c, int zr, int zc, char[][] inp) {
		for(int i=0;i<r;i++) {
			for(int zrr=1;zrr<=zr;zrr++) {
			for(int j=0;j<c;j++) {
				for(int zcc=1;zcc<=zc;zcc++) {
				System.out.print(inp[i][j]);}
			}
			System.out.println();}
		}
	}

	public static void main(String[] args) {
		int r=3, c=3, zr=1,zc=2;
		char inp[][]= {{'.','x','.'},{'x','.','x'},{'.','x','.'}};
		int r1=3,c1=3, zr1=2, zc1=1;
		char inp1[][]= {{'.','x','.'},{'x','.','x'},{'.','x','.'}};
solution(r,c,zr,zc,inp);
System.out.println();
solution(r1,c1,zr1,zc1,inp1);
	}

}
