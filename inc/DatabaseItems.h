/*
 * DatabaseItems.h
 *
 *  Created on: Apr 8, 2012
 *      Author: Administrator
 */

#include <FBase.h>
#include <FUi.h>
#include <FApp.h>
#include <FIo.h>

#ifndef DatabaseItem_H_
#define DatabaseItem_H_

class DatabaseItem: public Osp::Base::Object {

public:

	Osp::Base::String 	__description;
	int               	__index;
	Osp::Base::DateTime __date;

	DatabaseItem(Osp::Base::String description);
	~DatabaseItem();
	void SetIndex(int index);
	int GetIndex();

	Osp::Base::String GetDescription();
	void SetDate(Osp::Base::DateTime currentDate);
	Osp::Base::DateTime GetDate();
	void SetDescription(Osp::Base::String theDescription);

};


#endif /* DatabaseItem_H_ */
