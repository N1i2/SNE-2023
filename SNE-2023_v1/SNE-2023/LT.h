#pragma once
#define LEXEMA_FIXSIZE	1		
#define LT_MAXSIZE		4096		
#define LT_TI_NULLIDX	0xfffffff	
#define LEX_LITTLE		't'	
#define LEX_TEXT		't'
#define LEX_TYPES		't'
#define LEX_ID			'i'	
#define LEX_LITERAL		'l'	
#define LEX_FUNCTION	'f'	
#define LEX_NEW			'n'	
#define LEX_RETURN		'r'	
#define LEX_OUTPUT		'o'	
#define LEX_START		's'	
#define LEX_FROM		'm'
#define LEX_TO			'e'	
#define LEX_NOT			'j'	
#define LEX_CHECK		'c'
#define LEX_ENDCHECK	'?'	
#define LEX_LIBFUNCTION	'z'	
#define LEX_INCLUDELIB	'w'	
#define LEX_SEMICOLON	';'	
#define LEX_COMMA		','	
#define LEX_LEFTBRACE	'{'
#define LEX_RIGHTBRACE	'}'
#define LEX_LEFTTHESIS	'('	
#define LEX_RIGHTTHESIS	')'	
#define LEX_PLUS		'v'
#define LEX_MINUS		'v'	
#define LEX_STAR		'v'	
#define LEX_DIRSLASH	'v'	
#define LEX_OPERCHECK	'y'	
#define LEX_ENDCONDCYCL	'$'	
#define LEX_OPERATOR	'v'	
#define LEX_EQUAL		'=' 
#define NEWLINE			'\n'
#define POLISHFUNCTION  '@'
#define LATTICE 		'#'
#define SPACE	 		' '

namespace LT
{
	struct Entry
	{
		unsigned char lexema;
		char value;
		int sn;
		int idxTI;
		int index;
		bool used = false;
	};

	struct LexTable
	{
		int maxsize;
		int size;
		Entry* table;
	};

	LexTable Create(int size);

	void Add(LexTable& lextable, Entry entry);

	Entry GetEntry(LexTable& lextable, int n);

	void Delete(LexTable& lextable);

	void showTable(LexTable lextable, std::ofstream& file);
	void showTable_mini(LexTable lextable, std::ofstream& file);
};