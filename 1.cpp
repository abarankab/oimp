struct TimeLogger() {
    const long start;
    long current_time;

    TimeLogger() {
        start = Now();
    }

    ~TimeLogger() {
        current_time 

