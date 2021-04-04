import java.util.Arrays;

public class Q3 {
	public static char solution(String str1, String str2) {
		str1=str1.toLowerCase();
		str2=str2.toLowerCase();
		char array1[]=str1.toCharArray();
		char array2[]=str2.toCharArray();
		Arrays.sort(array1);
		Arrays.sort(array2);
		if(Arrays.equals(array1, array2)) {
			return 'T';
		}else return 'F';

	}

	public static void main(String[] args) {
		String str1="Listen";
		String str2="Silent";
		
		String tstr1="What";
		String tstr2="Ewha";
		
		System.out.println(solution(str1,str2));
		System.out.println(solution(tstr1,tstr2));


	}

}
