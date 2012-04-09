#ifndef _FORM1_H_
#define _FORM1_H_

#include <FBase.h>
#include <FApp.h>
#include <FIo.h>
#include <FUi.h>
#include "DatabaseForm.h"
#include "DatabaseItems.h"

class Form1 :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener,
 	public Osp::Ui::ITextBlockEventListener,
 	public Osp::Ui::IKeyEventListener,
 	public Osp::Ui::Controls::IListViewItemProvider,
	public Osp::Ui::Controls::IScrollEventListener,
	public Osp::Ui::Controls::IListViewItemEventListener
{

// Construction
public:
	Form1(void);
	virtual ~Form1(void);
	bool Initialize(void);

// Implementation
protected:
	static const int ID_BUTTON_1 = 101;
	static const int ID_BUTTON_2 = 102;
	static const int ID_PANEL_1 = 1;
	static const int ID_PANEL_2 = 2;

	Osp::Ui::Controls::Button *__pButtonOk;
	Osp::Ui::Controls::Button *__pButtonOk2;
	Osp::Ui::Controls::EditField *__pEditField;
	Osp::Ui::Controls::ListView *__pList;

	Osp::Base::String __databaseName;
	DatabaseForm* dbForm;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

	virtual void OnTextBlockSelected(Osp::Ui::Control &source, int start, int end);

	virtual void OnKeyLongPressed(const Osp::Ui::Control &source, Osp::Ui::KeyCode keyCode);
	virtual void OnKeyPressed(const Osp::Ui::Control &source, Osp::Ui::KeyCode keyCode);
	virtual void OnKeyReleased(const Osp::Ui::Control &source, Osp::Ui::KeyCode keyCode);

	/* IListViewItemProvider methods */
	virtual Osp::Ui::Controls::ListItemBase * CreateItem(int index,
	                                                     int itemWidth);

	virtual bool DeleteItem(int index,
	                        Osp::Ui::Controls::ListItemBase *pItem,
	                        int itemWidth);

	virtual int GetItemCount(void);

	/* IScrollEventListener methods */
	virtual void OnScrollEndReached
	                 (Osp::Ui::Control &source,
	                  Osp::Ui::Controls::ScrollEndEvent type);

	/* IListViewItemEventListener methods */
	virtual void OnListViewContextItemStateChanged
	                 (Osp::Ui::Controls::ListView &listView,
	                  int index,
	                  int elementId,
	                  Osp::Ui::Controls::ListContextItemStatus status);

	virtual void OnListViewItemStateChanged
	                 (Osp::Ui::Controls::ListView &listView,
	                  int index,
	                  int elementId,
	                  Osp::Ui::Controls::ListItemStatus status);

	virtual void OnListViewItemSwept
	                 (Osp::Ui::Controls::ListView &listView,
	                  int index,
	                  Osp::Ui::Controls::SweepDirection direction);

	virtual void OnListViewItemLongPressed
	                 (Osp::Ui::Controls::ListView &listView,
	                  int index,
	                  int elementId,
	                  bool &invokeListViewItemCallback);


};

#endif	//_FORM1_H_
