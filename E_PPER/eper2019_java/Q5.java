import java.util.*;
//public class Q5 {
//	public static ArrayList<String> solution(int k, int n, String[] inp, char[] alpha) {
//		ArrayList<String> arr[] = new ArrayList[30];
//		int ldx[]=new int[30];
//		for(int i=0;i<ldx.length;i++) {
//			ldx[i]=-1;
//		}
//		ArrayList<String> answers= new ArrayList();
//		for(int i=0;i<arr.length;i++) {
//			arr[i]=new ArrayList<String>();
//		}
//		for(String s: inp) {
//			arr[s.charAt(0)-'a'].add(s);
//		}
//		for(int i=0;i<arr.length;i++) {
//			Collections.sort(arr[i]);
//		}
//
//		for(char c: alpha) {
//			int id=ldx[c-'a'];
//			if(id+1>=arr[c-'a'].size()) {
//				id=0;
//				ldx[c-'a']=0;
//			}else{
//				id=id+1;
//				ldx[c-'a']+=1;
//			}		
//			answers.add(arr[c-'a'].get(id));
//		}
//		return answers;
//	}
//	public static void main(String args[]) {
//		int k =4;
//		int n=5;
//		int k1=5;
//		int n1=3;
//		int k2=1;
//		int n2=3;
////		String[] inp= {"zagreb", "split", "zadar","sisak"};
////		char[] alpha= {'z','s','s','z','z'};
////		String[] inp= {"london", "rim","pariz",	"moskva",	"sarajevo"};
////		char[] alpha= {'p','r','p'};
//		String[] inp= {"zagreb"};
//		char[] alpha= {'z','z','z'};
//		ArrayList<String> answers= solution(k2,n2,inp,alpha);
//		for(String s: answers) {
//			System.out.println(s);
//		}
//	}
//}
class Word implements Comparable<Word>{
	public String word;
	public int count;
	public Word(String word, int count) {
		this.word=word;
		this.count=count;
	}
	@Override
	public int compareTo(Word obk) {
		if(this.count==obk.count) {
			return this.word.compareTo(obk.word); //String¿« compareTo
		}
		return this.count-obk.count;
	}
		
}


class Q5{
	
	public static ArrayList<String> solution(int k, int n, String[] inp, char[] alpha) {
		PriorityQueue<Word> arr[]=new PriorityQueue[30];
		ArrayList<String> answers= new ArrayList<String>();
		for(int i=0;i<arr.length;i++) {
			arr[i]=new PriorityQueue<Word>();
		}
		for(String s:inp) {
			arr[s.charAt(0)-'a'].add(new Word(s,0));
		}
		for(char c: alpha) {
			Word w=arr[c-'a'].poll();
			answers.add(w.word);
			arr[c-'a'].add(new Word(w.word,w.count+1));
		}
		return answers;
	}

	public static void main(String args[]) {
		int k =4;
		int n=5;
		int k1=5;
		int n1=3;
		int k2=1;
		int n2=3;
		String[] inp= {"zagreb", "split", "zadar","sisak"};
	char[] alpha= {'z','s','s','z','z'};
		ArrayList<String> answers= solution(k1,n1,inp,alpha);
		for(String s: answers) {
			System.out.println(s);
		}
		System.out.println();
		String[] inp1= {"london", "rim","pariz",	"moskva",	"sarajevo"};
		char[] alpha1= {'p','r','p'};
		ArrayList<String> answers1= solution(k1,n1,inp1,alpha1);
		for(String s: answers1) {
			System.out.println(s);
		}
		System.out.println();

		String[] inp2= {"zagreb"};
		char[] alpha2= {'z','z','z'};
		ArrayList<String> answers2= solution(k2,n2,inp2,alpha2);
		for(String s: answers2) {
			System.out.println(s);
		}
	}
}
