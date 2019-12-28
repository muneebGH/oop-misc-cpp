#include"Candidate.h"
class VotingMachine
{
private:
	int numOfCandidates;
	Candidate * candidateList;
public:
	VotingMachine(const Candidate * p, const int n);
	void castVote(const CString &);
	int candidateReport(const CString &)const;
	Candidate * electionResult()const;
	int getCandidateNumber(const CString & str)const;
};