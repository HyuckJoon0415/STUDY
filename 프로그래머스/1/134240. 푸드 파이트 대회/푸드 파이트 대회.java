class Solution {
    public String solution(int[] food) {
        StringBuilder sb = new StringBuilder();
        
        for(int i=1;i<food.length;i++){
            int len = food[i];
            for(int j=0;j<len/2;j++){
                sb.append(i);
            }
        }
        StringBuilder sbAnswer = new StringBuilder(sb);
        sbAnswer.append(0);
        sbAnswer.append(sb.reverse());
        
        String answer = sbAnswer.toString();        
        return answer;
    }
}