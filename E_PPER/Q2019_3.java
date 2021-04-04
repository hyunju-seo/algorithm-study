import java.util.Arrays;

//public class Q2019_3 {
//	static char solution(String inp1, String inp2) {
//		int alpha[]= new int[50];
//		inp1=inp1.toUpperCase();
//		inp2=inp2.toUpperCase();
//		for(int i=0;i<inp1.length();i++) {
//			int n=inp1.charAt(i)-'A';
//			alpha[n]+=1;
//		}
//		for(int i=0;i<inp2.length();i++) {
//			int n=inp2.charAt(i)-'A';
//			if(alpha[n]<=0) {
//				return 'F';
//			}
//			alpha[n]-=1;
//		}
//		return 'T';
//	}
//	
//	public static void main(String args[]) {
////		String inp1="Listen";
////		String inp2="Slient";
//		String inp1= "What";
//		String inp2="Ewha";
//		System.out.println(solution(inp1,inp2));
//	}
//
//}
public class Q2019_3 {
	static char solution(String inp1, String inp2) {
		inp1=inp1.toUpperCase();
		inp2=inp2.toUpperCase();
		char arr[]=inp1.toCharArray();
		char arr2[]=inp2.toCharArray();
		Arrays.sort(arr);
		Arrays.sort(arr2);
		if(Arrays.equals(arr,arr2)) {
			return 'T';
		}else return 'F';

	}
	
	public static void main(String args[]) {
//		String inp1="Listen";
//		String inp2="Slient";
		String inp1= "What";
		String inp2="Ewha";
		String inp3=inp1;
		System.out.println(solution(inp1,inp2));
	}

}
