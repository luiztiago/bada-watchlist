/*
 * DatabaseItems.cpp
 *
 *  Created on: Apr 8, 2012
 *      Author: Administrator
 */

#include "DatabaseItems.h"

using namespace Osp::Base;
using namespace Osp::App;
using namespace Osp::System;

DatabaseItem::DatabaseItem (String description)
{
	 __description = description;
}

DatabaseItem::~DatabaseItem()
{

}

void DatabaseItem::SetIndex(int index)
{
	__index = index;
}

String DatabaseItem::GetDescription()
{
	return __description;
}

void DatabaseItem::SetDate(DateTime currentDate)
{
	__date = currentDate;
}

DateTime DatabaseItem::GetDate()
{
	return __date;
}

int DatabaseItem::GetIndex()
{
	return __index;
}

void DatabaseItem::SetDescription(String theDescription)
{
	__description = theDescription;
}
