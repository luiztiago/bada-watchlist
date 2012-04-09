/*
 * DatabaseForm.cpp
 *
 *  Created on: Apr 8, 2012
 *      Author: Administrator
 */

#include "DatabaseForm.h"

using namespace Osp::Base;
using namespace Osp::App;
using namespace Osp::Base::Collection;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Io;
using namespace Osp::Locales;
using namespace Osp::System;

DatabaseForm::DatabaseForm() {
	// TODO Auto-generated constructor stub

}

DatabaseForm::~DatabaseForm() {
	// TODO Auto-generated destructor stub
}

bool
DatabaseForm::Initialize()
{
	// Construct an XML form
	//Construct(L"IDF_MAINForm1");
	//__pItemsArray = new ArrayList();
	__databaseName = L"/Home/testingDatabase";

	return true;
}

result
DatabaseForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	return r;
}

bool DatabaseForm::CreateDatabase(){

	Database pDatabase;
	String sql;
	String sql2;
	String statement;

	result r = E_SUCCESS;

	// create the database if it doesn't exist
	r = pDatabase.Construct(__databaseName, true);
	if (IsFailed(r)) return false;


	//pDatabase = new Database();
	//if (pDatabase == null) return false;
	//r = pDatabase->Construct(pDatabaseName,true);
	//if (IsFailed(r)) return false;

	// Create the main table
	sql.Append(L"CREATE TABLE IF NOT EXISTS movies (id INTEGER PRIMARY KEY AUTOINCREMENT, description TEXT)");
	r = pDatabase.ExecuteSql(sql, true);

	if (IsFailed(r)) return false;

	return true;
}

bool DatabaseForm::AddItemToDatabase(DatabaseItem* newItem)
{

	String        notesString(L"very empty");
	Database      pDatabase;
	DbStatement*  pStmt;
	DbEnumerator* pEnum;
	String        statement;
	result        r = E_SUCCESS;

	pDatabase.BeginTransaction();

	// Prepare the INSERT statement
	statement.Append(L"INSERT INTO movies(description) VALUES (?, ?)");
	pStmt = pDatabase.CreateStatementN(statement);

   // Bind the values from the current entry into this statement
	pStmt->BindString(0, newItem->__description);

	// Now execute the statement with our values included
	pEnum = pDatabase.ExecuteStatementN(*pStmt);
	pDatabase.CommitTransaction();

	delete pEnum;
	delete pStmt;
	return true;
}

void DatabaseForm::AddItemToList (DatabaseItem* pCurrentItem)

{
	//ring myString = currentItem->mAmount.ToString();
	/*__pList->AddItem(&(pCurrentItem->__description), null, null, null);

	__pList->SetColumn1Width (330);
	__pList->SetColumn2Width (250);
	__pList->SetRow1Height (40);
	__pList->SetRow2Height (40);


	 Draw();
	 Show();
*/

}

void DatabaseForm::ReadItemsFromDatabase()
{
	Database pDatabase;
	DbEnumerator* pEnum;
  	String sql;
	String statement;

	result r = E_SUCCESS;

	r = pDatabase.Construct(__databaseName, false);

	sql.Append(L"select id, description from movies");
	pEnum = pDatabase.QueryN(sql);
	String description;
	int	   id;

   while( pEnum->MoveNext()== E_SUCCESS )
	{
		pEnum->GetIntAt(0, id);
		pEnum->GetStringAt(1, description);

		// Store the item in our data structure
		DatabaseItem* newItem = new DatabaseItem(description);
		newItem->SetIndex(id);
		// Display the item in our user interface using our own method
		AddItemToList(newItem);
		}
	if (pEnum != null)
		delete pEnum;
}
