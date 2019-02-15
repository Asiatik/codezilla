/**
 * Author:  Aarya R Shankar
 * Title:   BFS traversal of a connected undirected unweighted graph, represented using an adjacency matrix
 *          Can be modified to apply on directed and/or weighted graphs.
 */

import java.io.*;
import java.util.*;

class Solution {

    // Vertices are named from 0 to v-1
    // graph[i][j] = 1, if there is an edge between the nodes i and j, else 0
    // In case of weighted graph,
    // graph[i][j] = k, where k is the weight of the edge from i to j
    static ArrayList<Integer> BFS(int graph[][], int start) {
        ArrayList<Integer> bfs = new ArrayList<Integer>();
        int v = graph.length;
        boolean visited[] = new boolean[v];
        Arrays.fill(visited, false);
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(start);
        visited[start] = true;
        while(!q.isEmpty()) {
            int node = q.poll();
            bfs.add(node);
            for(int i = 0; i < v; i++) {
                if(i != node && graph[node][i] != 0 && !visited[i]) {
                    q.add(i);
                    visited[i] = true;
                }
            }
        }
        return bfs;
    }

    public static void main(String args[])throws IOException {
        /**
        0 --- 4
        | \   | \
        |  \  |  \
        |   \ |   \
        1     2 --- 3
        */
        int graph[][] = {
        //
        /* 0 */ {0, 1, 1, 0, 1},
        /* 1 */ {1, 0, 0, 0, 0},
        /* 2 */ {1, 0, 0, 1, 1},
        /* 3 */ {0, 0, 1, 0, 1},
        /* 4 */ {1, 0, 1, 1, 0}
        };
        ArrayList<Integer> bfs = BFS(graph, 0);
        System.out.println("BFS traversal: "+ bfs);
    }
}