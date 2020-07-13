#include <stdio.h>
#include <time.h>


// 定数宣言
#define  COUNT  100000         		// データ数を指定
#define  INFILE    "08sort.txt"		// 入力ファイルを指定
#define  SORTFILE  "out.txt"   		// 出力ファイルを指定


// プロトタイプ宣言
void sort_main(int *);
void getFile(int *);
void outFile(int *);
double getFuncTime(clock_t, clock_t);


// ソート（並び替え）メイン関数
void sort_main(int array[]){
  int i, j, tmp;

  for(i=1; i<COUNT; i++) {
    tmp = array[i];
    for (j=i; array[j-1] > tmp; j--) {
      array[j] = array[j-1];
    }
    array[j] = tmp;
  }
}


// プログラムのメイン関数
int main(){
    // 変数宣言
    clock_t start,end;      // 開始＆終了時間を格納
    int data[COUNT];        // ファイル内のデータを格納

    // ファイルからデータの読み込み
    getFile(data);

    // 処理開始時間の設定
    start = clock();

    // ソート関数の呼出し
    sort_main(data);

    // 処理終了時間の設定
    end = clock();

    /// 処理にかかった時間の出力
    printf("--- Sort Time is  %.2f sec. ---\n", getFuncTime(start, end));

    // 配列に保存されたデータの格納
    outFile(data);
}


void getFile(int *cur){
    FILE *fp;

    fp = fopen(INFILE, "r");
    while(fscanf(fp,"%d", cur) != EOF){
        cur++;
    }

    fclose(fp);
}

void outFile(int *cur){
    FILE *fp;
    int i;

    fp = fopen(SORTFILE, "w");

    for(i=0; i<COUNT; i++){
        fprintf(fp, "%d\n", *(cur+i));
    }

    fclose(fp);
}


double getFuncTime(clock_t start, clock_t end){
    return (double)(end-start)/CLOCKS_PER_SEC;
}
