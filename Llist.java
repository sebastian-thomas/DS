
class Node {
	Node next = null;
	int data;
	
	public Node(int d){
		data = d;
	}
	
	void appendToTail(int d){
		Node end = new Node(d);
		Node n = this;
		while(n.next != null){
			n = n.next;
		}
		n.next = end;
	}
	
	Node deleteNode(int d){
		Node n = this;
		if(n.data == d){
			return n.next;
		}
		while(n.next != null){
			if(n.next.data == d){
				n.next = n.next.next;
				return this;
			}
			n = n.next;
		}
		return this;
		
	}
	
	void printNodes(){
		Node n = this;
		while(n!= null){
			System.out.println(n.data);
			n = n.next;
		}
	}
}


public class Llist {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Node a = new Node(5);
		a.appendToTail(6);
		a.appendToTail(9);
		a.printNodes();
		a = a.deleteNode(6);
		a.printNodes();
		a = a.deleteNode(5);
		a.printNodes();

	}

}
