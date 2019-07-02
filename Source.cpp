#include<stdio.h>

void main()
{
	const int datas = 10;//データの数
	int data[datas];//データ
	int sw;//操作　0:データ登録　1:検索(削除)　2:データ一覧　3:データリセット　4:終了
	int no;//dataの番号
	int ken;//検索する数値
	int yn;//yesかno
	int cou = 0;//データを数えるのに使う

	for (int i = 0; i < datas; i++)//念のためNULLを入れとく
	{
		data[i] = NULL;
	}

	printf_s("0以外の整数データを%d個まで管理\n", datas);
	printf_s("操作　0:データ登録　1:検索(削除)　2:データ一覧　3:データリセット　4:終了\n");
	scanf_s("%d", &sw);
	while (sw != 4)
	{
		switch (sw)
		{
		case 0://データ登録
			no = 0;
			while (data[no] != 0 && no != datas)//中身が0のdataを探す(削除で穴あきが出るので)
			{
				no++;
			}
			if (no == datas)//全部0じゃないとき
			{
				printf_s("これ以上データを登録できません\n");
			}
			else
			{
				printf_s("登録したい整数値を入力:");
				scanf_s("%d", &data[no]);
				printf_s("data%dに登録しました\n", no);
			}
			break;
		case 1://検索(削除)
			printf_s("検索したいデータを入力:");
			scanf_s("%d", &ken);
			for (int i = 0; i < datas; i++)//全部から一個ずつ探す
			{
				if (ken == data[i])//検索に一致したとき
				{
					printf_s("data%d=%d\n", i, data[i]);
					printf_s("データが見つかりました。削除しますか？(yes:1 no:0)\n");
					scanf_s("%d", &yn);
					switch (yn)
					{
					case 1://yes
						data[i] = NULL;
						printf_s("削除しました\n");
						break;
					case 0://no
						printf_s("キャンセルします\n");
						break;
					default:
						printf_s("入力が正しくありません。キャンセルします\n");
						break;
					}
				}
				else//一致しなかったとき
				{
					cou++;
				}
				if (cou == datas)//一個も一致するものがなかったとき
				{
					printf_s("データが見つかりませんでした\n");
				}
			}
			break;
		case 2://データ一覧
			for (int i = 0; i < datas; i++)
			{
				if (data[i] == 0)//データがないデータの数を数える
				{
					cou++;
				}
				else//データが入ってれば表示
				{
					printf_s("data%d=%d\n", i, data[i]);
				}
			}
			if (cou == datas)//全部データがないとき
			{
				printf_s("データがありません\n");
			}
			break;
		case 3://データリセット
			printf_s("本当にリセットしますか？(yes:1 no:0)\n");
			scanf_s("%d", &yn);
			switch (yn)
			{
			case 1://yes
				for (int i = 0; i < datas; i++)
				{
					data[i] = NULL;
				}
				printf_s("リセットしました\n");
				break;
			case 0://no
				printf_s("キャンセルします\n");
				break;
			default:
				printf_s("入力が正しくありません。キャンセルします\n");
				break;
			}
			break;
		case 4://終了
			break;
		default:
			printf_s("入力が正しくありません\n");
			break;
		}
		cou = 0;
		printf_s("\n操作　0:データ登録　1:検索(削除)　2:データ一覧　3:データリセット　4:終了\n");
		scanf_s("%d", &sw);
	}
	printf_s("終了します\n");
}