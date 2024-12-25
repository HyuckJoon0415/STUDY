class Solution {
    public int solution(int n) {
        int pizzaCnt = n/7;
        int remainingPeople = n%7;
        
        return remainingPeople==0?pizzaCnt:pizzaCnt+1;
    }
}