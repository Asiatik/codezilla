import java.util.*;
public class CoinTower {
	public static  String coinTower(int n,int x,int y){
		
		int dp[]=new int[n+1];
      
      int max1=-1;
      int max2=-1;
      dp[0]=0;
      dp[1]=1;
      dp[x]=1;
      dp[y]=1;
      for(int i=2;i<=n;i++){
        
        int val=dp[i-1]^1;
      if(i-x>=0)
        max1=dp[i-x]^1;
        if(i-y>=0)
          max2=dp[i-y]^1;
        
        dp[i]=Math.max(val,Math.max(max1,max2));
      }
      
      if(dp[n]==1)
        return "A";
      else
        return "B";
		
	}

	public static void main(String[] args) {
		int n=0,x=0,y=0;
		Scanner s =new Scanner(System.in);
		n=s.nextInt();
		x=s.nextInt();
		y=s.nextInt();// a player can move 1 or x or y coins
		
		
		System.out.println(coinTower(n,x,y));
	}

}
