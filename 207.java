import java.util.ArrayList;
import java.util.LinkedList;

// Course Schedule
// Toposort, BFS
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] indeg = new int[numCourses];
        ArrayList<ArrayList<Integer>> adjMat = new ArrayList<ArrayList<Integer>>();
        boolean[] visited = new boolean[numCourses];
        for (int i = 0; i < numCourses; i++) {
            indeg[i] = 0;
            visited[i] = false;
            adjMat.add(new ArrayList<Integer>());
        }
        int n = prerequisites.length;
        for (int i = 0; i < n; i++) {
            int[] pre = prerequisites[i];
            indeg[pre[0]]++;
            adjMat.get(pre[1]).add(pre[0]);
        }
        int reachableCourses = 0;
        LinkedList<Integer> queue = new LinkedList<Integer>();
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                queue.offer(i);
                visited[i] = true;
                reachableCourses++;
            }
        }
        if (queue.isEmpty()) return false;
        
        while(!queue.isEmpty()) {
            int node = queue.poll();
            ArrayList<Integer> adjNodes = adjMat.get(node);
            for (int i = 0; i < adjNodes.size() ;i++) {
                int nextCourse = adjNodes.get(i);
                indeg[nextCourse] -= 1;
                if (!visited[nextCourse] && indeg[nextCourse] == 0) {
                    visited[nextCourse] = true;
                    reachableCourses++;
                    queue.offer(adjNodes.get(i));
                }
            }
        }
        return reachableCourses == numCourses;
    }
}
