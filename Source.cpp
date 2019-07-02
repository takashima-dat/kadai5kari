#include<stdio.h>

void main()
{
	const int datas = 10;//データの数
	int data[datas];
	int sw, no, ken, yn;
	int cou = 0;

	for (int i = 0; i < datas; i++)
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
			while (data[no] != 0 && no != datas)
			{
				no++;
			}
			if (no == datas)
			{
				printf_s("これ以上データを登録できません\n");
			}
			else
			{
				printf_s("登録したい整数値を入力:");
				scanf_s("%d", &data[no]);
				printf_s("data%dに登録しました\n", no);
			}
			printf_s("\n操作　0:データ登録　1:検索(削除)　2:データ一覧　3:データリセット　4:終了\n");
			scanf_s("%d", &sw);
			break;
		case 1://検索(削除)
			printf_s("検索したいデータを入力:");
			scanf_s("%d", &ken);
			for (int i = 0; i < datas; i++)
			{
				if (ken == data[i])
				{
					printf_s("data%d=%d\n", i, data[i]);
					printf_s("データが見つかりました。削除しますか？(yes:1 no:0)\n");
					scanf_s("%d", &yn);
					switch (yn)
					{
					case 1:
						data[i] = NULL;
						printf_s("削除しました\n");
						break;
					case 0:
						printf_s("キャンセルします\n");
						break;
					default:
						printf_s("入力が正しくありません。キャンセルします\n");
						break;
					}
				}
				else
				{
					cou++;
				}
				if (cou == datas)
				{
					printf_s("データが見つかりませんでした\n");
				}
			}
			cou = 0;
			printf_s("\n操作　0:データ登録　1:検索(削除)　2:データ一覧　3:データリセット　4:終了\n");
			scanf_s("%d", &sw);
			break;
		case 2://データ一覧
			for (int i = 0; i < datas; i++)
			{
				if (data[i] == 0)
				{
					cou++;
				}
				else
				{
					printf_s("data%d=%d\n", i, data[i]);
				}
			}
			if (cou == datas)
			{
				printf_s("データがありません\n");
			}
			cou = 0;
			printf_s("\n操作　0:データ登録　1:検索(削除)　2:データ一覧　3:データリセット　4:終了\n");
			scanf_s("%d", &sw);
			break;
		case 3://データリセット
			printf_s("本当にリセットしますか？(yes:1 no:0)\n");
			scanf_s("%d", &yn);
			switch (yn)
			{
			case 1:
				for (int i = 0; i < datas; i++)
				{
					data[i] = NULL;
				}
				printf_s("リセットしました\n");
				break;
			case 0:
				printf_s("キャンセルします\n");
				break;
			default:
				printf_s("入力が正しくありません。キャンセルします\n");
				break;
			}
			printf_s("\n操作　0:データ登録　1:検索(削除)　2:データ一覧　3:データリセット　4:終了\n");
			scanf_s("%d", &sw);
			break;
		case 4://終了
			break;
		default:
			printf_s("入力が正しくありません\n");
			printf_s("\n操作　0:データ登録　1:検索(削除)　2:データ一覧　3:データリセット　4:終了\n");
			scanf_s("%d", &sw);
			break;
		}
	}
	printf_s("終了します\n");
}