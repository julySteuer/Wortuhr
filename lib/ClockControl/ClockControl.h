namespace ClockControl {
    enum Deliminator {
        Vor = 0,
        Nach = 1,
        None
    };

    struct t_TimeProperty { // 20 (preNum) nach (delim) zwölf (hour)
        int preNum;
        Deliminator delim; 
        int hour;
    };

    t_TimeProperty parseTime(int hour, int minute) {
        t_TimeProperty currTime;

        int nextRoundNum = (minute - minute % 5);
        if (nextRoundNum <= 20) {
            currTime.hour = hour;
            currTime.preNum = nextRoundNum;
            currTime.delim = Deliminator::Nach;
        } else {
            if (nextRoundNum == 25) {
                currTime.preNum = 25;
                currTime.delim = Deliminator::Nach;
            } 
            currTime.hour = hour + 1;
            if (nextRoundNum == 35) {
                currTime.preNum = 25;
                currTime.delim = Deliminator::Vor;
            }
            if (nextRoundNum == 30) {
                currTime.preNum = 30;
                currTime.delim = Deliminator::None;
            }
            if (nextRoundNum >= 40) {
                currTime.preNum = 60 - nextRoundNum;
                currTime.delim = Deliminator::Vor;
            }
        }
        return currTime;
    }
}