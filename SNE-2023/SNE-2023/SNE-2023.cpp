#include"stdafx.h"

int wmain(int argc, wchar_t* argv[])
{
	setlocale(LC_ALL, "ru");

	Log::LOG log = Log::INFLOG;
	Out::OUT out=Out::INFOUT;
	try
	{
		//&&&&&&&&&&&&&&&&&&&&&&&&& ПРЕПРОЦЕССОР &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		out = Out::getout(parm.out);

		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm);
		Log::WriteIn(log, in);
		Out::WriteIn(out, in);
		
		//&&&&&&&&&&&&&&&&&&&&&&&&& ЛЕКСЕР &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

		Lexer::Tables myTables = Lexer::lexAnalis(In::getInfo().currentLine, (char*)In::getInfo().fulltext.c_str());


		//&&&&&&&&&&&&&&&&&&&&&&&&& СИНТАКСИЧЕСКИЙ АНАЛИЗ &&&&&&&&&&&&&&&&&&&&&&&&


		//&&&&&&&&&&&&&&&&&&&&&&&&& СИМАНТИЧЕСКИЙ АНАЛИЗ &&&&&&&&&&&&&&&&&&&&&&&&&


		//&&&&&&&&&&&&&&&&&&&&&&&&& КОНЕЦ &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
		Log::Close(log);
		Out::Cloce(out);

		std::cout << "Все хорошо\n";
	}
	catch (Error::ERROR e)
	{
		std::cout << e.message;
		Log::WriteError(log, e);
		return -1;
	}
	return 0;
};