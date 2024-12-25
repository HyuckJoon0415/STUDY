class Solution {
    public int[] solution(int n) {
        int cnt = (n%2==0) ? n/2 : n/2+1;
        
        int[] arr = new int[cnt];
        int arrIdx=0;
        for(int i=0;i<=n;i++){
            if(i%2!=0){
                arr[arrIdx] = i;
                arrIdx++;                
            }            
        }        
        return arr;
    }
}