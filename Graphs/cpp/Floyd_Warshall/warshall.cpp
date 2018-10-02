#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int kNmax = 105;

class Warshall {
 public:
	void solve() {
		read_input();
		compute();
		print_output();
	}

 private:
	int n;
	//result: 
	int d[kNmax][kNmax];
	
	//input matrix (the graph);
	int a[kNmax][kNmax];

	void read_input() {
		ifstream fin("input_example");
		fin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				fin >> a[i][j];
			}
		}
		fin.close();
	}

	// Floyd Warshall algorithm implementation:
	void compute() {
		/*
		An edge (x, y, w) is represented as follows:
			a[x][y] = w;
		If there is no edge between x and y, in the Adjacency matrix:
		there will be the value 0:
			a[x][y] = 0;

		The matrix d[][] is the result:
			d[x][y] = minimal distance between x and y, if there is a path.
			d[x][y] = 0 if there is no path between x and y.
			d[x][x] = 0.
		*/

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (a[i][j]) {
					d[i][j] = a[i][j];
				}
				else {
					d[i][j] = 9999999;
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			d[i][i] = 0;
		}

		for (int k = 1; k <= n; ++k) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (d[i][j] > d[i][k] + d[k][j]) {
						d[i][j] = d[i][k] + d[k][j];
					}
				}
			}
		}

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (d[i][j] == 9999999) {
					d[i][j] = 0;
				}
			}
		}

	}

	void print_output() {
		ofstream fout("out");
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				fout << d[i][j] << ' ';
			}
			fout << '\n';
		}
		fout.close();
	}
};

int main() {
	Warshall *obj = new Warshall();
	obj->solve();
	delete obj;
	return 0;
}
