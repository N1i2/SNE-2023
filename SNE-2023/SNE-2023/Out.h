#pragma once
#include"stdafx.h"

namespace Out
{
	struct OUT
	{
		wchar_t logfile[PARM_MAX_SIZE];
		std::ofstream* stream;
	};

	static const OUT INFOUT = { L"", NULL };
	OUT getout(wchar_t outFile[]);
	void WriteIn(OUT out, In::IN in);
	void Cloce(OUT out);
}