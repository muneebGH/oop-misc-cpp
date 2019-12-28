#include"VotingMachine.h"
VotingMachine::VotingMachine(const Candidate * p, const int n)
{
	if (n == 0)
	{
		exit(0);
	}
	numOfCandidates = n;
	candidateList = new Candidate[numOfCandidates];
	for (int i = 0; i < n; i = i + 1)
	{
		candidateList[i].setName(p[i].getName());
		candidateList[i].setName(p[i].getName());
	}
}

void VotingMachine::castVote(const CString & str)
{
	int candidateNumber = getCandidateNumber(str);
	if (candidateNumber == -1)
	{
		return;
	}

	candidateList[candidateNumber].castVote();

}


int VotingMachine::getCandidateNumber(const CString & str)const
{
	int result;
	for (int i = 0; i < numOfCandidates; i = i + 1)
	{
		result = str.comapre(candidateList[i].getElecSymbol());
		if (result == 0)
		{
			return i;
		}
	}

	return -1;
}


int VotingMachine::candidateReport(const CString & str)const
{
	int candidateNumber = getCandidateNumber(str);

	if (candidateNumber == -1)
	{
		return -1;
	}
	

	return candidateList[candidateNumber].getVotes();
}


Candidate * VotingMachine::electionResult()const
{
	Candidate * p;
	p = new Candidate[3];


	//winner 
	int max = candidateList[0].getVotes();
	int winner = 0;
	for (int i = 1; i < numOfCandidates; i = i + 1)
	{
		if (candidateList[i].getVotes() > max)
		{
			winner = i;
			max = candidateList[i].getVotes();
		}
	}

	p[0].setName(candidateList[winner].getName());
	p[0].setElectSymbol(candidateList[winner].getElecSymbol());



	//runner up

	int runnerUp;
	if (candidateList[0].getVotes() == max)
	{
		runnerUp = candidateList[1].getVotes();
	}
	else
	{
		runnerUp = candidateList[0].getVotes();
	}

	for (int i = 0; i < numOfCandidates; i = i + 1)
	{
		if (candidateList[i].getVotes() > runnerUp && candidateList[i].getVotes()!=max)
		{
			winner = i;
			runnerUp = candidateList[i].getVotes();
		}
	}

	p[1].setName(candidateList[winner].getName());
	p[1].setElectSymbol(candidateList[winner].getElecSymbol());

	//3rd number


	int third;
	for (int i = 0; i < numOfCandidates; i = i + 1)
	{
		if (candidateList[i].getVotes() != max && candidateList[i].getVotes() != runnerUp)
		{
			third = candidateList[i].getVotes();
			i = numOfCandidates;
		}
	}



	for (int i = 0; i < numOfCandidates; i = i + 1)
	{
		if (candidateList[i].getVotes() > third && (candidateList[i].getVotes() != max && candidateList[i].getVotes()!=runnerUp))
		{
			winner = i;
			runnerUp = candidateList[i].getVotes();
		}
	}

	p[2].setName(candidateList[winner].getName());
	p[2].setElectSymbol(candidateList[winner].getElecSymbol());


	return p;
}