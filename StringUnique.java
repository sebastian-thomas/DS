import java.io.*;
import java.util.*;

public class StringUnique {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		char s[]=null;
		int len=0, flag = 0;
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		HashMap  map = new HashMap();
		
		System.out.println("Enter string : ");
		try{
			s = br.readLine().toCharArray();
		}
		catch(Exception e){
			e.printStackTrace();
		}
		len = s.length;
		
		//using extra data structure
		for(int i=0 ; i <len; ++i){
			if(map.containsKey(s[i])){
				flag = 1;
				break;
			}
			else{
				map.put(s[i], 1);
			}
		}
		
		if(flag == 0)
			System.out.println("Unique Characters");
		
		//without extra data structure
		flag = 0;
		for(int i = 0 ; i < len-1 ; ++i){
			for(int j = i+1; j < len; ++j ){
				if(s[i] == s[j]){
					flag = 1;
					break;
				}
			}
			if(flag == 1)
				break;
		}
		
		if(flag == 0)
			System.out.println("Unique Characters");
		else
			System.out.print("not uniqe");

	}

}
