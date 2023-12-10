#pragma once
#include"stdafx.h"

namespace FST
{
	struct RELATION
	{
		char simbl;//символ перехода
		short node;//номер вершины

		RELATION(
			char c = 0x00,	//символ
			short ns = NULL	//состояние
		);
	};

	struct NODE
	{
		short n_rel;//количество ребер
		RELATION* relation;//ребра
		NODE();
		NODE(short n, RELATION rel, ...);
	};
	struct FST
	{
		char* chane;//цепочка
		short position;//позиция
		short n_stat;//количество состояний
		NODE* nodes;//граф переходов
		short* rstates;//состояние автомата
		FST(
			char* ch,//цепочка
			short ns,//коичество состаяний
			NODE n, ...//список состояний
		);
	};

	bool step(FST& fst, short*& rstat);//один шаг
	bool execute(FST fst);
}