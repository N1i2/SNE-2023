#include"stdafx.h"

namespace Out
{
	OUT getout(wchar_t outFile[])
	{
		OUT out;
		out.stream = new std::ofstream;
		out.stream->open(outFile);
		if (out.stream->fail())
			throw ERROR_THROW(113);
		return out;
	}

	void WriteIn(OUT out, In::IN in)
	{
		for (int i = 0; i < in.size; i++)
		{
			if (i != 0 && in.text[i-1] == IN_CODE_END && in.text[i] == IN_CODE_END)
				continue;

			if (in.text[i] == IN_CODE_END)
				*out.stream << IN_CODE_ENDL;
			else
				*out.stream << in.text[i];
		}
	}

	void Cloce(OUT out)
	{
		out.stream->close();
		delete out.stream;
	}
}