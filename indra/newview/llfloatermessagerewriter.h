#include "llfloater.h"
#include "llmessagelog.h"
#include "lltemplatemessagereader.h"

class LLFloaterMessageLog : public LLFloater
{
public:
	LLFloaterMessageLog();
	~LLFloaterMessageLog();
	static void show();
	BOOL postBuild();
	static LLFloaterMessageLog* sInstance;
	static void onClickSaveRules(void* user_data);
	static void onClickNewRule(void* user_data);
	void refreshRuleList();
};
