/*
 * Copyright (c) 2014 Ember
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include "Exception.h"
#include "Field.h"
#include "Definition.h"
#include <rapidxml.hpp>
#include <string>
#include <vector>
#include <map>

namespace ember { namespace dbc {

class Parser {
	struct ProgressCheck {
		bool type;
		bool name;
		bool key;
		bool options;
	};

	Definition do_parse(const std::string& path);
	Field parse_field(const std::string& dbc_name, rapidxml::xml_node<>* field);
	void parse_field_property(Field& field, ProgressCheck& check,
	                          rapidxml::xml_node<>* property);
	void parse_field_key(Key& key, rapidxml::xml_node<>* property);
	void parse_field_options(std::vector<std::pair<std::string, std::string>>& key,
	                         rapidxml::xml_node<>* property);

public:
	Definition parse(const std::string& path);
	std::vector<Definition> parse(const std::vector<std::string>& paths);
};

}} //dbc, ember