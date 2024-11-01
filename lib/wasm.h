#pragma once

#include <json/json.h>
#include <string>

const std::string getComponentStr(const std::string& componentName);
const Json::Value buildWasmInput(const std::string& markup, const std::vector<std::string> components, const Json::Value& initialState);
const std::string callWasm(Json::Value& input);
