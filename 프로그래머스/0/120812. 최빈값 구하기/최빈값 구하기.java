import java.util.HashMap;
import java.util.Map;

class Solution {
    public int solution(int[] array) {
        HashMap<Integer,Integer> a = new HashMap<>();
        for(int n : array){
            a.put(n,a.getOrDefault(n,0) + 1);            
        }
        
    
        
        int maxValue = 0;
        int maxKey = 0;
        for(Map.Entry<Integer, Integer> entry : a.entrySet()){
            int key = entry.getKey();
            int value = entry.getValue();
            
            if(maxValue < value){
                maxValue = value;
                maxKey = key;
            }
        }
        
        
        int maxValueCnt=0;
        for(int value : a.values()){
            if(value == maxValue) maxValueCnt++;
        }
        
        
        
        return maxValueCnt > 1 ? -1 : maxKey;
    }
}