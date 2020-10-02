//´Ù½Ã
public class Q6 {
	public static double[] solution(int x, int y) {
		double s=(double)250*250/4;
		double ansx,ansy;
		if(x==0) {
			if(y<125) {
				 ansx=(double)s*2/(250-y);
				 ansy=250-ansx;

			}
			else {
				ansy=0;
				ansx=(double)2*s/y;
			}

		}
		else if(y==0) {
			if(x<125) {
				 ansy=(double)s*2/(250-x);
				 ansx=250-ansy;
			}
			else {
				ansy=(double)2*s/x;
				ansx=0;

			}

		}
		else if(x<125) {
			 ansx=250-(double)2*s/y;
			 ansy=0;

		}
		else {
			 ansy=250-(double)2*s/x;
			 ansx=0;
		}
		double answers[]= {ansx,ansy};
		return answers;
	}

	public static void main(String[] args) {
		int x=0;
		int y=0;
		double answers[]=solution(x,y);
		System.out.printf("%.2f %.2f",answers[0],answers[1]);
		System.out.println();
		
		int x1=230;
		int y1=20;		
		double answers1[]=solution(x1,y1);
		System.out.printf("%.2f %.2f",answers1[0],answers1[1]);
		System.out.println();

		int x2=0;
		int y2=40;
		double answers2[]=solution(x2,y2);
		System.out.printf("%.2f %.2f",answers2[0],answers2[1]);
		
		
	}

}
