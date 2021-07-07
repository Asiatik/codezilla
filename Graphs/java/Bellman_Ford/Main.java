import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
	static class Ford {
		public static final String INPUT_FILE = "example_in";
		public static final String OUTPUT_FILE = "example_out";
		public static final int NMAX = 50005;

		int n;
		int m;
		int source;

		public class Edge {
			public int node;
			public int cost;

			Edge(int _node, int _cost) {
				node = _node;
				cost = _cost;
			}
		}

		@SuppressWarnings("unchecked")
		ArrayList<Edge> adj[] = new ArrayList[NMAX];

		private void readInput() {
			try {
				Scanner sc = new Scanner(new BufferedReader(new FileReader(
								INPUT_FILE)));
				n = sc.nextInt();
				m = sc.nextInt();
				source = sc.nextInt();

				for (int i = 1; i <= n; i++)
					adj[i] = new ArrayList<>();
				for (int i = 1; i <= m; i++) {
					int x, y, w;
					x = sc.nextInt();
					y = sc.nextInt();
					w = sc.nextInt();
					adj[x].add(new Edge(y, w));
				}
				sc.close();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}

		private void writeOutput(ArrayList<Integer> result) {
			try {
				BufferedWriter bw = new BufferedWriter(new FileWriter(
								OUTPUT_FILE));
				StringBuilder sb = new StringBuilder();
				if (result.size() == 0) {
					sb.append("Ciclu negativ!\n");
				} else {
					for (int i = 1; i <= n; i++) {
						sb.append(result.get(i)).append(' ');
					}
					sb.append('\n');
				}
				bw.write(sb.toString());
				bw.close();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}

		private ArrayList<Integer> getResult() {
			// Find the minimul distances from the source node to all the other nodes
			// using BellmanFord on the oriented graph with n nodes, m edges stored in adj
			// d[node] = minim cost / minimum length of a path from source to the "node" node.
			// d[source] = 0;
			// d[node] = -1, if we can't reach "node" from the source.


			// An edge is a pair (conected node, edge cost):
			//	adj[x].get(i).node = the node conected to x,
			//	adj[x].get(i).cost = the cost.

			ArrayList<Integer> d = new ArrayList<>();
			ArrayList<Integer> p = new ArrayList<>();
			for (int i = 0; i <= n; i++) {
				p.add(-1);
				d.add(999999999);
			}
			d.set(source, 0);
			for (int i = 1; i <= n-2; i++) {
				for (int j = 1; j <= n; j++) {
					for (Edge w : adj[j]) {
						if (d.get(w.node) > d.get(j) + w.cost) {
							d.set(w.node, d.get(j) + w.cost);
							p.set(w.node, j);
						}
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				for (Edge w : adj[i]) {
					if (d.get(w.node) > d.get(i) + w.cost) {
						// We can continue the relaxation so there is a negative cost cycle
						return new ArrayList<Integer>();
					}
				}
			}
			return d;
		}

		public void solve() {
			readInput();
			writeOutput(getResult());
		}
	}

	public static void main(String[] args) {
		new Ford().solve();
	}
}
