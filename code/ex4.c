typedef struct {
    int hour, minute;
} TimeT;

typedef struct {
    int day, month, year;
} DateT;

typedef struct {
    int TRANSACTION_NUMBER;
    char weekday[4];
    DateT date;
    TimeT time;
    char mode;
    char from[32], to[32];
    int journey;
    char fare_applied[12];
    float fare, discount, amount;
    

}