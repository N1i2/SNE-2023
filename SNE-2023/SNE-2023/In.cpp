#include"stdafx.h"

namespace In
{
	static helpInfo info;

	helpInfo getInfo() 
	{
		return info;
	}

	IN getin(Parm::PARM parm)
	{
		IN in;
		unsigned char leter;
		int item=0, position=0;
		bool strLeter = false, strCommit = false;

		in.size = 0;
		in.line = 1;
		in.ignor = 0;
		in.text = new char[IN_MAX_LEN_TXT];

		int line = 0;
		int simvl = 0;
		
		char* text = new char[IN_MAX_LEN_TXT];

		std::ifstream file(parm.in);
		if (file.fail())
		{
			std::cout << Error::geterror(102).message;
			throw ERROR_THROW(102);
		}

		while (in.size<IN_MAX_LEN_TXT)
		{
			leter = file.get();

			if (file.eof())break;

			if (leter == IN_CODE_ENDL)
				strCommit = false;

			if (strCommit)
				continue;
			
			if (leter == '\'' || leter == '\"')
				strLeter = !strLeter;

			switch (in.code[(int)leter])
			{
			case in.T:
				if (item != 0)
				{
					if (leter == IN_PROBEL && in.text[item - 1] == IN_PROBEL ||
						leter == IN_CODE_ENDL && in.text[item - 1] == IN_CODE_ENDL)
						continue;
				}
				in.text[item++] = leter;
				in.size++;
				position++;
				break;
			case in.F:
				throw ERROR_THROW_IN(200, in.line, position);
				break;
			case in.I:
				in.ignor++;
				position++;
				break;
			default:
				in.text[item++] = in.code[(int)leter];
				in.size++;
				position++;
				break;
			}
		}

		file.close();
		in.text[item] = '\0';

		info.fulltext += in.text;
		info.currentLine = in.size;

		return in;
	}
}