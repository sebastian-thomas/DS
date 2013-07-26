
class TNode{
	int data;
	TNode lchild = null;
	TNode rchild = null;
	
	public TNode(int d){
		data = d;
	}
	
	void insertToBST(int d){
		TNode tmp = new TNode(d);
		TNode n = this;
		while(n!=null){
			if(d < n.data){
				if(n.lchild == null){
					n.lchild = tmp;
					break;
				}
				else{
					n = n.lchild;
				}
			}
			else{
				if(n.rchild == null){
					n.rchild = tmp;
					break;
				}
				else{
					n = n.rchild;
				}
			}
		}
	}
	
	void inorder(TNode n){
		if(n == null)
			return;
		
		n.inorder(n.lchild);
		System.out.println(n.data);
		n.inorder(n.rchild);
		
	}
	
	void preorder(TNode n){
		if(n == null)
			return;
		System.out.println(n.data);
		n.inorder(n.lchild);
		n.inorder(n.rchild);
		
	}
}


public class BSTree {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TNode bst = new TNode(4);
		bst.insertToBST(6);
		bst.insertToBST(3);
		System.out.println("In");
		bst.inorder(bst);
		System.out.println("Pre");
        bst.preorder(bst);
	}

}
