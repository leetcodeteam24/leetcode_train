#pragma once
#include <map>
#include <memory>

enum CodeId {
	S001,
	S002,
	S003,
	S004,
	S005,

	Count
};

class SolutionBase
{
public:
	SolutionBase() {}
	~SolutionBase() {}


	virtual void displayQus() = 0;
	virtual void solute() = 0;
};

class LeetCode 
{
public:
	LeetCode() {}
	~LeetCode() {}

	void RegisterSolution(CodeId id, std::shared_ptr<SolutionBase> solution) {
		m_solutions[id] = solution;
	}

	void Exec(CodeId id) {
		m_solutions[id]->displayQus();
		m_solutions[id]->solute();
	}
private:
	std::map<CodeId, std::shared_ptr<SolutionBase>> m_solutions;
};

#define REGISTER_SOLUTION(code_exe, codeid) code_exe->RegisterSolution(codeid, std::make_shared<Solution_##codeid>());

#define DECLARE_SOLUTION(codeid) class Solution_##codeid : public SolutionBase\
{\
public:\
	void displayQus() override; \
	void solute() override; \
	CodeId Id = codeid;\
};





#define DECLARE_IMPL(codeid) DECLARE_SOLUTION(codeid)\
static void register_solutions_##codeid(LeetCode* code_exe)\
{\
	REGISTER_SOLUTION(code_exe, codeid)\
};\


DECLARE_IMPL(S001)
DECLARE_IMPL(S002)
DECLARE_IMPL(S003)
DECLARE_IMPL(S004)
DECLARE_IMPL(S005)


static void register_solutions(LeetCode* code_exe)
{
	register_solutions_S001(code_exe);
	register_solutions_S002(code_exe);
	register_solutions_S003(code_exe);
	register_solutions_S004(code_exe);
	register_solutions_S005(code_exe);
}




