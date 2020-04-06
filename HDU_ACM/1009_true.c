#include<stdio.h>
#include<stdlib.h>

typedef struct k_ {
    double k;//存储每个房间中javabean和猫粮的比例

    int x;//存储房间号

}K_;

int cmp(const void *a, const void *b) {
    return *(double *)a > *(double *)b ? -1 : 1;
}


int main() {
    int j[1000], f[1000], i;
    K_ k[1000];
    int m, n;
    double javabean;
    while (scanf("%d%d", &m, &n) != EOF && !(m == -1 && n == -1)) {
        javabean = 0;
        for (i = 0; i < n; i++) {
            scanf("%d%d", &j[i], &f[i]);
            k[i].k = (double)j[i] / f[i];
            k[i].x = i;
        }
        qsort(k, n, sizeof(k[0]), cmp);
        for (i = 0; i < n; i++) {
            if (m > f[k[i].x]) {
                javabean += j[k[i].x];
                m -= f[k[i].x];
            }
            else {
                javabean += ((double)j[k[i].x] * ((double)m / f[k[i].x]));
                break;
            }
        }
        printf("%.3lf\n", javabean);
    }
    return 0;
}
