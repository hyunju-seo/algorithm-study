
public class Q1 {
	public static char solution(int y) {
		char ans='F';
		if(y%4==0 && y%100!=0 ||y%400==0) ans='T';
		return ans;
		
	}
public static void main(String args[]) {
	//int y=2000;
	int y=1999;
	System.out.println(solution(y));

}
}
