public class DynamicQueue extends Queue {
	@Override
	public void enQueue(int item) throws Exception {
		if (this.size() == this.data.length) {
			int[] os = this.data;
			int[] ns = new int[os.length * 2];
			int f = this.front;
			int s = this.size;
			int j = (f + s) % this.data.length;

			for (int i = 0; i < this.size(); i++) {
				ns[i] = os[j];
				s++;
				j = (f + s) % this.data.length;
			}
			this.front = 0;
			this.data = ns;

		}
		super.enQueue(item);

	}

}
