import java.util.*;
public class Q3 {
/*	public static ArrayList<Character> solution(String s) {
		char arr[]=s.toCharArray();
		ArrayList<Character> answers=new ArrayList<>();
		answers.add(arr[0]);
		for(int i=1;i<arr.length;i++) {
			if(arr[i]=='-' && i!=arr.length-1) {
				answers.add(arr[i+1]);
			}
		}
		return answers;

	}
*/
	public static ArrayList<Character> solution(String s) {
		ArrayList<Character> answers= new ArrayList<>();
		String arr[]=s.split("-");
		for(String str: arr) {
			answers.add(str.charAt(0));
		}
		return answers;
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		
		String s=sc.next();
		ArrayList<Character> answers= solution(s);
		for(char a:answers) {
			System.out.print(a);
		}
	

	}

}
