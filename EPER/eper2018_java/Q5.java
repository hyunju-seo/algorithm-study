//import java.util.*;
//public class Q5 {
//	public static String solution(int inp[]) {
//		int desc[]= {8,7,6,5,4,3,2,1};
//		int asc[]= {1,2,3,4,5,6,7,8};
//		for(int i=0;i<8;i++) {
//			if(desc[i]!=inp[i]) break;
//			if(i==7) return "descending";
//			
//		}
//		for(int i=0;i<8;i++) {
//			if(asc[i]!=inp[i]) break;
//			if(i==7) return "ascending";
//			
//		}
//		return "mixed";
//	}
//	public static void main(String[] args) {
//		Scanner sc= new Scanner(System.in);
//		int inp[]= new int[8];
//		for(int i=0;i<8;i++) {
//			inp[i]=sc.nextInt();
//		}
//		System.out.println(solution(inp));
//	}
//
//}
import java.util.*;
public class Q5 {
	public static String solution(String s) {
		String desc= "8 7 6 5 4 3 2 1";
		String asc="1 2 3 4 5 6 7 8 9";
		if(s.equals(desc)) return "descending";
		else if(s.equals(asc))return "ascending";
		
		
		return "mixed";
	}
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		String s=sc.nextLine();
		
		System.out.println(solution(s));
	}

}
