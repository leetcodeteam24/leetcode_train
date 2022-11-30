#pragma once
#include <map>
#include <memory>
#include <iostream>

static void code_auto_register_function_();
#define CODE_CAT_IMPL(a, b) a##b
#define CODE_CAT(a, b) CODE_CAT_IMPL(a, b)

#define CODEMANAGER_REGISTERATION \
namespace{\
struct code_auto_register__ { \
	code_auto_register__() { \
		code_auto_register_function_(); \
	}\
};\
}\
static const code_auto_register__ CODE_CAT(auto_register__, __LINE__);\
static void code_auto_register_function_()



class SolutionBase
{
public:
	SolutionBase() {}
	~SolutionBase() {}


	virtual void displayQus() = 0;
	virtual void solute() = 0;
};

class CodeSolutionManager
{
public:
	static CodeSolutionManager& Instance()
	{
		static CodeSolutionManager ins;
		return ins;
	}
	void RegisterSolution(const std::string& key, std::shared_ptr<SolutionBase> solution) {
		m_solutions[key] = solution;
	}

	void Exec(const std::string& key) {
		m_solutions[key]->displayQus();
		m_solutions[key]->solute();
	}

private:
	std::map<std::string, std::shared_ptr<SolutionBase>> m_solutions;

};


#define REGISTER_SOLUTION(codeid) CodeSolutionManager::Instance().RegisterSolution(#codeid, std::make_shared<Solution_##codeid>());

#define DECLARE_SOLUTION_IMPL(codeid) class Solution_##codeid : public SolutionBase\
{\
public:\
	void displayQus() override; \
	void solute() override; \
};




#define DECLARE_SOLUTION(codeid) DECLARE_SOLUTION_IMPL(codeid)\
static void register_solutions_##codeid()\
{\
	REGISTER_SOLUTION(codeid)\
};\
CODEMANAGER_REGISTERATION\
{\
	register_solutions_##codeid();\
}


