import java.util.*;
public class Q6 {
	public static String solution(String str, String finalstr) {
		str=str.toLowerCase();
		finalstr=finalstr.toLowerCase();
		char strarr[]=str.toCharArray();
		char finalarr[]=finalstr.toCharArray();
		Arrays.sort(strarr);
		Arrays.sort(finalarr);
		
	
		if(Arrays.equals(finalarr,strarr)) {
			return "Yes";
			
		}
		return "NO";
	}

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		String str=sc.next();
		String finalstr=sc.next();
		System.out.println(solution(str,finalstr));

	}

}
