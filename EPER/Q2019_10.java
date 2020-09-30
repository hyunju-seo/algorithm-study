//
//public class Q2019_10 {
//	public static void solution(String[] dest, String goal) {
//		int charlist[]=new int[40];
//		for(String s : dest) {
//			
//			for(int i=0;i<goal.length();i++) {
//				if(s.charAt(i)!=goal.charAt(i)) continue;
//				if(i==goal.length()-1) {
//					if(s.length()>goal.length()) {
//						charlist[s.charAt(i+1)-'A']=1;
//					}
//				}
//			}
//			
//		}
//		for(int i=0;i<4;i++) {
//			for(int j=0;j<8;j++) {
//				int idx=i*8+j-3;
//
//				if(i==0&&j==0 ||i==0&&j==1||i==0&&j==2||i==3&&j==5||i==3&&j==6||i==3&&j==7) {
//					System.out.print('*');
//				}
//				else if(idx>=0&&charlist[idx]==1) {
//					
//					System.out.print((char)('A'+idx));
//				}
//				else System.out.print('*');
//			}
//			System.out.println();    
//		}
//
//	}
//	public static void main(String args[]) {
//		int n=4;
//		String[] dest1= {"ZAGREB","SISAK","ZADAR","ZABOK"};
//		String[] dest2= {"SPLIT","VINKOVCI","NOVSKA","RIJEKA"};
//		String[] dest3= {"AAAABCD","AAAABCA","AAAACDE","AAAAAAA"};
//		String goal1="ZA";
//		String goal2="VINKO";
//		String goal3="AAAA";
//		solution(dest3,goal3);
//	}
//}
//
public class Q2019_10 {
	public static void solution(String[] dest, String goal) {
		char charlist[]=new char[40];
		for(int i=0;i<charlist.length;i++) {
			charlist[i]='*';
		}
		for(String s : dest) {
			if(goal.equals(s.substring(0,goal.length()))) {
				char nextchar=s.charAt(goal.length());
				charlist[nextchar-62]=nextchar;
			}
			
		}
		for(int i=0;i<4;i++) {
			for(int j=0;j<8;j++) {
				System.out.print(charlist[i*8+j]);
			}System.out.println();
		}

	}
	public static void main(String args[]) {
		int n=4;
		String[] dest1= {"ZAGREB","SISAK","ZADAR","ZABOK"};
		String[] dest2= {"SPLIT","VINKOVCI","NOVSKA","RIJEKA"};
		String[] dest3= {"AAAABCD","AAAABCA","AAAACDE","AAAAAAA"};
		String goal1="ZA";
		String goal2="VINKO";
		String goal3="AAAA";
		solution(dest1,goal1);
	}
}