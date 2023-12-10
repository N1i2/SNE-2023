#include"stdafx.h"
#include<time.h>
#pragma warning(disable:4996) //предпреждения об устаревших функциях

namespace Log
{
	LOG getlog(wchar_t logfile[])
	{
		LOG log;
		log.stream = new std::ofstream;
		log.stream->open(logfile);
		if (log.stream->fail())
			throw ERROR_THROW(112);

		wcscpy_s(log.logfile, logfile);
		return log;
	}

	void WriteLine(LOG log, const  char* c, ...)
	{
		const char** p = &c;
		for (int i = 0; p[i] != ""; i++)
		{
			*log.stream << *p;
			p++;
		}
		*log.stream << std::endl;
	}

	void WriteLine(LOG log, const wchar_t* c, ...)
	{
		const wchar_t** wp = &c;
		char cArr[100];

		for (int i = 0; wp[i]!=L""; i++)
		{
			wcstombs(cArr, wp[i], sizeof(cArr));
			*log.stream << cArr;
		}
		*log.stream << std::endl;
	}

	void WriteLog(LOG log)
	{
		std::time_t rowTime;
		tm* timeInfo;
		time(&rowTime);
		timeInfo = localtime(&rowTime);		//функция преобразовывает текущее значение времени, передаваемое 
											//как аргумент, через указатель timeptr на time_t в структуру tm
		char temp[100];
		strftime(temp, sizeof(temp), "\n========ПРОТОКОЛ========\n ===%d.%m.%y %T===\n ", timeInfo);
		*log.stream << temp;
	}

	void WriteParm(LOG log, Parm::PARM parm)
	{
		char in_text[PARM_MAX_SIZE], 
			out_text[PARM_MAX_SIZE],
			log_text[PARM_MAX_SIZE];
		wcstombs(in_text, parm.in, PARM_MAX_SIZE);
		wcstombs(out_text, parm.out, PARM_MAX_SIZE);
		wcstombs(log_text, parm.log, PARM_MAX_SIZE);
		*log.stream << "\n ==== Параметры ==== \n\n-in: " << in_text
			<< "\n-out: " << out_text
			<< "\n-log: " << log_text << std::endl;
	}

	void WriteIn(LOG log, In::IN in)
	{
		*log.stream << "\n---- Исходные данные ----\n"
			<< "\nВсего символов: " << in.size
			<< "\nВсего строк: " << in.line
			<< "\nПропущено: " << in.ignor << std::endl;
	}

	void WriteError(LOG log, Error::ERROR error) 
	{
		if (log.stream)
		{
			*log.stream << "\nОшибка " << error.id
				<< ": " << error.message
				<< "\nСтрока " << error.inext.line
				<< " символ " << error.inext.col << std::endl;
			return;
		}
		*log.stream << "\nОшибка " << error.id
			<< ": " << error.message
			<< "\nСтрока " << error.inext.line
			<< " символ " << error.inext.col << std::endl;
	}

	void Close(LOG log)
	{
		log.stream->close();
		delete log.stream;
	}
}