#include <stdio.h>
#include <stdlib.h>
#include "primeFactorization.h"

// 素数を取得する関数
int getPrime(int n, int *primes) {

    // 入力値Nまでの配列を作る(素数の検査用配列)
    int data[n + 1];

    // 配列dataの要素全てに1を入れる
    int i;
    for(i = 0; i < n + 1; i++) {
        data[i] = 1;
    }

    // 配列0と1には最初から0を入れておく(素数ではないため)
    data[0] = 0;
    data[1] = 0;

    // 素数の倍数
    int m = 2;
    // 配列の添字
    int count = 0;

    // 入力された数字が1であれば配列primesに1を入れて処理終了
    if(n == 1) {
        primes[0] = 1;
        primes[1] = 0;
        count = 1;

    } else {

        do {
            // 変数mに2掛け、その数値の配列に0を入れていく(つまり素数ではない数値を0にする)
            for(i = 2 * m; i < n + 1; i += m) {
                data[i] = 0;
            }
            // 配列primesに素数mを格納する
            primes[count] = m;
            count ++;

            // 1が格納されている配列を探す(次の素数候補)
            do {
                m++;
            } while(data[m] == 0 && m < n + 1);
        
        // mが入力数値を超えるまで続ける
        } while(m < n + 1);
    }
    return 0;
}

// 素数から入力数値の因数を取得する関数
int primeFactoring(int n, int *primes, int *factors) {

    /*
    数字nを素数(primes)で割れるだけ割っていき、割った数字を配列に入れる
    割れなくなったら次の素数(primes[i + 1])を使って割っていく
    最終的に残った数字と素数が同じならその数値を配列に入れて終了
    */
    
    // forループ用変数
    int i;

    // 因数格納に使う変数
    int j = 0;

    // 入力数値回数分ループさせる
    for(i = 0; i <= n; i++) {
        // 残った数値と素数が同じ時、その素数を配列に入れて処理を終了させる
        if(n == primes[i]) {
            factors[j] = primes[i];
            break;
        }
        // 入力数値が素数で0になるまで続ける
        while(n % primes[i] == 0) {
            // 割った素数を格納する
            factors[j] = primes[i];
            // 次の格納場所へインクリメント
            j++;
            // 次の計算のために数値を割っておく
            n /= primes[i];
        }
    }
    return 0;
}

// 因数の配列を受け取って結果を出力する関数
int printFactors(int n, int *factors) {

    // 結果の出力
    printf("%d->\n", n);
    
    // 格納された因数をループで表示していく
    for(int i = 0; i < 100; i++) {

        // 入力数字が配列の一番最初と等しい時、表示して終了
        if(n == factors[0]) {
            printf("%d\n", factors[0]);
            break;
        }

        /*
        格納されている「次の」数字が入力数値より大きいか、0、マイナスのいずれかの場合、
        「その前の」数字を表示してループ終了
        */
        if(factors[i + 1] < 0 || n < factors[i + 1] || factors[i + 1] == 0) {
            printf("%d\n", factors[i]);
            break;
        }

        // 因数表示
        printf("%d * ", factors[i]);

        // 配列の添字が5の倍数なら改行する
        if ((i + 1) % 5 == 0){
            printf("\n");
        }
    }

    return 0;
}