#include"stdafx.h"

namespace FST
{
	RELATION::RELATION(char ch, short nn)
	{
		simbl = ch;
		node = nn;
	}
	NODE::NODE()
	{
		n_rel = 0;
		RELATION* relation = NULL;
	}
	NODE::NODE(short n, RELATION rel, ...)
	{
		n_rel = n;
		RELATION* pth = &rel;
		relation = new RELATION[n_rel];
		for (int i = 0; i < n_rel; i++)
			relation[i] = pth[i];
	}
	FST::FST(char* ch, short ns, NODE n, ...)
	{
		chane = ch;
		n_stat = ns;
		nodes = new NODE[ns];
		NODE* p = &n;
		for (int i = 0; i < ns; i++)
			nodes[i] = p[i];
		rstates = new short[n_stat];
		memset(rstates, 0xff, sizeof(short) * n_stat);
		rstates[0] = 0;
		position = -1;
	}
	bool step(FST& fst, short*& rstat)
	{
		bool rc = false;
		std::swap(rstat, fst.rstates);
		for (short i = 0; i < fst.n_stat; i++)
			if(rstat[i]==fst.position)
				for (short j = 0; j < fst.nodes[i].n_rel; j++)
					if (fst.nodes[i].relation[j].simbl==fst.chane[fst.position])
					{
						fst.rstates[fst.nodes[i].relation[j].node] = fst.position + 1;
						rc = true;
					}

		return rc;
	}
	bool execute(FST fst)
	{
		short lenth = strlen(fst.chane);
		short* rstat = new short[fst.n_stat];
		memset(rstat, 0xff, sizeof(short) * fst.n_stat);
		bool rc = true;
		for (short i = 0; i < lenth&&rc; i++)
		{
			fst.position++; 
			rc = step(fst, rstat);
		}
		delete[] rstat;
		return (rc ? (fst.rstates[fst.n_stat - 1] == lenth) : rc);
	}
}