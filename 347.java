import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

// Top K Frequent Elements
// Heap
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> freq = new HashMap<Integer, Integer>();
        for(int i: nums) {
            freq.put(i, freq.getOrDefault(i, 0) + 1);
        }
        
        for(Map.Entry<Integer, Integer> val : freq.entrySet()) {
            System.out.println(String.format("%d %d", val.getKey(), val.getValue()));
        }
        PriorityQueue<ArrayList<Integer>> minHeap = 
            new PriorityQueue<ArrayList<Integer>>((a,b) -> a.get(1) - b.get(1));
        for(Map.Entry<Integer, Integer> val : freq.entrySet()) {
            ArrayList<Integer> newVal = new ArrayList<Integer>();
            newVal.add(val.getKey());
            newVal.add(val.getValue());
            minHeap.offer(newVal);
            System.out.println(String.format("Offered: %d %d", newVal.get(0), newVal.get(1)));
            if (minHeap.size() > k) {
                minHeap.poll();  
            }
        }
        int[] res = new int[k];
        for (int i = 0; i < k; i++) {
            res[i] = minHeap.poll().get(0);
        }
        return res;
    }
}
