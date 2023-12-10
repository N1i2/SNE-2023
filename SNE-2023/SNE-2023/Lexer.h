#pragma once
#include"stdafx.h"
#include"IT.h"
#include"LT.h"

namespace Lexer
{
	struct Tables
	{
		LT::LexTable lextable;
		IT::IdTable idtable;
	};

	Tables lexAnalis(int currentLine, char* fulltext);
}