
import java.io.*;
import java.util.*;

public class Coins {

	/**
	 * @param args
	 * 
	 * soln to http://ww2.codechef.com/problems/COINS
	 * 
	 */
	
	static HashMap <Long,Long> hasm = new HashMap <Long,Long>();
	
    public static long checkValue(long n){
    	if(n <= 0){
    		return 0;
    	}
    	else if(hasm.get(n)!= null){
    		return hasm.get(n);
    	}
    	else{
    		long v =Math.max(n, checkValue(n/2) + checkValue(n/3) +checkValue(n/4));
    		hasm.put(n, v);
    		return v;
    	}
    	
    }
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		long n=0;
		BufferedReader r = new BufferedReader(new InputStreamReader (System.in));
		String s;
		do{
			try{
				s = r.readLine();
				n = (long)Integer.parseInt(s);
				if(s==null){
					break;
				}
				System.out.println(checkValue(n));
			}
			catch(Exception e){
				break;
			}
		}while(s != null);

	}

}
