/*
 * DatabaseForm.h
 *
 *  Created on: Apr 8, 2012
 *      Author: Administrator
 */

#ifndef DATABASEFORM_H_
#define DATABASEFORM_H_

#include <FBase.h>
#include <FUi.h>
#include <FIo.h>
#include <FLocales.h>
#include "DatabaseItems.h"

class DatabaseForm :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener,
	public Osp::Ui::IItemEventListener

{

// Construction
public:
	DatabaseForm();
	virtual ~DatabaseForm();
	bool Initialize(void);

protected:
	Osp::Base::String 					__databaseName;

public:
	virtual result OnInitializing(void);

	bool CreateDatabase();
	bool AddItemToDatabase(DatabaseItem* pNewItem);
	void AddItemToList (DatabaseItem* pCurrentItem);
	void ReadItemsFromDatabase();
};

#endif /* DATABASEFORM_H_ */
