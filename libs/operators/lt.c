/*
	Copyright (C) 2013 - 2014 CurlyMo

	This file is part of pilight.

	pilight is free software: you can redistribute it and/or modify it under the
	terms of the GNU General Public License as published by the Free Software
	Foundation, either version 3 of the License, or (at your option) any later
	version.

	pilight is distributed in the hope that it will be useful, but WITHOUT ANY
	WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
	A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with pilight. If not, see	<http://www.gnu.org/licenses/>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "operator.h"
#include "lt.h"
#include "dso.h"

static void operatorLtCallback(double a, double b, char **ret) {
	if(a < b) {
		strcpy(*ret, "1");
	} else {
		strcpy(*ret, "0");
	}
}

#ifndef MODULE
__attribute__((weak))
#endif
void operatorLtInit(void) {
	event_operator_register(&operator_lt, "<");
	operator_lt->callback_number = &operatorLtCallback;
}


#ifdef MODULE
void compatibility(struct module_t *module) {
	module->name = "<";
	module->version = "1.0";
	module->reqversion = "5.0";
	module->reqcommit = "87";
}

void init(void) {
	operatorLtInit();
}
#endif
