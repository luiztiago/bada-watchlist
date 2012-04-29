#include "Form1.h"
#include "DatabaseForm.h"
#include "DatabaseItems.h"
#include "Movie.h"

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::Base::Collection;
using namespace Osp::Io;
using namespace Osp::Graphics;
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

	ScrollPanel1_ = static_cast<ScrollPanel*>(this->GetControl("IDC_PANEL1"));
	ScrollPanel2_ = static_cast<ScrollPanel*>(this->GetControl("IDC_PANEL2"));
	ScrollPanel2_->SetShowState(false);

	__pList = static_cast<ListView*>(ScrollPanel1_->GetControl(L"IDC_LISTVIEW1"));
	if (__pList)
	{
		AppLog("Tem lista :) \n");
		//__pList->Construct(GetClientAreaBounds(), true, true);
		__pList->SetItemProvider(*this);
		__pList->AddListViewItemEventListener(*this);
		//AddControl(*__pList);
	}

	// TODO: Add your initialization code here
	__pItems = new ArrayList();
	__pItems->Construct();
	//__pItems->Add(*(new String("Teste")));
	//__pList->RefreshList(__pList->GetItemCount(), LIST_REFRESH_TYPE_ITEM_ADD);
	//__pItems->Add(*(new Integer(1)));
	//__pItems->Add(*(new Integer(2)));

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

	__pEditField = static_cast<EditField*>(ScrollPanel2_->GetControl(L"IDC_EDITFIELD1"));
	if (__pEditField)
	{
		AppLog("Tem editfield :) \n");
		//__pEditField->AddKeyEventListener(*this);
		//__pList->AddItemEventListener(*this);
		//pList->Hide();
	}

	Button *pButton1 = static_cast<Button *>(ScrollPanel2_->GetControl("IDC_BUTTON1"));
	AppLog("Button 1 \n");
	if (pButton1)
	{
		AppLog("Button 1 existe \n");
		pButton1->SetActionId(ID_BUTTON_1);
		pButton1->AddActionEventListener(*this);
	}

	AppLog("Quantidade %d", __pList->GetItemCount());

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
			String texto = __pEditField->GetText();
			if(texto != null) {
				//SimpleItem * pItem = new SimpleItem();
				//pItem->SetElement(texto);
				__pItems->Add(texto);
				//__pList->CreateItem(0, texto);
				//__pList->UpdateList();
				__pList->RefreshList(__pList->GetItemCount(), LIST_REFRESH_TYPE_ITEM_ADD);
				//__pList->RefreshList(__pList->GetItemCount()-1, LIST_REFRESH_TYPE_ITEM_REMOVE);
				ScrollPanel1_->SetShowState(true);
				ScrollPanel2_->SetShowState(false);
				this->RequestRedraw(true);
			}
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

int Form1::GetItemCount(void) {
    return __pItems->GetCount();
}

Osp::Ui::Controls::ListItemBase * Form1::CreateItem(int index,
                                                    int itemWidth) {
    AppLog("CreateItem()");

    AppLog("Quantidade %d", __pList->GetItemCount());

    Osp::Base::String* text = null;
    String texto;
    text = (Osp::Base::String*)__pItems->GetAt(index);
    texto.Format(100, L"Filme: %d", text);
    // tentei com cast, usando %s, %ls, %S e nenhum deles retornava a string correta

    SimpleItem * pItem = new SimpleItem();
    pItem->Construct(Dimension(itemWidth, 100), LIST_ANNEX_STYLE_DETAILED);
    pItem->SetElement(texto, null);
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

void
Form1::OnTouchDoublePressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Form1::OnTouchFocusIn(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Form1::OnTouchFocusOut(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Form1::OnTouchLongPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Form1::OnTouchMoved(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Form1::OnTouchPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Form1::OnTouchReleased(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}
