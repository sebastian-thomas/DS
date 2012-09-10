
import java.io.*;

class Stack
{
	int [] st;
	int top;
	
	Stack(int sz)
	{
		st=new int[sz];
		top=-1;
	}
	
	void push(int val)
	{
		if(top<st.length)
		{
			st[++top]=val;
		}
		else
		{
			System.out.println("Stack size finished");
		}
	}
	
	int pop()
	{
		if(top==-1)
			return -1;
		else
			return st[top--];
	}
	
	int getTop()
	{
		return top;
	}
	
	int getTopEle()
	{
		return st[top];
	}
}

public class StackArray
{
	
	public static void main(String args[])
	{
		int sz=0;
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		String ins="0";
		
		try
		{
			ins=br.readLine();
			sz=Integer.parseInt(ins);
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		
		Stack s=new Stack(sz);
		s.push(4);
		s.push(8);
		s.push(12);
		
		System.out.println(s.pop());
		System.out.println(s.pop());
		
	}
	
}