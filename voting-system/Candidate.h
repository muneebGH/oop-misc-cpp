#include"CString.h"

class Candidate
{private:
	CString name;
	CString elecSymbol;
	int votes;
public:
	Candidate();
	Candidate(const CString nam,const CString elctionSymbol);
	CString getName() const;
	void setName(const CString nam);
	CString getElecSymbol() const;
	void setElectSymbol(const CString nam);
	int getVotes()const;
	void castVote();
};