#pragma once
#include"stdafx.h"

namespace FST
{
	struct RELATION
	{
		char simbl;//������ ��������
		short node;//����� �������

		RELATION(
			char c = 0x00,	//������
			short ns = NULL	//���������
		);
	};

	struct NODE
	{
		short n_rel;//���������� �����
		RELATION* relation;//�����
		NODE();
		NODE(short n, RELATION rel, ...);
	};
	struct FST
	{
		char* chane;//�������
		short position;//�������
		short n_stat;//���������� ���������
		NODE* nodes;//���� ���������
		short* rstates;//��������� ��������
		FST(
			char* ch,//�������
			short ns,//��������� ���������
			NODE n, ...//������ ���������
		);
	};

	bool step(FST& fst, short*& rstat);//���� ���
	bool execute(FST fst);
}