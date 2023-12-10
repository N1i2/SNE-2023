#include"stdafx.h"


namespace Lexer
{
	Tables lexAnalis(int currentLine, char* fulltext)
	{
		std::string text = fulltext;
		std::string lexem[300];
		int countLex{ 0 };
		int* LexLine = new int[currentLine];
		currentLine = 0;
		int LexIT;
		int litSize{ 0 };

		bool isLiteral{ false };

		for (int i = 0; i < text.size(); i++)
		{
			switch (text[i])
			{
			case '-':
				if (!isLiteral && lexem != 0 && (lexem[countLex - 1] == "=" || lexem[countLex - 1] == "("))
				{
					lexem[countLex] = text[i];
					break;
				}
			case ';':
			case ',':
			case '(':
			case ')':
			case '+':
			case '%':
			case '*':
			case '/':
			case '=':
				if (!isLiteral)
				{
					if (lexem[countLex] != "")
						countLex++;
					lexem[countLex] += text[i];
				}
			case '\n':
				if (!isLiteral)
				{
					if (text[i] == '\n')
					{
						if (lexem[countLex] != "")
							countLex++;

						lexem[countLex] = "\n";
					}
					LexLine[currentLine++] = countLex;
				}
			case ' ':
			case '\t':
				if (!isLiteral)
				{
					if (lexem[countLex] != "")
						countLex++;
				}
				else
				{
					litSize++;
					if (++litSize > 255)
						throw ERROR_THROW_IN(118, currentLine, 0);

					lexem[countLex] += text[i];
				}
				break;
			case '\'':
			case '\"':
				isLiteral = -isLiteral;
				litSize = 0;
			default:
				lexem[countLex] += text[i];
				break;
			}
		}

		Tables tabl;
		tabl.idtable = IT::Create(countLex);
		tabl.lextable = LT::Create(countLex);

		bool endFunc{ true };
		bool thereMain{ false };
		bool thereMainD{ false };
		bool endParam{ true };
		bool endIf{ true };
		bool endElse{ true };
		unsigned char bofer{};
		std::string lexString[300];
		char** words = new char* [countLex];
		for (int i = 0; i < countLex; i++)
		{
			words[i] = new char[lexem[i].length() + 1];
			std::strcpy(words[i], lexem[i].c_str());
		}
		currentLine = 0;

		IT::Entry entryIT;
		LT::Entry entryLT;

		for (int i = 0; i < countLex; i++)
		{
			switch (lexem[i][0])
			{
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
				entryLT.lexema = LEX_OPERATOR;
				bofer = entryLT.lexema;
				entryLT.strNumb = currentLine;
				entryLT.indxTI = LT_IT_NULLIDX;

				LT::Add(tabl.lextable, entryLT);

				break;
			case 'n':
				if (FST::execute(FST::FST(words[i], FST_SHORT)))
				{
					entryLT.lexema = LEX_NUMB;
					entryLT.strNumb = currentLine;
					entryLT.indxTI = LT_IT_NULLIDX;
					bofer = entryLT.lexema;

					LT::Add(tabl.lextable, entryLT);
				}
				break;
			case 't':
				if (FST::execute(FST::FST(words[i], FST_STRING)))
				{
					entryLT.lexema = LEX_TEXT;
					entryLT.strNumb = currentLine;
					entryLT.indxTI = LT_IT_NULLIDX;
					bofer = entryLT.lexema;

					LT::Add(tabl.lextable, entryLT);
				}
				else if (FST::execute(FST::FST(words[i], FST_TONUMB)))
				{
					entryLT.lexema = LEX_TEXTNUMB;
					entryLT.strNumb = currentLine;
					entryLT.indxTI = LT_IT_NULLIDX;
					bofer = entryLT.lexema;

					LT::Add(tabl.lextable, entryLT);
				}
				break;
			case 'v':
				if (FST::execute(FST::FST(words[i], FST_VOID)))
				{
					entryLT.lexema = LEX_VOID;
					entryLT.strNumb = currentLine;
					entryLT.indxTI = LT_IT_NULLIDX;
					bofer = entryLT.lexema;

					LT::Add(tabl.lextable, entryLT);
				}
				break;
			case 'V':
				if (FST::execute(FST::FST(words[i], FST_VOID)))
				{
					entryLT.lexema = LEX_VIVOD;
					entryLT.strNumb = currentLine;
					entryLT.indxTI = LT_IT_NULLIDX;
					bofer = entryLT.lexema;

					LT::Add(tabl.lextable, entryLT);
				}
				break;
			case 'F':
				if (FST::execute(FST::FST(words[i], FST_FUNC)))
				{
					if (!endFunc)
					{
						throw ERROR_THROW_IN(205, currentLine, 0);
					}
					endFunc = false;
					entryLT.lexema = LEX_FUNCTION;
					entryLT.strNumb = currentLine;
					entryLT.indxTI = LT_IT_NULLIDX;
					bofer = entryLT.lexema;

					LT::Add(tabl.lextable, entryLT);
				}
				else if (FST::execute(FST::FST(words[i], FST_FUNCEND)))
				{
					if (endFunc)
					{
						throw ERROR_THROW_IN(205, currentLine, 0);
					}
					endFunc = true;
					entryLT.lexema = LEX_RFIGUR;
					entryLT.strNumb = currentLine;
					entryLT.indxTI = LT_IT_NULLIDX;
					bofer = entryLT.lexema;

					LT::Add(tabl.lextable, entryLT);
				}
				break;
			case 'r':
				if (FST::execute(FST::FST(words[i], FST_RETURN)))
				{
					if (endFunc)
					{
						throw ERROR_THROW_IN(205, currentLine, 0);
					}
					entryLT.lexema = LEX_RETURN;
					entryLT.strNumb = currentLine;
					entryLT.indxTI = LT_IT_NULLIDX;
					bofer = entryLT.lexema;

					LT::Add(tabl.lextable, entryLT);
				}
				break;
			case 'M':
				if (FST::execute(FST::FST(words[i], FST_MAIN)))
				{
					if (thereMain)
					{
						throw ERROR_THROW_IN(205, currentLine, 0);
					}

					thereMain = true;
					entryLT.lexema = LEX_MAIN;
					entryLT.strNumb = currentLine;
					entryLT.indxTI = LT_IT_NULLIDX;
					bofer = entryLT.lexema;

					LT::Add(tabl.lextable, entryLT);
				}
				else if (FST::execute(FST::FST(words[i], FST_MAINEND)))
				{
					if (thereMainD)
					{
						throw ERROR_THROW_IN(205, currentLine, 0);
					}

					thereMainD = true;
					entryLT.lexema = LEX_RFIGUR;
					entryLT.strNumb = currentLine;
					entryLT.indxTI = LT_IT_NULLIDX;
					bofer = entryLT.lexema;

					LT::Add(tabl.lextable, entryLT);
				}
				break;
			case 'e':
				if (FST::execute(FST::FST(words[i], FST_IF)))
				{
					if (!endIf)
					{
						throw ERROR_THROW_IN(205, currentLine, 0);
					}
					endIf = false;

					entryLT.lexema = LEX_IF;
					entryLT.strNumb = currentLine;
					entryLT.indxTI = LT_IT_NULLIDX;
					bofer = entryLT.lexema;

					LT::Add(tabl.lextable, entryLT);
				}
				else if (FST::execute(FST::FST(words[i], FST_IFEND)))
				{
					if (endIf)
					{
						throw ERROR_THROW_IN(205, currentLine, 0);
					}
					endIf = true;

					entryLT.lexema = LEX_RFIGUR;
					entryLT.strNumb = currentLine;
					entryLT.indxTI = LT_IT_NULLIDX;
					bofer = entryLT.lexema;

					LT::Add(tabl.lextable, entryLT);
				}
				break;
			case 'i':
				if (FST::execute(FST::FST(words[i], FST_ELSE)))
				{
					if (endIf)
					{
						throw ERROR_THROW_IN(205, currentLine, 0);
					}
					endElse = false;

					entryLT.lexema = LEX_ELSE;
					entryLT.strNumb = currentLine;
					entryLT.indxTI = LT_IT_NULLIDX;
					bofer = entryLT.lexema;

					LT::Add(tabl.lextable, entryLT);
				}
				else if (FST::execute(FST::FST(words[i], FST_ELSEEND)))
				{
					if (endElse)
					{
						throw ERROR_THROW_IN(205, currentLine, 0);
					}
					endElse = true;

					entryLT.lexema = LEX_RFIGUR;
					entryLT.strNumb = currentLine;
					entryLT.indxTI = LT_IT_NULLIDX;
					bofer = entryLT.lexema;

					LT::Add(tabl.lextable, entryLT);
				}
				break;
			case '(':
				if (!endParam)
				{
					throw ERROR_THROW_IN(205, currentLine, 0);
				}
				endParam = false;

				entryLT.lexema = LEX_LKRUG;
				entryLT.strNumb = currentLine;
				entryLT.indxTI = LT_IT_NULLIDX;
				bofer = entryLT.lexema;

				LT::Add(tabl.lextable, entryLT);
				break;
			case ')':
				if (endParam)
				{
					throw ERROR_THROW_IN(205, currentLine, 0);
				}
				endParam = true;

				entryLT.lexema = LEX_RKRUG;
				entryLT.strNumb = currentLine;
				entryLT.indxTI = LT_IT_NULLIDX;
				bofer = entryLT.lexema;

				LT::Add(tabl.lextable, entryLT);
				break;
			case '=':
				if((!endIf||!endElse)&&(!endParam))
					if (words[i + 1][0] == LEX_PRISVOI)
					{
						entryLT.lexema = LEX_RAVNO;
						i++;
					}
					else
					{
						throw ERROR_THROW_IN(205, currentLine, 0);
					}
				else
					entryLT.lexema = LEX_PRISVOI;
				entryLT.strNumb = currentLine;
				entryLT.indxTI = LT_IT_NULLIDX;
				bofer = entryLT.lexema;

				LT::Add(tabl.lextable, entryLT);
				break;
			case ',':
				entryLT.lexema = LEX_COMMA;
				entryLT.strNumb = currentLine;
				entryLT.indxTI = LT_IT_NULLIDX;
				bofer = entryLT.lexema;

				LT::Add(tabl.lextable, entryLT);
				break;
			case ';':
				entryLT.lexema = LEX_END;
				entryLT.strNumb = currentLine;
				entryLT.indxTI = LT_IT_NULLIDX;
				bofer = entryLT.lexema;

				LT::Add(tabl.lextable, entryLT);
				break;
			case '\n':
				currentLine++;
				break;
			case '\"':
			case '\'':
				entryLT.lexema = LEX_LITER;
				entryLT.strNumb = currentLine;
				entryLT.indxTI = LT_IT_NULLIDX;
				bofer = entryLT.lexema;

				LT::Add(tabl.lextable, entryLT);
				break;
			default:
				if (bofer != 't' && bofer != LEX_PRISVOI
					&& bofer != LEX_OPERATOR&& bofer!=LEX_LKRUG&&
					bofer!=LEX_COMMA && bofer !=LEX_RAVNO)
				{
					throw ERROR_THROW_IN(205, currentLine, 0);
				}


				break;
			}
		}

		std::ofstream fileLT;
		fileLT.open("LT.txt");
		LT::showLT(tabl.lextable, fileLT);
	}
}