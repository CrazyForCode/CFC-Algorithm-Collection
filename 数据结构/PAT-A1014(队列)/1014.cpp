#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct custumer {
    int id;
    int queryTime;
}customers[1001], lines[21][11];

int queris[1001] = {0};
int endtimes[1001] = {0};
int n, m, k, q;
int timer;

void getTimeFrom8(char *a, int cus, int mins) {
    if (mins - customers[cus].queryTime > 539) {
        char temp[6] = "Sorry";
        strcpy(a, temp);
        return;
    }
    int hour = mins / 60;
    hour += 8;
    int min = mins % 60;
//    char a[6];
    if (hour > 9) {
        a[0] = hour / 10 + '0';
        a[1] = hour % 10 + '0';
    } else {
        a[0] = '0';
        a[1] = hour + '0';
    }
    a[2] = ':';
    if (min > 9) {
        a[3] = min / 10 + '0';
        a[4] = min % 10 + '0';
    } else {
        a[3] = '0';
        a[4] = min + '0';
    }
    a[5] = 0;
}

void printLines() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%3d ", lines[i][j].queryTime);
        }
        printf("\n");
    }
}

int shortestOne() {
    int shortest = 1e9;
    for (int i = 0; i < n; ++i) {
        if (lines[i][0].queryTime != 0 && lines[i][0].queryTime < shortest) {
            shortest = lines[i][0].queryTime;
        }
    }
    return shortest;
}

void passTime(int sec) {
    timer += sec;
    for (int i = 0; i < n; ++i) {
        if (lines[i][0].queryTime) {
            lines[i][0].queryTime -= sec;
        }
    }
}

void shift() {
    for (int i = 0; i < n; ++i) {
        if (lines[i][0].id != -1 && lines[i][0].queryTime == 0) {
            endtimes[lines[i][0].id] = timer;
            lines[i][0].id = -1;
        }
        for (int j = 0; j < m-1; ++j) {
            if (lines[i][j].queryTime == 0 && lines[i][j+1].queryTime) {
                lines[i][j].queryTime = lines[i][j+1].queryTime;
                lines[i][j].id = lines[i][j+1].id;

                lines[i][j+1].queryTime = 0;
                lines[i][j+1].id = -1;
            }
        }
    }
}

bool isAvailable() {

    for (int i = 0; i < n; ++i) {
        if (lines[i][m-1].queryTime == 0) {
            return true;
        }
    }
    return false;
}

bool isDone() {

    for (int i = 0; i < n; ++i) {
        if (lines[i][0].queryTime != 0) {
            return false;
        }
    }
    return true;
}

void push(int cus) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (lines[j][i].queryTime == 0) {
                lines[j][i] = customers[cus];
                return;
            }
        }
    }
}

int main() {
    timer = 0;
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &customers[i].queryTime);
        customers[i].id = i;
    }
    for (int i = 0; i < q; ++i) {
        scanf("%d", &queris[i]);
    }

    int currentCustomer = 0;
    push(currentCustomer++);
    while (!isDone()) {
        while (isAvailable() && currentCustomer < k) {
            push(currentCustomer++);
        }

        passTime(shortestOne());
        shift();
//        printLines();
    }
    char a[6];
    for (int i = 0; i < q; ++i) {
        getTimeFrom8(a, queris[i] - 1, endtimes[queris[i]-1]);
        printf("%s\n", a);
    }
    return 0;
}
