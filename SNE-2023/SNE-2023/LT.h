#pragma once
#define LEXEMA_FIXSIZE	1			// ������ �������
#define LT_MAXSIZE		4096		// ������������ ������ �������
#define LT_IT_NULLIDX	0xfffffff	// ���� ������ ���
#define LEX_NUMB		't'			// numb
#define LEX_TEXT		't'			// text
#define LEX_VOID		't'			// void
#define LEX_LITER		'l'			// ��������
#define LEX_IDENTY		'i'			// �������������
#define LEX_FUNCTION	'f'			// Func
#define LEX_RETURN		'r'			// return
#define LEX_VIVOD		'v'			// Vivod
#define LEX_END			';'			// ;
#define LEX_COMMA		','			// ,
#define LEX_RFIGUR		'}'			// FuncD, MainD
#define LEX_LKRUG		'('			// (
#define LEX_RKRUG		')'			// )
#define LEX_PLUS		'v'			// +
#define LEX_MINUS		'v'			// -
#define LEX_MNOG		'v'			// *
#define LEX_DELEN		'v'			// /
#define LEX_ODELEN		'v'			// %
#define LEX_OPERATOR	'v'			// ���������
#define LEX_ALLOPER		'v'			// ��� ���������
#define LEX_PRISVOI		'='			// =
#define LEX_RAVNO		'a'			// ==
#define LEX_NRAVNO		'z'			// !=
#define LEX_NEWLINE		'\n'		// \n
#define LEX_TEXTNUMB	'd'			// toNumber
#define LEX_MAIN		'm'			// main
#define LEX_IF			'e'			// esli
#define LEX_ELSE		'u'			// ili
#define LEX_USHI		'\"'		// (") (')

namespace LT
{
	struct Entry		// ������ ������� ������
	{
		unsigned char lexema;
		char value; 
		int strNumb;
		int indxTI;
		int index;
	};
	struct LexTable		// ������� ������
	{
		int maxSize;
		int size;
		Entry* table;
	};

	LexTable Create(int size);

	void Add(LexTable& lextable, Entry entry);

	Entry GetEntry(LexTable& lextable, int n);

	void Delete(LexTable& lextable);
	void showLT(LexTable& lextable, std::ofstream &file);
}