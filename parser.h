#include <FlexLexer.h>
#include <map>
#include <string>

class Parser
{
private:
	yyFlexLexer scanner;
	int lookahead;

	std::map<std::string, int> tokenCount;
	
public:
	Parser();
	void Start();
};
