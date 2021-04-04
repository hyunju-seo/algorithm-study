import java.util.*;
public class Q2018_7 {
	public static int[] solution(int[] numbers) {
		int sum=0;
		int answers[] =new int[7];
		for(int i=0;i<9;i++) {
			sum+=numbers[i];
		}
		int ans1=-1;
		int ans2=-1;
		for(int i=0;i<9;i++) {
			for(int j=i+1;j<9;j++) {
			if(sum-numbers[i]-numbers[j]==100) {
				int idx=0;
				for(int k=0;k<9;k++) {
					if(k==i || k== j) continue;
					answers[idx++]=numbers[k];
				}
			}
		}
	}
		return answers;

}
public static void main(String[] args) {
	int numbers[]= {7,8,10,13,15,19,20,23,25};
	int answers[]=solution(numbers);
	for(int i=0;i<7;i++) {
		System.out.print(answers[i]+" ");
	}
}
}