#include <stdbool.h>

typedef struct SetRep *set;

set newSet(void);
void dropSet(set);
void setAdd(set, int);
void setRemove(set, int);
bool setContains(set, int);
void showSet(set);


