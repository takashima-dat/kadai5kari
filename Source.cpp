#include<stdio.h>

void main()
{
	const int datas = 10;//�f�[�^�̐�
	int data[datas];
	int sw, no, ken, yn;
	int cou = 0;

	for (int i = 0; i < datas; i++)
	{
		data[i] = NULL;
	}

	printf_s("0�ȊO�̐����f�[�^��%d�܂ŊǗ�\n", datas);
	printf_s("����@0:�f�[�^�o�^�@1:����(�폜)�@2:�f�[�^�ꗗ�@3:�f�[�^���Z�b�g�@4:�I��\n");
	scanf_s("%d", &sw);
	while (sw != 4)
	{
		switch (sw)
		{
		case 0://�f�[�^�o�^
			no = 0;
			while (data[no] != 0 && no != datas)
			{
				no++;
			}
			if (no == datas)
			{
				printf_s("����ȏ�f�[�^��o�^�ł��܂���\n");
			}
			else
			{
				printf_s("�o�^�����������l�����:");
				scanf_s("%d", &data[no]);
				printf_s("data%d�ɓo�^���܂���\n", no);
			}
			printf_s("\n����@0:�f�[�^�o�^�@1:����(�폜)�@2:�f�[�^�ꗗ�@3:�f�[�^���Z�b�g�@4:�I��\n");
			scanf_s("%d", &sw);
			break;
		case 1://����(�폜)
			printf_s("�����������f�[�^�����:");
			scanf_s("%d", &ken);
			for (int i = 0; i < datas; i++)
			{
				if (ken == data[i])
				{
					printf_s("data%d=%d\n", i, data[i]);
					printf_s("�f�[�^��������܂����B�폜���܂����H(yes:1 no:0)\n");
					scanf_s("%d", &yn);
					switch (yn)
					{
					case 1:
						data[i] = NULL;
						printf_s("�폜���܂���\n");
						break;
					case 0:
						printf_s("�L�����Z�����܂�\n");
						break;
					default:
						printf_s("���͂�����������܂���B�L�����Z�����܂�\n");
						break;
					}
				}
				else
				{
					cou++;
				}
				if (cou == datas)
				{
					printf_s("�f�[�^��������܂���ł���\n");
				}
			}
			cou = 0;
			printf_s("\n����@0:�f�[�^�o�^�@1:����(�폜)�@2:�f�[�^�ꗗ�@3:�f�[�^���Z�b�g�@4:�I��\n");
			scanf_s("%d", &sw);
			break;
		case 2://�f�[�^�ꗗ
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
				printf_s("�f�[�^������܂���\n");
			}
			cou = 0;
			printf_s("\n����@0:�f�[�^�o�^�@1:����(�폜)�@2:�f�[�^�ꗗ�@3:�f�[�^���Z�b�g�@4:�I��\n");
			scanf_s("%d", &sw);
			break;
		case 3://�f�[�^���Z�b�g
			printf_s("�{���Ƀ��Z�b�g���܂����H(yes:1 no:0)\n");
			scanf_s("%d", &yn);
			switch (yn)
			{
			case 1:
				for (int i = 0; i < datas; i++)
				{
					data[i] = NULL;
				}
				printf_s("���Z�b�g���܂���\n");
				break;
			case 0:
				printf_s("�L�����Z�����܂�\n");
				break;
			default:
				printf_s("���͂�����������܂���B�L�����Z�����܂�\n");
				break;
			}
			printf_s("\n����@0:�f�[�^�o�^�@1:����(�폜)�@2:�f�[�^�ꗗ�@3:�f�[�^���Z�b�g�@4:�I��\n");
			scanf_s("%d", &sw);
			break;
		case 4://�I��
			break;
		default:
			printf_s("���͂�����������܂���\n");
			printf_s("\n����@0:�f�[�^�o�^�@1:����(�폜)�@2:�f�[�^�ꗗ�@3:�f�[�^���Z�b�g�@4:�I��\n");
			scanf_s("%d", &sw);
			break;
		}
	}
	printf_s("�I�����܂�\n");
}