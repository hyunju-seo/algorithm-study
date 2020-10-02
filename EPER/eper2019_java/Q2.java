
public class Q2 {


	public static double solution(int scores[], int n) {
		int sum=0;
		for(int score:scores) {
			sum+=score;
		}
		double avg=(double)sum/scores.length;
	//	System.out.println(avg);
		int nans=0;
		for(int score:scores) {
			if(score>avg) {
				nans+=1;
			}
		}
		//System.out.println(nans);
		double ans=((double)nans/scores.length)*100;
		return ans;
	}
	public static void main(String[] args) {
		int n=5;
		int scores[]= {50,50,70,80,100};
		int n2=7;
		int scores2[]= {100, 95, 90, 80, 70, 60, 50};
		System.out.printf("%.3f%%",solution(scores,n));
		System.out.printf("%.3f%%",solution(scores2,n2));



	}

}
