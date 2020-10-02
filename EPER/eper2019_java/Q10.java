import java.util.*;
public class Q10 {

	public static void main(String[] args) {
		char keyboard[]= new char[32];
		for(int i=0;i<keyboard.length;i++) {
			keyboard[i]='*';
		}
		Scanner s= new Scanner(System.in);
		int n=s.nextInt();
		String str[]=new String[n+1];
		for(int i=0;i<n;i++) {
			str[i]=s.next();
		}
	
		String goal= s.next();
		for(int i=0;i<n;i++) {
			//if((str[i].substring(0,goal.length())).equals(goal)) {
			if(goal.equals(str[i].substring(0,goal.length()))){
				keyboard[str[i].charAt(goal.length())-'A'+3]=(char)(str[i].charAt(goal.length()));
			}
			
			
		}
		for(int i=0;i<32;i++) {
			System.out.print(keyboard[i]);
			if((i+1)%8==0) System.out.println();
		}

	}

}
