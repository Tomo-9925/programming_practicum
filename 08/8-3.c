#include <stdio.h>
#include <time.h>


// 定数宣言
#define  COUNT  100000         		// データ数を指定
#define  INFILE    "08sort.txt"		// 入力ファイルを指定
#define  SORTFILE  "out.txt"   		// 出力ファイルを指定


// プロトタイプ宣言
void sort_main(int *array, int first, int last);
void getFile(int *);
void outFile(int *);
double getFuncTime(clock_t, clock_t);


// ソート（並び替え）メイン関数
void sort_main(int *array, int first, int last){
  int left = first;
  int right = last;
  int pivot = *(array+last);
  int tmp;

  while(1) {
    while(*(array+left) > pivot) ++left;
    while(*(array+right) < pivot) --right;
    if(left < right) {
      tmp = *(array+left);
      *(array+left) = *(array+right);
      *(array+right) = tmp;

      ++left;
      --right;
    }
    else break;
  }
  if(first < left-1) sort_main(array, first, left-1);
  if(right+1 < last) sort_main(array, right+1, last);
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
    sort_main(data, 0, COUNT-1);

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
