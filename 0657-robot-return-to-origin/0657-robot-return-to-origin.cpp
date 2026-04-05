class Solution {
public:
    bool judgeCircle(string moves) {
        int startx = 0;
        int starty = 0;
        for(int i = 0; i < moves.size(); i++){
            if(moves[i] == 'R')
                startx++;
            if(moves[i] == 'L')
                startx--;
            if(moves[i] == 'U')
                starty--;
            if(moves[i] == 'D')
                starty++;
        }
        if(startx == 0 && starty == 0){
            return true;
        }
        else 
            return false;
    }
};