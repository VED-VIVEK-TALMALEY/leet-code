class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (hour==12)hour=0 ;
        double hour_angle = 30*hour + 0.5*minutes;
        double minute_angle = 6*minutes ;
        double len =abs(hour_angle-minute_angle);
        return(min(len,360.0-len));

    }
};