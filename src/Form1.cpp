#include "Form1.h"
#include "DatabaseForm.h"
#include "DatabaseItems.h"

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::Io;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

Osp::Ui::Controls::ScrollPanel *ScrollPanel1_;
Osp::Ui::Controls::ScrollPanel *ScrollPanel2_;

Form1::Form1(void)
{

}

Form1::~Form1(void)
{
}

bool
Form1::Initialize()
{
	// Construct an XML form
	Construct(L"IDF_FORM1");
	__databaseName = L"/Home/testingDatabase";
	return true;
}

result
Form1::OnInitializing(void)
{
	result r = E_SUCCESS;

		// TODO: Add your initialization code here

	// Get a button via resource ID
	__pButtonOk = static_cast<Button *>(GetControl(L"IDC_BUTTON1"));
	AppLog("Button 1 \n");
	if (__pButtonOk != null)
	{
		AppLog("Button 1 existe \n");
		__pButtonOk->SetActionId(ID_BUTTON_1);
		__pButtonOk->AddActionEventListener(*this);
	}

	__pButtonOk2 = static_cast<Button *>(GetControl(L"IDC_BUTTON2"));
	AppLog("Button 2 \n");
		if (__pButtonOk2 != null)
		{
			AppLog("Button 2 existe \n");
			__pButtonOk2->SetActionId(ID_BUTTON_2);
			__pButtonOk2->AddActionEventListener(*this);
		}

	ScrollPanel1_ = static_cast<ScrollPanel*>(this->GetControl("IDC_PANEL1"));
	ScrollPanel2_ = static_cast<ScrollPanel*>(this->GetControl("IDC_PANEL2"));
	ScrollPanel2_->SetShowState(false);

	//Tab* pTab = GetTab();
	//if (pTab)
	//{
	//	AppLog("Tem tab :) \n");
	//	pTab->AddItem(L"Fiirst", ID_PANEL_1);
	//	pTab->AddItem(L"Seecond", ID_PANEL_2);
	//	pTab->AddActionEventListener(*this);
	//}

    TabBar *pTabbar1 = static_cast<TabBar *>(GetControl("IDC_TABBAR1"));
	if (pTabbar1)
	{
		AppLog("Tem tab :) \n");

		TabBarItem tabBarItem1;
		TabBarItem tabBarItem2;

		tabBarItem1.Construct("Lista",ID_PANEL_1);
		tabBarItem2.Construct("Novo",ID_PANEL_2);

		pTabbar1->RemoveAllItems();
		pTabbar1->AddItem(tabBarItem1);
		pTabbar1->AddItem(tabBarItem2);
		pTabbar1->AddActionEventListener(*this);
	}

	__pList = static_cast<ListView*>(GetControl(L"IDC_LISTVIEW1"));
	if (__pList != null)
	{
		__pList->SetItemProvider(*this);
		__pList->AddListViewItemEventListener(*this);
		__pList->AddScrollEventListener(*this);
	}

	__pEditField = static_cast<EditField*>(GetControl(L"IDC_EDITFIELD1"));
	if (__pEditField != null)
	{
		__pEditField->AddKeyEventListener(*this);
		//__pList->AddItemEventListener(*this);
		//pList->Hide();
	}

	return r;

}

result
Form1::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void
Form1::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	AppLog("####### OnActionPerformed called with ActionId(%d)! #######", actionId);
	switch(actionId)
	{
	case ID_BUTTON_1:
		{
			AppLog("Button 1 is clicked! \n");
		}
		break;
	case ID_BUTTON_2:
		{
			String texto = __pEditField->GetText();
			if(texto != null) {
				//AppLog("Button 2 is clicked! Valor: (%ls) \n", texto);
			}
			AppLog("Button 2 is clicked!");
		}
		break;
	case ID_PANEL_1:
		{
			AppLog("Show first panel \n");
			ScrollPanel2_->SetShowState(false);
			ScrollPanel1_->SetShowState(true);
			this->RequestRedraw(true);
		}
		break;
	case ID_PANEL_2:
		{
			AppLog("Show second panel \n");
			ScrollPanel2_->SetShowState(true);
			ScrollPanel1_->SetShowState(false);
			this->RequestRedraw(true);
		}
		break;
	default:
		break;
	}
}



void
Form1::OnTextBlockSelected(Osp::Ui::Control &source, int start, int end)
{
	// TODO: Add your implementation codes here

}

void
Form1::OnKeyLongPressed(const Osp::Ui::Control &source, Osp::Ui::KeyCode keyCode)
{
	// TODO: Add your implementation codes here

}

void
Form1::OnKeyPressed(const Osp::Ui::Control &source, Osp::Ui::KeyCode keyCode)
{
	// TODO: Add your implementation codes here

}

void
Form1::OnKeyReleased(const Osp::Ui::Control &source, Osp::Ui::KeyCode keyCode)
{
	// TODO: Add your implementation codes here

}

int Form1::GetItemCount(void) {
    return 0;
}

Osp::Ui::Controls::ListItemBase * Form1::CreateItem(int index,
                                                    int itemWidth) {
    AppLog("CreateItem()");

    String text;
    text.Format(100, L"SimpleItem #%d", index);

    SimpleItem * pItem = new SimpleItem();
    pItem->SetElement(text);
    return pItem;

}

bool Form1::DeleteItem(int index,
                       Osp::Ui::Controls::ListItemBase *pItem,
                       int itemWidth) {
    AppLog("DeleteItem()");
    /* pItem not deallocated in this method */
    return false;
}

void Form1::OnScrollEndReached(Osp::Ui::Control &source,
                               Osp::Ui::Controls::ScrollEndEvent type) {

    AppLog("OnScrollEndReached()");
}

void Form1::OnListViewContextItemStateChanged
             (Osp::Ui::Controls::ListView &listView,
              int index, int elementId,
              Osp::Ui::Controls::ListContextItemStatus status) {
    AppLog("OnListViewContextItemStateChanged()");
}

void Form1::OnListViewItemStateChanged
             (Osp::Ui::Controls::ListView &listView,
              int index, int elementId,
              Osp::Ui::Controls::ListItemStatus status) {
    AppLog("OnListViewItemStateChanged()");

}

void Form1::OnListViewItemSwept
             (Osp::Ui::Controls::ListView &listView,
              int index,
              Osp::Ui::Controls::SweepDirection direction) {
    AppLog("OnListViewItemSwept()");
}

void Form1:: OnListViewItemLongPressed
             (Osp::Ui::Controls::ListView &listView,
              int index,
              int elementId,
              bool &invokeListViewItemCallback) {
    AppLog("OnListViewItemLongPressed()");
}
