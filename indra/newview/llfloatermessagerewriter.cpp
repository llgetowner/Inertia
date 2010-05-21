#include "llviewerprecompiledheaders.h"
#include "llfloatermessagerewriter.h"
#include "lluictrlfactory.h"
#include "llscrolllistctrl.h"
#include "lltexteditor.h"
#include "llviewerwindow.h" // alertXml
#include "llmessagetemplate.h"
#include "llmessageconfig.h"
#include <boost/tokenizer.hpp>
#include "llmenugl.h"

LLFloaterMessageRewriter* LLFloaterMessageRewriter::sInstance;

LLFloaterMessageRewriter::LLFloaterMessageRewriter()
:	LLFloater()
{
	sInstance = this;
	LLUICtrlFactory::getInstance()->buildFloater(this, "floater_message_rewriter.xml");
}
LLFloaterMessageRewriter::~LLFloaterMessageRewriter()
{
	
	sInstance = NULL;
}
// static
void LLFloaterMessageRewriter::show()
{
	if(!sInstance) sInstance = new LLFloaterMessageRewriter();
	sInstance->open();
}
BOOL LLFloaterMessageRewriter::postBuild()
{
	childSetAction("save_rules", onClickSaveRules, this);
	childSetAction("new_rule", onClickNewRule, this);
	refreshRuleList();
	return TRUE;
}

void LLFloaterMessageRewriter::refreshRuleList()
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
	direction_column["column"] = "direction";
	direction_column["value"] = "Out";
		
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
	
	//LLSD& messages = LLMessageConfigFile::instance().mMessages;
}
// static
void LLFloaterMessageRewriter::onClickSaveRules(void* user_data)
{
	return;
}
//static
void LLFloaterMessageRewriter::onClickNewRule(void* user_data)
{
	return;
}
// </edit>
