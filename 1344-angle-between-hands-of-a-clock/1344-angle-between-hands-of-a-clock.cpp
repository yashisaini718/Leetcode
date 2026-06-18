class Solution {
public:
    double angleClock(int hour, int minutes) {
        //each min, min hand move 6 degree while the hour hand move (30/60)=0.5 degree
        // each hour the hour hand moves 30 degree
        double hourangle= hour*30 + minutes*0.5;
        double minangle= minutes*6;
        double angle= abs(hourangle-minangle);
        return min(angle,360-angle);
    }
};