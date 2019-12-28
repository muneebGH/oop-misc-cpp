#include"Candidate.h"
Candidate::Candidate()
{
	votes = 0;
}

Candidate::Candidate(const CString nam, const CString electionSymbol) :name(nam), elecSymbol(electionSymbol)
{
	votes = 0;
}

CString Candidate::getName() const
{
	return name;
}

void Candidate::setName(const CString nam)
{
	name.copy(nam);
}

CString Candidate::getElecSymbol()const
{
	return elecSymbol;

}

void Candidate::setElectSymbol(const CString nam)
{
	elecSymbol.copy(nam);
}

int Candidate::getVotes()const
{
	return votes;
}

void Candidate::castVote()
{
	votes = votes + 1;
}

