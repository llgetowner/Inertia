#include "llfloater.h"
#include "lltemplatemessagereader.h"

class LLFloaterMessageRewriter : public LLFloater
{
public:
	LLFloaterMessageRewriter();
	~LLFloaterMessageRewriter();
	static void show();
	BOOL postBuild();
	static LLFloaterMessageRewriter* sInstance;
	static void onClickSaveRules(void* user_data);
	static void onClickNewRule(void* user_data);
	void refreshRuleList();
};
