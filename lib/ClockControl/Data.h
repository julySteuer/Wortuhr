namespace Data {
    struct t_Word {
        int begin;
        int end;
    } Word;
    
    // Finish this 
    const t_Word minutes[5] = {{0,4}, {5,8}, {0,8}, {24,30}, {20,30}}; // Increments in 5 until 30
    const t_Word delims[2] = {{39, 42}, {46, 49}}; // static 
    const t_Word hours[12] = {{44,47}, {57,60}}; // incements in steps of 1 until 12

    t_Word getMinute(int minute) {
        return minutes[minute / 5 - 1];
    }

    t_Word getDelim(int index) {
        return delims[index];
    }

    t_Word getHour(int hour) {
        return hours[hour];
    }
}