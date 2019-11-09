import java.util.ArrayList;
import java.util.Scanner;

public class HeapSort {

	public static class Heap {

		private ArrayList<Integer> heap = new ArrayList<>();

		public boolean isEmpty(){
			return heap.size() == 0;
		}

		public int size(){
			return heap.size();
		}

		public int getMin(){
			if(isEmpty()){
				return -1;
			}
			return heap.get(0);
		}

		public void insert(int node){
			heap.add(node);
			int childIndex = heap.size() - 1;
			int parentIndex = (childIndex-1)/2;
			while(childIndex > 0){
				int child = heap.get(childIndex);
				int parent = heap.get(parentIndex);
				if(child < parent){
					heap.set(parentIndex, child);
					heap.set(childIndex, parent);
					childIndex = parentIndex;
					parentIndex = (childIndex-1)/2;
				}
				else{
					return;
				}
			}
		}

		public int removeMin(){
			if(isEmpty()){
				return -1;
			}
			int temp = heap.get(0);
			heap.set(0, heap.get(heap.size()-1));
			heap.remove(heap.size() - 1);
			if(heap.size() > 0){
				downHeapify(0);
			}
			return temp;
		}

		private void downHeapify(int index) {
			int leftIndex = 2*index + 1;
			int rightIndex = 2*index + 2;
			if(leftIndex >= heap.size()){
				return;
			}
			int maxIndex = index;
			if(heap.get(leftIndex) < heap.get(maxIndex)){
				maxIndex = leftIndex;
			}
			if(rightIndex < heap.size() && heap.get(rightIndex) < heap.get(maxIndex)){
				maxIndex = rightIndex;
			}
			if(maxIndex != index){
				int temp = heap.get(index);
				heap.set(index, heap.get(maxIndex));
				heap.set(maxIndex, temp);
				downHeapify(maxIndex);
			}
		}
	}

	public static void main(String[] args) {

		Heap heap = new Heap();
		Scanner s = new Scanner(System.in);
		System.out.println("Enter number of elements:");
		int n = s.nextInt();
		System.out.println("Enter the array:");
		for(int i=0; i<n; i++){
			heap.insert(s.nextInt());
		}
		int array[] = new int[n];
		int i=0;
		while(!heap.isEmpty()){
			array[i] = heap.removeMin();
			i++;
		}
		for(i=0; i<n; i++){
			System.out.println(array[i]);;
		}
	}

}
