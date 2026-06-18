class Solution {
public:
    double angleClock(int hour, int minutes) {
        // minhand= 360 degree / 60 = 6 degree/min
        // each min, min hand move 6 degree while the hour hand move 
        // 1 hour equals 30 degree angle and 1 hour equal 60 min 
        // so hour hand move (30/60)=0.5 degree/min
        // each hour the hour hand moves 30 degree/hour
        double hourangle= hour*30 + minutes*0.5;
        double minangle= minutes*6;
        double angle= abs(hourangle-minangle);
        return min(angle,360-angle);
    }
};