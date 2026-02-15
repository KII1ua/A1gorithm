class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int hp = health;
        int lasttime = 0;
        
        for(int[] attack : attacks) {
            int attacktime = attack[0];
            int damage = attack[1];
            
            int gap = attacktime - lasttime - 1;
            int bonus_hp = (gap / bandage[0]) * bandage[2];
            
            hp = Math.min(health, hp + bonus_hp + gap * bandage[1]);
            
            hp -= damage;
            
            if(hp <= 0) return -1;
            
            lasttime = attacktime;
        }
        
        return hp;
    }
}