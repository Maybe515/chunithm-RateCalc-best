#include <stdio.h>
#include <math.h>

#define MAX_SCORE 1010000

// 小数第N位切り捨て
double floorN(double value, int n) {
    double factor = pow(10.0, n);
    return floor(value * factor) / factor;
}

// 貢献値を計算する関数
double calcRatingValue(int score, double chartConst) {
    double rc = 0.0; // 上昇分
    double rv = 0.0; // 貢献値

    if (score >= 1007500) {
        rv = chartConst + 2;
    } else if (score >= 1005000) {
        chartConst += 1.5;
        rc = (score - 1005000) * 0.0002;
        rv = chartConst + rc;
    } else if (score >= 1000000) {
        chartConst += 1.0;
        rc = (score - 1000000) * 0.0001;
        rv = chartConst + rc;
    } else if (score >= 975000) {
        rc = (score - 975000) * 0.00004;
        rv = chartConst + rc;
    } else if (score >= 950000) {
        chartConst -= 1.5;
        rc = (score - 950000) * 0.00006;
        rv = chartConst + rc;
    } else if (score >= 925000) {
        chartConst -= 3.0;
        rc = (score - 925000) * 0.00006;
        rv = chartConst + rc;
    } else if (score >= 900000) {
        chartConst -= 5.0;
        rc = (score - 900000) * 0.00008;
        rv = chartConst + rc;
    } else if (score >= 800000) {
        chartConst -= 7.5;
        rc = (score - 800000) * 0.000025;
        rv = chartConst + rc;
    } else if (score >= 700000) {
        chartConst -= 8.5;
        rc = (score - 700000) * 0.00001;
        rv = chartConst + rc;
    } else if (score >= 600000) {
        chartConst -= 9.0;
        rc = (score - 600000) * 0.000005;
        rv = chartConst + rc;
    } else if (score >= 500000) {
        chartConst -= 13.7;
        rc = (score - 500000) * 0.000047;
        rv = chartConst + rc;
    }

    rv = floorN(rv, 2);
    if (rv < 0) rv = 0;

    printf("上昇分: %.2f + %.6f\n", chartConst, rc);
    return rv;
}

int main(void) {
    int score;
    double chartConst;
    int retry;

    printf("チュウニズム 貢献値計算機\n指定した「スコア」と「譜面定数」から【貢献値】を算出します\n\n");

    do {
        // スコア入力
        do {
            printf("スコア: ");
            scanf("%d", &score);
            if (score > MAX_SCORE) {
                printf("理論値を超えています。もう一度入力してください。\n");
            }
        } while (score > MAX_SCORE);

        // 譜面定数入力
        printf("譜面定数: ");
        scanf("%lf", &chartConst);

        // 計算
        double ratingValue = calcRatingValue(score, chartConst);

        // 出力
        printf("貢献値は「%.2f」です\n\n", ratingValue);

        // 再入力確認
        printf("再入力する場合は「1」を入力: ");
        scanf("%d", &retry);
        printf("-----\n");

    } while (retry == 1);

    printf("Finished\n");
    return 0;
}
