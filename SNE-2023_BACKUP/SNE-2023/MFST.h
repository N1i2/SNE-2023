#pragma once
#include <stack>
#include <iomanip>
#include "Greibach.h"
#include "LexAnaliz.h"

#define MFST_DIAGN_MAXSIZE 2*ERROR_MAXSIZE_MESSAGE
#define MFST_DIAGN_NUMBER 3
#define MFST_TRACE_START	filetrace << std::setw(4) << std::left << "Шаг" << ": " \
									  << std::setw(20) << std::left << "Правило" \
									  << std::setw(30) << std::left << "Входная лента" \
									  << std::setw(20) << std::left << "Стек" \
									  << std::endl;

#define MFST_TRACE1		filetrace << std::setw(4) << std::left << ++FST_TRACE_n << ": " \
								  << std::setw(20) << std::left << rule.getCRule(rbuf, nrulechain) \
								  << std::setw(30) << std::left << getCLenta(lbuf, lenta_position) \
								  << std::setw(20) << std::left << getCSt(sbuf) \
								  << std::endl;

#define MFST_TRACE2		filetrace << std::setw(4) << std::left << FST_TRACE_n<<": " \
								  << std::setw(20) << std::left << " " \
								  << std::setw(30) << std::left << getCLenta(lbuf, lenta_position) \
								  << std::setw(20) << std::left << getCSt(sbuf) \
								  << std::endl;

#define MFST_TRACE3		filetrace << std::setw(4) << std::left << ++FST_TRACE_n <<": " \
								  << std::setw(20) << std::left << " " \
								  << std::setw(30) << std::left << getCLenta(lbuf, lenta_position) \
								  << std::setw(20) << std::left << getCSt(sbuf) \
								  << std::endl;

#define MFST_TRACE4(c)	filetrace << std::setw(4) << std::left << ++FST_TRACE_n << ": " << std::setw(20) << std::left << c <<std::endl; 
#define MFST_TRACE5(c)	filetrace << std::setw(4) << std::left << FST_TRACE_n << ": " << std::setw(20) << std::left << c << std::endl; 
#define MFST_TRACE6(c, k)	filetrace << std::setw(4) << std::left << FST_TRACE_n << ": " << std::setw(20) << std::left << c << k << std::endl; 
#define MFST_TRACE7		*log.stream << std::setw(4) << std::left << state.lenta_position << ": " \
								  << std::setw(20) << std::left << rule.getCRule(rbuf, state.nrulechain) \
								  << std::endl;

typedef std::stack<short> MFSTSTACK;

namespace MFST
{
	struct MfstState
	{
		short lenta_position;
		short nrule;
		short nrulechain;
		MFSTSTACK st;
		MfstState();
		MfstState(short pposition, MFSTSTACK pst, short pnrulechain);
		MfstState(short pposition, MFSTSTACK pst, short pnrule, short pnrulechain);
	};

	struct Mfst
	{
		enum RC_STEP {
			NS_OK,
			NS_NORULE,
			NS_NORULECHAIN,
			NS_ERROR,
			TS_OK,
			TS_NOK,
			LENTA_END,
			SURPRISE
		};

		struct MfstDiagnosis
		{
			short lenta_position;
			RC_STEP rc_step;
			short nrule;
			short nrule_chain;
			MfstDiagnosis();
			MfstDiagnosis(short plenta_position, RC_STEP prt_step, short pnrule, short pnrule_chain);
		} diagnosis[MFST_DIAGN_NUMBER];

		GRBALPHABET* lenta;
		short lenta_position;
		short nrule;
		short nrulechain;
		short lenta_size;
		GRB::Greibach grebach;
		LexA::Tables lex;
		MFSTSTACK st;
		std::stack<MfstState> storestate;
		Mfst();
		Mfst(LexA::Tables plex, GRB::Greibach pgrebach);
		char* getCSt(char* buf);
		char* getCLenta(char* buf, short pos, short n = 25);
		char* getDiagnosis(short n, char* buf);
		bool savestate(std::ofstream& log);
		bool reststate(std::ofstream& log);
		bool push_chain(GRB::Rule::Chain chain);
		RC_STEP step(std::ofstream& log);
		bool start(std::ofstream& log);
		bool savediagnosis(RC_STEP pprc_step);
		void printrules(Log::LOG log);

		struct Deducation
		{
			short size;
			short* nrules;
			short* nrulechains;
			Deducation()
			{
				size = 0;
				nrules = 0;
				nrulechains = 0;
			};
		} deducation;

		bool savededucation();
	};
}