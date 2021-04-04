
public class Q2018_9 {
	public static int[] solution(int n ,int m) {
		int p=Math.min(n, m);
		int answers[] = new int[p+1];
		int total= n*m;
		if(n!=1 && m!=1) {
			//total=2*n+2*m-4;
			total-=(m-2)*(n-2);
		}
		int idx=0;
		answers[idx++]=1;
		//주의 (n-1) %2 이부분이랑 else if 사용하기
		for(int i=2;i<=p;i++) {
			if(total%i==0) {
				if(n%i==0 &&(m-2)%i==0) answers[idx++]=i;
				else if((n-1)%i==0) {
					if((m-2)%i==0&&m%i==0) answers[idx++]=i;
					else if((m-1)%i==0)answers[idx++]=i;
				}
				else if((n-2)%i==0&&m%i==0) answers[idx++]=i;
				else if((n-2)%i==0 && n%i==0 && (m-1)%i==0) {answers[idx++]=i;}

			}
		}

		return answers;
	}
	public static void main(String args[]) {
		int n=500;
		int m=500;
		int answers[]=solution(n,m);
		for(int i=0;i<answers.length;i++) {
			if(answers[i]!=0) System.out.print(answers[i]+" ");
		}
	}
}
