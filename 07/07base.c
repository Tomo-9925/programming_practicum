#include <stdio.h>
#include <time.h>

// 定数宣言
#define  COUNT  100000         			// データ数を指定
#define  INFILE    "07search.txt"		// 入力ファイルを指定

// プロトタイプ宣言
int search_main(int *, int);				// ソートメイン関数
void getFile(int *);							// ファイルからデータを読込む関数
double getFuncTime(clock_t, clock_t);	// 指定範囲における経過時間を算出する関数

// サーチ（探索）メイン関数（修正箇所）
int search_main(int *array, int target){
	// サーチ（探索）の処理を本関数で実現すること
	// 処理をまとめたい場合は、別関数を定義すること
	
	// *(array) = 10;					<--   data[0] = 10;　	と同じ
	// *(array + 10) = 100;			<--   data[10] = 100;	と同じ
	
	return 0; 							// データ群の中に存在した探索値targetの数を設定
}

// プログラムのメイン関数
int main(){
	// 変数宣言
	clock_t start,end;      				// 開始＆終了時間を格納
	int data[COUNT];       		 			// ファイル内のデータを格納
	int i, target;

	getFile(data);								// ファイルからデータの読み込み

	printf("探索したい値を入力して下さい\n");
	scanf("%d", &target);

	// 処理①
	printf("データ群の中から探索値[%d]を%d件発見しました\n", target, search_main(data, target));
	
	// 処理②：検索アルゴリズムの計算コスト確認
	/*
	start = clock();							// 処理開始時間の設定

	// 1から9999までの数値を5回ずつ探索した場合の処理時間を比較
	
	for(i=0; i<5; i++){
		for(target=1; target<10000; target++){
			search_main(data, target);			// サーチ関数の呼出し
      }
   }

	end = clock();								// 処理終了時間の設定
	// 処理にかかった時間の出力
	printf("--- Search Time is  %.2f sec. ---\n", getFuncTime(start, end));
	*/
	
	return 0;
}

// ファイルからデータを読込む関数
void getFile(int *cur){
	FILE *fp;

	fp = fopen(INFILE, "r");						// 定数宣言したファイルを読込みモードで開く

	while(fscanf(fp,"%d", cur)!= EOF) cur++;	// ファイル内の数値を読込み

	fclose(fp);											// ファイルを閉じる
}

// 指定範囲における経過時間を算出する関数
double getFuncTime(clock_t start, clock_t end){
	return (double)(end-start)/CLOCKS_PER_SEC;
}
