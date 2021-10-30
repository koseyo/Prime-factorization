// ヘッダーファイル読み込み
#include <stdio.h>
#include <stdlib.h>
#include "primeFactorization.h"

// メイン部分
int main(int argc, char *argv[]) {

    // コマンドライン引数が2でなければ処理を終了
    if(argc != 2) {
        printf("引数の数が正しくありません 入力を整数にしてください\n");
        return 1;
    }

    // 二つ目の引数を数字に変換
    int n = atoi(argv[1]);

    // 入力された数値が0以下、10001以上であれば処理を終了させる
    if(n <= 0 || 10000 < n) {
        printf("1以上、10000以下の整数を入力してください\n");
        return 1;
    }

    // 素数を入れる配列の宣言と関数の実行
    int primes[n + 1];
    getPrime(n, primes);

    // 因数を入れる配列の宣言と関数の実行
    int factors[n + 1];
    primeFactoring(n, primes, factors);

    // 結果を表示する関数の実行
    printFactors(n, factors);

    return 0;
}