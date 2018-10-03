import java.util.Arrays;

/*
 * The Floyd-Warshall algorithm
 * find the all-pairs shortest path
 * in a weighted graph with either positive or negative weights
 * without negative edge cycles.
 *
 * Time complexity O(n^3), where n is the number of nodes
 *
 */
public class FloydWarshall {

    static final int INF = Integer.MAX_VALUE;
    static final int UNDEF = Integer.MIN_VALUE;
    static int n;
    static int[][][] dist;

    // Dynamic programming using memoization
    static int shortestPath(int[][] graph, int i, int j, int k) {
        if (k == -1) return graph[i][j];
        if (dist[i][j][k] != UNDEF) return dist[i][j][k];
        dist[i][j][k] = min(add(shortestPath(graph, i, k, k - 1), shortestPath(graph, k, j, k - 1)),
                shortestPath(graph, i, j, k - 1));
        return dist[i][j][k];
    }

    static int min(int x, int y) {
        return y > x ? x : y;
    }

    static int add(int x, int y) {
        return x == INF || y == INF ? INF : x + y;
    }


    public static void main(String[] args) {
        int[][] graph = {
                {0, 3, 8, INF, -4},
                {INF, 0, INF, 1, 7},
                {INF, 4, 0, INF, INF},
                {2, INF, -5, 0, INF},
                {INF, INF, INF, 6, 0}
        };

        n = graph.length;
        dist = new int[n][n][n];

        // initialize dist array
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                Arrays.fill(dist[i][j], UNDEF);
            }
        }

        // print out pair-wise shortest distance
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.printf("%3d", shortestPath(graph, i, j, n - 1));
            }
            System.out.println();
        }

    }
}