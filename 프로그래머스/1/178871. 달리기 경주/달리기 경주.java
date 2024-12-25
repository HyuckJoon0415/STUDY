import java.util.HashMap;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        HashMap<Integer, String> ranking = new HashMap<>();
        HashMap<String, Integer> record = new HashMap<>();
        for(int i=0;i<players.length;i++){
            ranking.put(i,players[i]);
            record.put(players[i],i);
        }
        
        for(String player : callings){
            int oldRanking = record.get(player);
            int newRanking = oldRanking - 1;
            String fallPlayer = ranking.get(newRanking);
            
            ranking.replace(newRanking,player);
            ranking.replace(oldRanking,fallPlayer);
            
            record.replace(player, newRanking);
            record.replace(fallPlayer, oldRanking);
        }
        
        String[] result = new String[ranking.size()];
        for(int i=0;i<ranking.size();i++){
            result[i] = ranking.get(i);
        }
        
        return result;
    }
}