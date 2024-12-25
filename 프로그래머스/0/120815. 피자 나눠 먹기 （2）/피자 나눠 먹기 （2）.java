class Solution {
    public int solution(int n) {
        int gcd = caculatedGcd(n,6);
        int lcm = caculatedLcm(n,6,gcd);
        
        return lcm/6;
    }
    
    public int caculatedGcd(int a, int b){
        return b==0?a:caculatedGcd(b,a%b);
    }
    
    public int caculatedLcm(int a, int b, int gcd){
        return (a*b)/gcd;
    }
}