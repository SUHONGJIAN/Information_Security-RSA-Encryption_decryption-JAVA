package 穷举法求d;
public class SU {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int e = 89,p = 71,q = 83,r;
		r = (p-1)*(q-1);
		long starTime=System.currentTimeMillis();
		for(int i = 1; i < 1000; i++)
		{
			for(int j = 1; j <1000; j++)
			{
				if(e * i - r * j ==1 )
				{
					System.out.println("d = " + i);
					long endTime=System.currentTimeMillis();
					long Time=endTime-starTime;
					System.out.println("用时：" + Time + "ms");
					System.exit(0);
				}
			}
		}
	}
}
