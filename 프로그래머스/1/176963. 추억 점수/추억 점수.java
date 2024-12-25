import java.util.HashMap;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        HashMap<String, Integer> yearnMap = new HashMap<>();
        for(int i=0;i<name.length;i++){
            yearnMap.put(name[i], yearning[i]);
        }
        
        int[] answer = new int[photo.length];
        for(int i=0;i<photo.length;i++){
            int sum=0;
            for(String person : photo[i]){
                sum += yearnMap.getOrDefault(person, 0);
            }
            answer[i] = sum;
        }
        return answer;
    }
}