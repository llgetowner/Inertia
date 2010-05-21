#include "llviewerprecompiledheaders.h"
#include "llfloatermessagelog.h"
#include "lluictrlfactory.h"
#include "llscrolllistctrl.h"
#include "lltexteditor.h"
#include "llviewerwindow.h" // alertXml
#include "llmessagetemplate.h"
#include <boost/tokenizer.hpp>
#include "llmenugl.h"

LLFloaterMessageLog* LLFloaterMessageLog::sInstance;

LLFloaterMessageLog::LLFloaterMessageLog()
:	LLFloater()
{
	sInstance = this;
	LLUICtrlFactory::getInstance()->buildFloater(this, "floater_message_rewriter.xml");
}
LLFloaterMessageLog::~LLFloaterMessageLog()
{
	
	sInstance = NULL;
}
// static
void LLFloaterMessageLog::show()
{
	if(!sInstance) sInstance = new LLFloaterMessageLog();
	sInstance->open();
}
BOOL LLFloaterMessageLog::postBuild()
{
	childSetAction("save_rules", onClickSaveRules, this);
	childSetAction("new_rule", onClickNewRule, this);
	refreshRuleList();
	refreshNetInfo(TRUE);
	return TRUE;
}

void LLFloaterMessageLog::refreshRuleList()
{
	LLScrollListCtrl* scrollp = getChild<LLScrollListCtrl>("rule_list");
	
	// Rebuild scroll list from scratch
	LLUUID selected_id = scrollp->getFirstSelected() ? scrollp->getFirstSelected()->getUUID() : LLUUID::null;
	S32 scroll_pos = scrollp->getScrollPos();
	scrollp->clearRows();
	
	LLSD element;
	element["id"] = 9999;

	LLSD& icon_column = element["columns"][0];
	icon_column["column"] = "icon_enabled";
	icon_column["type"] = "icon";
	icon_column["value"] = "";
	
	LLSD& rule_column = element["columns"][1];
	rule_column["column"] = "RuleName";
	rule_column["value"] = "A Cool Rule #1";
	
	LLSD& direction_column = element["columns"][2];
	rule_column["column"] = "direction";
	rule_column["value"] = "Out";
		
	LLScrollListItem* scroll_itemp = scrollp->addElement(element);
	BOOL rule_enabled = true;
	
	if(rule_enabled)
	{
		LLScrollListIcon* icon = (LLScrollListIcon*)scroll_itemp->getColumn(0);
		icon->setValue("account_id_green.tga");
		icon->setClickCallback(NULL, NULL);
	}
	else
	{
		LLScrollListIcon* icon = (LLScrollListIcon*)scroll_itemp->getColumn(0);
		icon->setValue("account_id_green.tga");
		icon->setClickCallback(NULL, NULL);
	}
	
	if(selected_id.notNull()) scrollp->selectByID(selected_id);
	if(scroll_pos < scrollp->getItemCount()) scrollp->setScrollPos(scroll_pos);
}
// static
void LLFloaterMessageLog::onClickSaveRules(void* user_data)
{
	return;
}
//static
void LLFloaterMessageLog::onClickNewRule(void* user_data)
{
	return;
}
// </edit>
