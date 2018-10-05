
import java.util.Scanner;

public class BinaryTree_Size {
	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {

		BinaryTree_Size bts = new BinaryTree_Size();
		BinaryTree bt = bts.new BinaryTree();
//		10 true 20 true 40 false false true 50 false false true 30 true 60 false
//		 false false		**Give this Input to create the tree**
		bt.display();
		System.out.println(bt.size2());

	}

	private class BinaryTree {

		private class Node {
			int data;
			Node left;
			Node right;
		}

		private Node root;
		private int size;

		public BinaryTree() {
			this.root = construct(null, false);
		}

		private Node construct(Node parent, boolean ilc) {

			if (parent == null) {
				System.out.println("Enter the data for root node ? ");
			} else {
				if (ilc) {
					System.out.println("Enter the data for left " + parent.data);
				} else {
					System.out.println("Enter the data for right " + parent.data);
				}
			}

			int val = scn.nextInt();
			Node nn = new Node(); 		// nn -> new node
			nn.data = val;
			this.size++;

			boolean lc;			// lc -> left child
			System.out.println("Do you want left child");
			lc = scn.nextBoolean();
			if (lc) {
				nn.left = construct(nn, true);
			}

			boolean rc;			// rc -> right child
			System.out.println("Do you want right child");
			rc = scn.nextBoolean();
			if (rc) {
				nn.right = construct(nn, false);
			}

			return nn;

		}

		public void display() {
			display(this.root);
		}

		private void display(Node node) {

			if (node == null) {
				return;
			}

			String str = "";

			if (node.left != null) {
				str += node.left.data;
			} else {
				str += ".";
			}

			str += "->" + node.data + "<-";

			if (node.right != null) {
				str += node.right.data;
			} else {
				str += ".";
			}
			System.out.println(str);
			display(node.left);
			display(node.right);

		}

		public int size2() {
			return size2(this.root);
		}

		private int size2(Node node) {

			if (node == null) {
				return 0;
			}

			int ls = size2(node.left);	// ls -> left size
			int rs = size2(node.right);	// rs -> right size

			return ls + rs + 1;

		}

	}
}
